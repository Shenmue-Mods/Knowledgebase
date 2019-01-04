/* $Id: seqconv.c,v 1.34 1998/09/30 09:47:24 hyamada Exp hyamada $ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqdata.h"

/*#define TIME_CHECK*/

#ifdef USER_takanao
#undef USER_takanao
#endif
/*#define USER_takanao /* デバッグシンボル */

/* 
 *	構造体
 */
typedef	struct	{
    int 	id;	/* 'TRCK' */
    int 	size;
    char	endian;	/* 0:little, 1:big */
    char	version;
    char	xxx1;
    char	xxx2;
    int 	nframes;
} SEQHEADER;

typedef	struct	{
    char	type;
    char	argc;
    short	xxxx;
    int 	args[1];
} SEQ;

enum	{
    /* シーケンスコマンド */
    stEND = 0,
    stCAMERA,
    stMOVE,
    stMOTION,
    stEFFECT,
    stVOICE,
    stSE,

    /* バッファサイズ */
    SEQBSIZE = 128*1024,
    CAMBSIZE = 256*1024,
    MOVBSIZE = 512*1024,
    MAXTBL  = 128,
    MAXSTR  = 1024,
    MAXCLIP = 1024,

    /* ダミーのID */
    ID_CAMERA = MAKE_ID('(','^','^',';'),
};

typedef	struct	{		/* 作業領域の割り当て */
    char	track[8];
    char	seq[SEQBSIZE];
    char	cam[CAMBSIZE];
    char	mov[MOVBSIZE];
    char	*camtbl[MAXTBL];
    char	*movtbl[MAXTBL];
    char	*strtbl[MAXSTR];
    short	*cliptbl[MAXCLIP];
} WORK;

/* 
 *	プロトタイプ
 */
static	int	MakeCamOnly();
static	int	MakeData();
static 	void 	TransSplData();
static	int	*ReqCamera(int *, int);
static	int	*ReqMove(int *, int);
static	int	*ReqMotion(int *, int);
static	int	*ReqEffect(int *, int);
static	int	*ReqVoice(int *, int);
static	int	*ReqSE(int *, int);
static	int	WriteFile();

static	void	CreateCamData(void );
static	void	CreateMovData(void );
static	void	*CreateSplData(int *, void *, int );
static	int 	fwrites(char *fname, void *buff, int size);

extern	void	SetEndian(int big);
extern	int	endian(void );
extern	int 	GetInt16(void *);
extern	int 	GetInt32(void *);
extern	void	SetInt16(void *, int);
extern	void	SetInt32(void *, int);

extern	float 	GetAiffTime(char *fname);

/*
 *	グローバル変数
 */
extern	Uint32	Scene[];
extern	Uint32	MoveID[];
extern	Uint32	EffectID[];
extern	Uint32	MotionID[];
extern	Uint32	VoiceID[];
extern	Uint32	SoundEffectID[];
extern	ObjMove	MoveAll[];
extern	Camera	CamAll[];
extern	char	*VoiceName[];
extern	char	*SoundEffectName[];
extern	float	PlayOffs[3];
extern	float	PlayRot[3];
float	*xxx = PlayRot;		/* 使ってないけどエラーを起こさせるため */
extern	char	_fdata[];
extern	char	_fbss[];

static	char	usage[] = {
    "seqconv 1.34\n"
    "\n"
    "usage : seqconv [-o outfile]\n"
    "        seqconv -c camno [-o outfile]\n"
};
static	char	*outfn = "seqdata.bin";
static	int	camno;			/* camera number */
static	char	camout;			/* -c option */
static	char	aifftime;		/* -a option */
static	char	verbose;		/* -v option */
static	char	viderr;			/* voice ID error */

static	WORK	*work;
static	char	*workbuff, *workdatap;
static	char	*camdata, *movdata;
static	int	ncam, nmov, nstr, nclip, nv, nse;

static	int	*scMove   = (int *)MoveID;
static	int	*scMotion = (int *)MotionID;
static	int	*scEffect = (int *)EffectID;
static	int	*scVoice  = (int *)VoiceID;
static	int	*scSE     = (int *)SoundEffectID;

