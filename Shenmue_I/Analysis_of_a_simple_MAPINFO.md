# Analysis of a simple MAPINFO

An attempt to analyze a simple mapinfo file of Shenmue I.

Specifically Area 0000's mapinfo file.

[Byte order is in Little Endian.]

```
Offset(h) 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F

00000000  41 54 54 52 08 00 00 00 53 43 4E 33 A8 00 00 00  ATTR....SCN3¨...
00000010  00 01 00 00 30 00 00 00 74 00 00 00 A0 00 00 00  ....0...t... ...
00000020  00 00 00 00 00 00 00 00 30 00 00 00 A0 00 00 00  ........0... ...
00000030  00 00 00 00 00 00 00 00 13 00 70 41 4B 49 52 50  ..........pAKIRP
00000040  01 73 43 00 00 00 1B 02 13 0C 00 13 00 50 01 5E  .sC..........P.^
00000050  08 1B 1F 13 08 5E 08 1B 05 13 04 50 01 1B 2D 13  .....^.....P..-.
00000060  04 50 01 17 01 1C 00 13 04 50 01 2B 95 01 13 04  .P.......P.+•...
00000070  50 01 17 01 1C 00 13 04 00 FF FF FF 00 00 80 3F  P..........€?
00000080  00 00 80 3F 00 00 80 3F FF FF FF 00 FF FF FF 00  ..€?..€?..
00000090  FF FF FF 00 FF FF FF 00 00 00 A0 41 00 00 48 44  .... A..HD
000000A0  00 00 80 3F FF FF FF FF 00 00 00 00 00 00 00 00  ..€?........
000000B0  52 45 47 44 08 00 00 00 43 48 52 44 F8 00 00 00  REGD....CHRDψ...
000000C0  43 48 52 53 88 00 00 00 BC 00 00 00 23 00 00 00  CHRS....Ό...#...
000000D0  BD 00 00 00 04 00 00 00 A6 00 00 00 19 00 00 00  ½.......¦.......
000000E0  00 00 80 3F 81 00 00 00 B1 00 00 00 22 00 00 00  ..€?....±..."...
000000F0  41 4B 49 52 14 00 00 00 7D 00 00 00 49 00 00 00  AKIR....}...I...
00000100  00 00 40 C0 00 00 00 00 00 00 00 00 72 00 00 00  ..@ΐ........r...
00000110  03 00 00 00 79 00 00 00 57 00 00 00 00 00 00 00  ....y...W.......
00000120  88 00 00 00 00 00 00 00 6B 00 00 00 03 00 00 00  ........k.......
00000130  73 00 00 00 26 00 00 00 00 00 00 00 24 00 00 00  s...&.......$...
00000140  03 00 00 00 0C 00 00 00 53 54 52 47 68 00 00 00  ........STRGh...
00000150  59 4B 41 5F 46 2E 4D 54 33 00 4F 73 61 67 65 00  YKA_F.MT3.Osage.
00000160  46 61 63 65 00 59 4B 42 5F 4D 2E 4D 54 35 00 48  Face.YKB_M.MT5.H
00000170  75 6D 61 6E 00 50 6F 73 69 74 69 6F 6E 00 49 6D  uman.Position.Im
00000180  61 67 65 00 44 65 66 49 6D 61 67 65 00 59 4B 42  age.DefImage.YKB
00000190  5F 4D 00 46 6C 61 67 73 00 43 68 61 72 61 63 74  _M.Flags.Charact
000001A0  65 72 00 44 49 53 50 00 50 6C 61 79 65 72 00 00  er.DISP.Player..
000001B0  53 43 52 4C 0C 00 00 00 01 00 00 00 45 4E 44 00  SCRL........END.
000001C0  08 00 00 00                                      ....
```

