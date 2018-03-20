# SPSD files

```
How to rip/play SPSD files:

SPSD magic at offset 0x00, 0x40 bytes of header, then Yamaha ADPCM data (all files I've seen have 2 channels with 0x2000 interleave).

Offset 0x0c in header stores # of samples in the file (DWORD, LE). Add header size to that and you have full SPSD filesize.

Offset 0x2a in header stores stream frequency (WORD, LE).
```

Source: <http://forums.bannister.org/ubbthreads.php?ubb=showflat&Number=46112#Post46112>