/*
 *	main
 */

int main(int argc, char *argv[])
{
    /* オプションチェック */
    argv++;
    for ( ; argv[0] && argv[0][0] == '-'; argv++ ){	/* options */
	switch ( argv[0][1] ){
	case 'l':
	    break;
	case 'o':
	    argv++;
	    outfn = argv[0];
	    break;
	case 'a':
	    aifftime = 1;
	    break;
	case 'c':
	    argv++;
	    camout = 1;
	    camno = atoi(argv[0]);
	    break;
	case 'v':
	    verbose = 1;
	    break;
	default :
	    printf(usage);
	    return 2;	/* NG */
	}
    }

    /* カメラ番号チェック */
    if ( camno > 9999 ){
	printf("seqconv: camera number %d too large\n", camno);
	return 1;	/* NG */
    }

    /* little-endianに設定 */
    SetEndian(0);

    /* メモリ確保 */
    if ( !AllocMem() ){
	return 1;	/* NG */
    }

    /* データの作成 */
    if ( camout ){
	if ( !MakeCamOnly() ){
	    return 1;	/* NG */
	}
    }
    else {
	if ( !MakeData() ){
	    return 1;	/* NG */
	}
    }

    /* ファイルの書き込み */
    if ( !WriteFile() ){
	return 1;	/* NG */
    }

    /* おしまい */
    free(workbuff);

    if ( viderr ){
	printf("VoiceID[] にファイル名が入ってるようですので、ついでの時に直して下さい。\n");
    }
    return 0;	/* OK */
}

/*
 *	ファイルの書き込み
 */

int WriteFile()
{
    FILE *fp;
    int   size;

    fp = fopen(outfn, "w");
    if ( !fp ){
	printf("%s : cannot open\n", outfn);
	return 0;	/* NG */
    }
    size = GetInt32(&workbuff[4]);
    if ( fwrite(workbuff, 1, size, fp) != size ){
	printf("%s : write error\n", outfn);
	return 0;	/* NG */
    }
    close(fp);
    return 1;	/* OK */
}

/*
 *	メモリ確保
 */

int AllocMem()
{
    workbuff = malloc(sizeof(WORK)+1024);	/* 多いめに */
    if ( !workbuff ){
	printf("seqconv: not enough memory\n");
	return 0;	/* NG */
    }
    memset(workbuff, 0, sizeof(WORK));
    work = (WORK *)workbuff;
    camdata = work->cam;
    movdata = work->mov;
}

/*
 *	カメラデータのみの作成
 */

int MakeCamOnly()
{
    int  datasize;

    /* カメラデータの作成 */
    CreateCamData();

    /* データをバッファ先頭へ転送 */
    datasize = camdata - work->cam;
    memcpy(workbuff, work->cam, datasize);
}

/*
 *	データの作成
 */