Analysis:
```
ATTR

08 00 00 00 = points to SCN3

SCN3

A8 00 00 00 = points to REGD [Value in: decimal = 168]

00 01 00 00 = value? pointer? (if it's a pointer, it points to offset 110) [Value in: decimal = 256]
30 00 00 00 = value? pointer? (if it's a pointer, it points to offset 44) [Value in: decimal = 48]
74 00 00 00 = value? pointer? (if it's a pointer, it points to offset 8C) [Value in: decimal = 116]

A0 00 00 00 = value? pointer? (if it's a pointer, it points to offset BC) [Value in: decimal = 160]

00 00 00 00 -----------------
00 00 00 00 -----------------

30 00 00 00 = value? pointer? (if it's a pointer, it points to offset 58)) [Value in: decimal = 48]

A0 00 00 00 = value? pointer? (if it's a pointer, it points to offset CC) [Value in: decimal = 160]

00 00 00 00 -----------------
00 00 00 00 -----------------

13 00 70    = NEW INFO! : The last byte (in this case, 70) points to the 8 bytes before REGD (the end of the SCN3 section)

AKIR

----------------------------- New thought about the given below: I think it's assembly code (with data/pointers/etc, too), and that's about loading the MAP.MT5 file, as well about specific settings for the player (like, if he's able to move the character or open the menu system).

50 01 73 43 = Value, of what?
00 00 00 1B = Value, of what?
02 13 0C 00 = Value, of what?

13 00 50 01 = Value, of what?
5E 08 1B 1F = Value, of what?

13 08       = Value, of what?

5E 08 1B 05 = Value, of what?
13 04 50 01 = Value, of what?

1B 2D       = Value, of what?

13 04 50 01 = Value, of what?
17 01 1C 00 = Value, of what?
13 04 50 01 = Value, of what?

2B 95 01    = NEW INFO! : The last byte (in this case, 01) is to set the Pause Screen enabled (00 for disabled).

13 04 50 01 = Value, of what?
17 01 1C 00 = Value, of what?


13 04 00 FF = Value, of what?
FF FF 00 00 = Value, of what?

80 3F 00 00 = Value, of what?
80 3F 00 00 = Value, of what?
80 3F FF FF = Value, of what?

FF 00 FF FF = Value, of what?
FF 00 FF FF = Value, of what?
FF 00 FF FF = Value, of what?

FF 00 00 00 = Value, of what?

A0 41 00 00 = Value, of what?
48 44 00 00 = Value, of what?

80 3F FF FF = Value, of what?

FF FF 00 00 = Value, of what?

00 00 00 00 -----------------
00 00       -----------------

----------------------------- End

REGD

08 00 00 00 = points to CHRD

CHRD

F8 00 00 00 = points to SCRL

CHRS

88 00 00 00 = points to STRG
BC 00 00 00 = points to "DefImage"

23 00 00 00 = value? or points before AKIR (?)

BD 00 00 00 = points to "YKB_M" (not to YKB_M.MT5, but just YKB_M)

04 00 00 00 = value? or points to the next word (=4 bytes)

A6 00 00 00 = points to "Image"

19 00 00 00 = value? (if it's a pointer, it points to the 2 bytes after AKIR)
00 00 80 3F = Value, of what?

81 00 00 00 = points to "YKB_M.MT5"
B1 00 00 00 = points to "Character"

22 00 00 00 = Value, of what? (if it's a pointer, it points to offset 10E)

AKIR

14 00 00 00 = value? or points to offset 108 (from F4-107 there are 3 

words...)

7D 00 00 00 = points to Position

49 00 00 00 = Value, of what? (if it's a pointer, it points to offset 145)

00 00 40 C0 = value of position on the X (or maybe Z) axis {signed float value}
00 00 00 00 = value of position on the Y axis [this is the height] {signed float value}
00 00 00 00 = value of position on the Z (or maybe X) axis {signed float value}

72 00 00 00 = points to "Image"

03 00 00 00 = Value, of what?

79 00 00 00 = points to "YKB_M"
57 00 00 00 = points to "Human"

00 00 00 00 -----------------

88 00 00 00 = points to "Player"

00 00 00 00 -----------------

6B 00 00 00 = points to "Flags"

03 00 00 00 = Value, of what? [maybe it has something to do with FLAG (in the 

debug menu)]

73 00 00 00 = points to "DISP"
26 00 00 00 = points to "Osage"

00 00 00 00 -----------------

24 00 00 00 = points to "Face"

03 00 00 00 = Value, of what?

0C 00 00 00 = points to "YKA_F.MT3"

STRG

68 00 00 00 = points to SCRL

YKA_F.MT3
Osage
Face
YKB_M.MT5
Human
Position
Image
DefImage
YKB_M
Flags
Character
DISP
Player

00

SCRL (=loads the skybox)

0C 00 00 00 = points to END

01 00 00 00 = Value, of what?

END
0

08 00 00 00 = points to the End Of File
```