int MakeData()
{ 
#define seqhdr ((SEQHEADER *)work->seq)
    int  *seq, *ip;
    int   nframes;

    /* シーケンスデータの作成 */

    seq = (int *)(work->seq + sizeof(SEQHEADER));
    ip  = Scene;
    for (;;){
	SetInt32(seq++, ip[0]);		/* frame */
	if ( ip[1] ){			/* CAMERA */
	    seq = ReqCamera(seq, ip[1]);
	}
	if ( ip[2] ){			/* MOVE */
	    seq = ReqMove(seq, ip[2]);
	}
	if ( ip[3] ){			/* MOTION */
	    seq = ReqMotion(seq, ip[3]);
	}
	if ( ip[4] ){			/* EFFECT */
	    seq = ReqEffect(seq, ip[4]);
	}
	if ( ip[5] ){			/* VOICE */
	    seq = ReqVoice(seq, ip[5]);
	}
	if ( ip[6] ){			/* SE */
	    seq = ReqSE(seq, ip[6]);
	}
	SetInt32(seq++, stEND);
	ip += 7;
	if ( ip[1] > 1 ){
	    nframes = ip[1];
	    break;
	}
    }
    SetInt32(seq++, -1);		/* end mark */
    workdatap = (char *)seq;

    /* リミットチェック */

    if ( (char *)seq >= &work->seq[SEQBSIZE] ){
	printf("seqconv: conversion error (seq,internal)\n");
	return 0;	/* NG */
    }
    if ( camdata >= &work->cam[CAMBSIZE] ){
	printf("seqconv: conversion error (cam,internal)\n");
	return 0;	/* NG */
    }
    if ( movdata >= &work->mov[MOVBSIZE] ){
	printf("seqconv: conversion error (mov,internal)\n");
	return 0;	/* NG */
    }

    /* ヘッダの設定 */

    memcpy(&seqhdr->id, "ASEQ", 4);
    SetInt32(&seqhdr->size, (char *)seq - work->seq);
    SetInt32(&seqhdr->nframes, nframes);
    seqhdr->endian  = endian();
    seqhdr->version = 5;

    /* スプラインデータの転送 */

    TransSplData();

    /* 全体ヘッダの設定 */

    memcpy(workbuff, "TRCK", 4);
    SetInt32(workbuff+4, workdatap - workbuff);
}

/*
 *	スプラインデータの転送
 */

static void TransSplData()
{
    int   i, headsize, datasize;
    char  *datap = workdatap;
    short *clipp;

    /* カメラデータの転送 */

    headsize = 16 + (ncam + 1) * sizeof(char **);
    datasize = camdata - work->cam;
    memcpy(datap, "ACAM", 4);			/* chunk ID */
    SetInt32(datap + 4, headsize + datasize);	/* chunk size */
    SetInt32(datap + 12, ncam);			/* 数 */
    datap += 16;
    for (i = 0; i < ncam; i++){		/* オフセットテーブルの作成 */
	SetInt32(datap, work->camtbl[i] - work->cam + headsize);
	datap += 4;
    }
    SetInt32(datap, headsize + datasize);	/* end mark */
    datap += 4;
    memcpy(datap, work->cam, datasize);
    datap += datasize;

    /* 移動データの転送 */

    headsize = 16 + (nmov + 1) * sizeof(char **);
    datasize = movdata - work->mov;
    memcpy(datap, "AMOV", 4);			/* chunk ID */
    SetInt32(datap + 4, headsize + datasize);	/* chunk size */
    SetInt32(datap + 12, nmov);			/* 数 */
    datap += 16;
    for (i = 0; i < nmov; i++){		/* オフセットテーブルの作成 */
	SetInt32(datap, work->movtbl[i] - work->mov + headsize);
	datap += 4;
    }
    SetInt32(datap, headsize + datasize);	/* end mark */
    datap += 4;
    memcpy(datap, work->mov, datasize);
    datap += datasize;

    /* 文字列データの転送 */

    if ( nstr ){
	workdatap = datap;			/* 'ASTR' の先頭をメモ */
	headsize = 16 + (nstr + 1) * sizeof(char *);
	datap += headsize;
	for (i = 0; i < nstr; i++){	
	    SetInt32(workdatap + 16 + i * sizeof(char *), datap - workdatap);
	    strcpy(datap, work->strtbl[i]);
	    datap += strlen(work->strtbl[i]) + 1;
	}
	SetInt32(workdatap + 16 + i * sizeof(char *), datap - workdatap);
	datap = (char *)(((int)datap + 3) & ~3); 	/* 切り上げ */
	memcpy(workdatap, "ASTR", 4); 			/* chunk ID */
	SetInt32(workdatap + 4, datap - workdatap); 	/* chunk size */
	SetInt32(workdatap + 12, nstr);
    }

    /* 口パクデータの転送 */

#ifdef USER_takanao
	  printf("  nclip = %x\n", nclip );
#endif
    if ( nclip ){
	workdatap = datap;			/* 'ALIP' の先頭をメモ */
	headsize = 16 + (nclip + 1) * sizeof(short *);
	datap += headsize;
	for (i = 0; i < nclip; i++){	
	    SetInt32(workdatap + 16 + i * sizeof(short *), datap - workdatap);
	    clipp = work->cliptbl[i];
	    if ( clipp ){
		do {
		    SetInt16(datap, *clipp);
		    datap += 2;
		} while ( *clipp++ != -1 );
	    }
	    else {
		SetInt16(datap, -1);
		datap += 2;
	    }
	}
	SetInt32(workdatap + 16 + i * sizeof(short *), datap - workdatap);
	datap = (char *)(((int)datap + 3) & ~3); 	/* 切り上げ */
	memcpy(workdatap, "ALIP", 4); 			/* chunk ID */
	SetInt32(workdatap + 4, datap - workdatap); 	/* chunk size */
	SetInt32(workdatap + 12, nclip);
    }

    /* ポインタをメモして戻る */

    workdatap = datap;
}

/*
 *	カメラのリクエスト
 */

static int *ReqCamera(int *a, int n)
{
    SEQ *seq = (SEQ *)a;
    (void)n;				/* １つだけなので無視 */

    seq->type = stCAMERA;
    seq->argc = 2;
    SetInt32(&seq->args[0], ID_CAMERA);
    SetInt32(&seq->args[1], ncam);
    CreateCamData();
    seq = (SEQ *)&seq->args[2];

    return (int *)seq; 
}

/*
 *	移動のリクエスト
 */

static int *ReqMove(int *a, int n)
{
    SEQ *seq = (SEQ *)a;

    while ( n-- ){
	seq->type = stMOVE;
	seq->argc = 2;
	SetInt32(&seq->args[0], scMove[0]);
	SetInt32(&seq->args[1], nmov);
	CreateMovData();
	seq = (SEQ *)&seq->args[2];
	scMove += 2;
    }
    return (int *)seq; 
}

/*
 *	モーションのリクエスト
 */

static int *ReqMotion(int *a, int n)
{
    SEQ *seq = (SEQ *)a;

    while ( n-- ){
	seq->type = stMOTION;
	seq->argc = 5;
	SetInt32(&seq->args[0], scMotion[0]);
	SetInt32(&seq->args[1], scMotion[1]);
	SetInt32(&seq->args[2], scMotion[2]);
	SetInt32(&seq->args[3], scMotion[3]);
	SetInt32(&seq->args[4], scMotion[4]);
	seq = (SEQ *)&seq->args[5];
	scMotion += 5;
	if ( (char *)scMotion > (char *)VoiceID ){
	    printf("older version MotionID[] data\n");
	    exit(1);
	}
    }
    return (int *)seq; 
}

/*
 *	特殊効果のリクエスト
 */
static int *ReqEffect(int *a, int n)
{
    int id, type, ptn, spd;
    SEQ *seq = (SEQ *)a;

    type = TYPE_DEFAULT;
    ptn = PTN_DEFAULT;
    spd = SPD_DEFAULT;

	seq->type = stEFFECT;
	seq->argc = 4;
        id = scEffect[0];
    
    while ( n-- ){

      if ( scEffect[1] & TYPE_ID ) {
	type = scEffect[1] & ID_MASK;
      } else
	if ( scEffect[1] & PTN_ID ) {
	  ptn = scEffect[1] & ID_MASK;
	} else
	  if ( scEffect[1] & SPD_ID ) {
	    spd = scEffect[1] & ID_MASK;
	  }
      scEffect += 2;
    }

#ifdef USER_takanao
    printf("ReqEffect : %x %d %d %d\n",id, type, ptn, spd );
#endif

	SetInt32(&seq->args[0], id);
	SetInt32(&seq->args[1], type);
	SetInt32(&seq->args[2], ptn);
	SetInt32(&seq->args[3], spd);
	seq = (SEQ *)&seq->args[4];

    return (int *)seq; 
}

/*
 *	声のリクエスト
 */

static int *ReqVoice(int *a, int n)
{
    SEQ *seq = (SEQ *)a;
    float	sec;

    while ( n-- ){
	seq->type = stVOICE;
	seq->argc = 5;
	SetInt32(&seq->args[0], scVoice[0]);
	SetInt32(&seq->args[1], nstr);
	SetInt32(&seq->args[2], -1);
	SetInt32(&seq->args[3], scVoice[1]);
	if ( _fdata <= (char *)scVoice[1] && (char *)scVoice[1] <= _fbss ){
	    if ( memcmp((char *)scVoice[1], "/p16", 4) == 0 ){
		printf("VoiceID[%d][1] = -1  (%s)\n", (scVoice - (int *)VoiceID) / 3, scVoice[1]);
		seq->args[3] = -1;
		viderr = 1;
	    }
	}
	seq->args[4] = 0;
	if ( aifftime ){
	    sec = GetAiffTime(VoiceName[nv]);
	    SetInt32(&seq->args[4], *(int *)&sec);

#ifdef USER_takanao
printf("scVoice(length) : %f, %x\n",sec, seq->args[4]);
#endif
	}
	work->strtbl[nstr] = VoiceName[nv];
	nstr++;
	nv++;
/*#ifdef USER_takanao
	  printf(" ADR-work = %x %x %x\n",  &work, &work->strtbl, &work->cliptbl );
#endif*/
	if ( scVoice[2] ){
	  /* 口パク */
/*#ifdef USER_takanao
	  printf(" VoiceID[2] = %d,  nclip = %x,  ADR-cliptbl = %x\n", scVoice[2], nclip, &work->cliptbl[nclip] );
#endif*/
	    SetInt32(&seq->args[2], nclip);
	    work->cliptbl[nclip++] = (short *)scVoice[2];
	}
	seq = (SEQ *)&seq->args[5];
	scVoice += 3;
    }
    return (int *)seq; 
}

enum {
  SEQCONV_VER2 = -1,
  SE_VOL_DEFAULT = 127,
  SE_PACK_DEFAULT = 4,
  SE_MIDI_DEFAULT = 16,
  SE_FLAG_DEFAULT = 0x00
};
    
#define SE_ADDITION (0.5)

/*
 *	効果音のリクエスト
 */

static int *ReqSE(int *a, int n)
{
    SEQ *seq = (SEQ *)a;
    float	sec;

      while ( n-- ){
	seq->type = stSE;
	seq->argc = 9;
	SetInt32(&seq->args[0], scSE[0]);
	SetInt32(&seq->args[1], scSE[1]);
	SetInt32(&seq->args[2], nstr);
	SetInt32(&seq->args[3], scSE[2]);
	if ( scSE[2] == SEQCONV_VER2 ) {
	  /* 新バージョンデータ */
/*#ifdef USER_takanao
printf("scSE(Ver3) : %x, %x, %d, %d, %d, %d, %d\n",scSE[0],scSE[1],scSE[2],scSE[3],scSE[4],scSE[5],scSE[6]);
#endif
*/	  SetInt32(&seq->args[4], scSE[3]);    /* vol */
	  SetInt32(&seq->args[5], scSE[4]);    /* pack */
	  SetInt32(&seq->args[6], scSE[5]);    /* MIDI */
	  SetInt32(&seq->args[7], scSE[6]);    /* flag */
	  scSE += 7;
	} else {
	  /* 旧バージョンデータ */
/*#ifdef USER_takanao
printf("scSE(Ver1) : %x, %x\n",scSE[0], scSE[1]);
#endif
*/	  SetInt32(&seq->args[4], SE_VOL_DEFAULT);    /* vol */
	  SetInt32(&seq->args[5], SE_PACK_DEFAULT);    /* pack */
	  SetInt32(&seq->args[6], SE_MIDI_DEFAULT);    /* MIDI */
	  SetInt32(&seq->args[7], SE_FLAG_DEFAULT);    /* flag */
	  scSE += 2;
	}

	/* SE長さ */
	seq->args[8] = 0;
	if ( aifftime ){
	    sec = GetAiffTime(SoundEffectName[nse]);
	    sec += (float)SE_ADDITION;
	    SetInt32(&seq->args[8], *(int *)&sec);

/*#ifdef USER_takanao
printf("scSE(length) : %f, %d\n",sec, (int)(sec * 30.0f));
#endif
*/
	}

	seq = (SEQ *)&seq->args[9];
	work->strtbl[nstr] = SoundEffectName[nse];
	nstr++;
	nse++;
      }
    return (int *)seq; 
}

/*-------  多湖スプラインモジュール用データ変換 --------*/
/*
 *	カメラデータの作成
 */

static void CreateCamData()
{
#ifdef TIME_CHECK
    {
	const CAMDATA *cam;
	int num;
	int i;

	cam = CamAll[ncam].cam;
	num = sizeof (CamAll[0].cam) / sizeof (CamAll[0].cam[0]);
	for (i = 0; i < num; i++) {
	    if (cam->n >= 2) {
		const FCVKEYt *ptr;
		int n;

		ptr = cam->p;
		for (n = 1; n < cam->n; n++) {
		    if (ptr[0].time >= ptr[1].time) {
			static const char *str[]=
			{
			    "camX",
			    "camY",
			    "camZ",
			    "intX",
			    "intY",
			    "intZ",
			    "pers",
			    "roll",
			};

			printf ("%s[%d].timeの値が正しくありません。N番目のtimeは、N-1番目のtimeより大きくなければなりません。\n", str[i], n);
			exit (1);
		    }
		    ptr++;
		}
	    }
	    cam++;
	}
    }
#endif
    work->camtbl[ncam] = camdata;
    camdata = CreateSplData((int *)camdata, &CamAll[ncam].cam, 1);
    ncam++;
}

/*
 *	移動データの作成
 */

static void CreateMovData()
{
#ifdef TIME_CHECK
    {
	const MOVDATA *mov;
	int num;
	int i;

	mov = MoveAll[nmov].mov;
	num = sizeof (MoveAll[0].mov) / sizeof (MoveAll[0].mov[0]);
	for (i = 0; i < num; i++) {
	    if (mov->n >= 2) {
		const FCVKEYt *ptr;
		int n;

		ptr = mov->p;
		for (n = 1; n < mov->n; n++) {
		    if (ptr[0].time >= ptr[1].time) {
			static const char *str[]=
			{
			    "trsX",
			    "trsY",
			    "trsZ",
			    "rotX",
			    "rotY",
			    "rotZ",
			    "kaoX",
			    "kaoY",
			    "kaoZ",
			};

			printf ("MoveAll[%d]の%s[%d].timeの値が正しくありません。N番目のtimeは、N-1番目のtimeより大きくなければなりません。\n", nmov, str[i], n);
			exit (1);
		    }
		    ptr++;
		}
	    }
	    mov++;
	}
    }
#endif
    work->movtbl[nmov] = movdata;
    movdata = CreateSplData((int *)movdata, &MoveAll[nmov].mov, 0);
    nmov++;
}

/*
	MOTION CAMERAのデータ構造	     TRANS/ROTのデータ構造       
	+-------------------------------+    +-------------------------------+
	|int32×1       アトリビュート  |    | TRN-X                         |
	+-------------------------------+    |int32×1       key frameの個数 |
	| POS-X                         |    |float×個数    time            |
	|int32×1       key frameの個数 |    |float×個数    value           |
	|float×個数    time            |    |float×個数    slope           |
	|float×個数    value           |    +-------------------------------+
	|float×個数    slope           |    | TRN-Y                         |
	+-------------------------------+    +-------------------------------+
	| POS-Y                         |    | TRN-Z                         |
	+-------------------------------+    +-------------------------------+
	| POS-Z                         |    | ROT-X                         |
	+-------------------------------+    +-------------------------------+
	| INT-X                         |    | ROT-Y                         |
	+-------------------------------+    +-------------------------------+
	| INT-Y                         |    | ROT-Z                         |
	+-------------------------------+    +-------------------------------+
	| INT-Z                         |
	+-------------------------------+
	| PERS                          |
	+-------------------------------+
	（最初と最後を除き、slopeはleftとrightの２つのデータに分割する）
*/
static void *CreateSplData(int *ip, void *dp, int cam)
{
#define EVENTCAM_SPLINE		0x00000001	/* 現在未使用 */
#define EVENTCAM_ROLL		0x00000020	/* ロールデータがついている */
#define EVENTCAM_PERS		0x00000040	/* パースデータがついている */
    static  int  splorder[2][9] =
    {
    { 0,1,2,3,4,5,7,6 },	/* cam用 persよりrollを先にする */
    { 0,1,2,3,4,5,6,7,8 },
    };
    int *so = cam ? splorder[0] : splorder[1];
    int     i, j, n, camsize;
    int     (*datap)[2], numfp, *camdata;
    float   value, offs[9];
    FCVKEYt *fp;

    if ( camout && cam ){
	camdata = ip;
	sprintf((char *)ip, "%04d", camno);
	ip++;					/* cam No. */
	ip++;					/* data size（あとで）*/
    }

    /* フラグ設定 */
    datap = (int (*)[2])dp;
    if ( cam ){
	n = EVENTCAM_SPLINE;
	if ( datap[6][1] ){
	    n |= EVENTCAM_PERS;
	}
	if ( datap[7][1] ){
	    n |= EVENTCAM_ROLL;
	}
	SetInt32(ip++, n);
    }

    /* オフセットの設定 */
    if (cam) {
	for (i = 0; i < 8; i++){
	    if ( i < 3 ){                       /* 0,1,2 は X,Y,Z なのでそのまま入れる */
		offs[i] = PlayOffs[i];
	    }
	    else if ( i < 6 ){                  /* camの 3,4,5 は int-X,Y,Z なので入れる */
		offs[i] = PlayOffs[i - 3];
	    }
	    else {				/* その他は 0.0 */
		offs[i] = 0.0;
	    }
	}
    } else {
	for (i = 0; i < 9; i++){
	    if (i < 3) {
		offs[i] = PlayOffs[i];
	    } else {
		offs[i] = 0.0;
	    }
	}
    }

    /* 並べ替え */

    for (i = 0; i < (cam ? 8 : 9); i++){	/* x y z x y z (p) */
	fp = (FCVKEYt *)datap[so[i]][0];	/* function curve のデータ位置 */
	numfp = datap[so[i]][1];		/* function curve のデータ個数 */

	if ( numfp ){
	    /* データ個数を調べる */
	    n = numfp * 2 - 2;
	    SetInt32(ip++, n);	/* key frameの個数 */

	    /* データを並べる */
	    for (j = 0; j < numfp; j++){
		value = fp[j].value + offs[i];
		SetInt32(&ip[0],   *(int *)&fp[j].time);
		SetInt32(&ip[n],   *(int *)&value);
		SetInt32(&ip[n*2], *(int *)&fp[j].left_slope);
		if ( j == 0 ){	/* 最初のtimeを zero にしておく */
		    SetInt32(ip, 0);
		}
		ip++;
		if ( j != 0 && j != numfp - 1 ){ /* 最初と最後以外は２つのデータ */
		    SetInt32(&ip[0],   *(int *)&fp[j].time);
		    SetInt32(&ip[n],   *(int *)&value);
		    SetInt32(&ip[n*2], *(int *)&fp[j].right_slope);
		    ip++;
		}
	    }

	    /* 次へ */
	    ip += n * (3 - 1);		/* time分は進んでいるので、valueとslope分を進める */
	} else {
	    SetInt32(ip++, 0);	/* データがない */
	}
    }

    /* デバッグモードならデータ出力 */
    if ( camout && cam ){
	camsize = (char *)ip - (char *)camdata;
	SetInt32(camdata + 1, camsize);
    }

    /* おしまい */
    return ip;
}

/*
 *	ファイル出力
 */

static int fwrites(char *fname, void *buff, int size)
{
    FILE *fp;
    int   wsize;

    fp = fopen(fname, "w");
    if ( !fp ){
	return 0;
    }
    wsize = fwrite(buff, 1, size, fp);
    fclose(fp);
    return wsize;
}

/*-------------  エンディアン変更モジュール ------------*/

/*
 *	グローバル変数
 */

static	char	endian16[2];	/* 16-bitのendian	*/
static	char	endian32[4];	/* 32-bitのendian	*/
static	char	str_little[] = "\0\1\2\3\0\1";
static	char	str_big[]    = "\3\2\1\0\1\0";
static	void	SetEndianByStr(char *str);

/*
 *	endian データの設定
 */

void SetEndian(int big)
{
    if ( big ){
	SetEndianByStr(str_big);
    }
    else {
	SetEndianByStr(str_little);
    }
}

static void SetEndianByStr(char *str)
{
    endian32[0] = str[0];
    endian32[1] = str[1];
    endian32[2] = str[2];
    endian32[3] = str[3];
    endian16[0] = str[4];
    endian16[1] = str[5];
}

/*
 *	endian の取得
 */

int endian()
{
    return endian16[0] != 0;
}

/*
 *	現在の endian による16/32-bitデータの読み書き
 */

int GetInt16(void *p)
{
    return ((uchar *)p)[endian16[0]] + (((uchar *)p)[endian16[1]] << 8);
}

int GetInt32(void *p)
{
    return ((uchar *)p)[endian32[0]]         + (((uchar *)p)[endian32[1]] << 8) +
	   (((uchar *)p)[endian32[2]] << 16) + (((uchar *)p)[endian32[3]] << 24);
}

void SetInt16(void *p, int n)
{
    ((uchar *)p)[endian16[0]] = n;
    ((uchar *)p)[endian16[1]] = n >> 8;
}

void SetInt32(void *p, int n)
{
    ((uchar *)p)[endian32[0]] = n;
    ((uchar *)p)[endian32[1]] = n >> 8;
    ((uchar *)p)[endian32[2]] = n >> 16;
    ((uchar *)p)[endian32[3]] = n >> 24;
}

/*-------------  AIFFファイルモジュール ------------*/

#define	ushort	unsigned short

typedef	struct	{
    int 	FileID;			/* 'FORM'	*/
    int 	FileSize;
    int 	FileType;		/* 'AIFF'	*/
    int 	CommID;			/* 'COMM'	*/
    int 	CommSize;
    short	SampleChannel;		/* 1 or 2	*/
    short	xxx1;
    short	xxx2;
    short	SampleSize;		/* 8 or 16	*/
    ushort	SampleRate[5];		/* 80-bit float	*/
} AIFFHEADER;

typedef	struct	{
    int 	chunkID;
    int 	chunkSize;
} AIFFCHUNK;

/*
 *	AIFFファイルのプレイ時間を取得
 */

float GetAiffTime(char *fname)
{
    AIFFHEADER 	head;
    AIFFCHUNK  	chunk;
    FILE	*fp;
    float	sec, rate;
    
    fp = fopen(fname, "r");
    if ( !fp ){
	return 0;	/* NG */
    }
    if ( fread(&head, 1, 38, fp) != 38 ){
	fclose(fp);
	return 0;	/* NG */
    }
    if ( head.FileID != 'FORM' || head.FileType != 'AIFF' ){
	fclose(fp);
	return 0;	/* NG */
    }
    for (;;){
	if ( feof(fp) ){
	    fclose(fp);
	    return 0;	/* NG */
	}
	fread(&chunk, 1, sizeof(chunk), fp);	/* チャンクヘッダを読む */
	if ( chunk.chunkID == 'SSND' ){		/* サンプリングデータ */
	    break;
	}
	fseek(fp, chunk.chunkSize, SEEK_CUR);	/* 次のチャンクへ */
    }
    fclose(fp);
    rate = head.SampleRate[1] >> (0x400e - head.SampleRate[0]);	/* 80-bit floatを変換（手抜き）*/
    sec = (chunk.chunkSize - 8) / head.SampleChannel / (head.SampleSize / 8) / rate;
    if ( verbose ){
	printf("%s %d-ch %d-bit %g Hz %f sec\n", fname, head.SampleChannel, head.SampleSize, rate, sec);
    }
    return sec;
}


