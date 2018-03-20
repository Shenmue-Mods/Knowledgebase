# PVR Graphic Format

```
PVR Graphic Formats (Dreamcast 2D Graphics)
By SmokesGrass:|
http://www.thehorrorisalive.com/markgrass/index.html

Version 0.1 - March 03, 2006
	- Highly updated version from original 2001 document by an 
	  unknown person.
________________________________________________________________________

HEADER
________________________________________________________________________

[GLOBAL INDEX HEADER]
This header is optional defining a "Global Index".

offset length description
--------------------------
0-3     4     "GBIX" (ascii text)
4-7     4     Length of GBIX header from offset 8 onwards
8-15    8     Global Index
________________________________________________________________________

[PVR GRAPHIC HEADER]

offset length description
--------------------------
0-3     4     "PVRT" (ascii text)
4-7     4     Length of rest of file in bytes (not counting these 4 bytes)
8-11    4     Type of PVR file
12-13   2     Width
14-15   2     Height
________________________________________________________________________

[PVR GRAPHIC TYPE]
There are 4 bytes reserved for the PVR type. Byte 1 identifies the
Pixel Format. Byte 2 identifies the Image Data Type. Bytes 3 & 4
are blank (0x0000).
The 2 bytes for each type are as follows:

byte 1 (Pixel Format):
0x00 = ARGB1555 (bilevel translucent alpha 0,255)
0x01 = RGB565 (no translucent)
0x02 = ARGB4444 (translucent alpha 0-255)
0x03 = YUV442
0x04 = Bump
0x05 = 4-BIT (SEE BELOW)
0x06 = 8-BIT (SEE BELOW)

:4-BIT/8-BIT FORMAT:
The Dreamcast uses a PowerVR graphics chip which requires 4/8-BIT images to be 
"twiddled" before blending, therefore 4/8-BIT images are always twiddled. Also, 
not every 4/8-BIT PVR image uses a CLUT.

byte 2 (Image Data Type):
0x00 = 
0x01 = SQUARE TWIDDLED
0x02 = SQUARE TWIDDLED & MIPMAP
0x03 = VQ
0x04 = VQ & MIPMAP
0X05 = 8-BIT CLUT TWIDDLED
0X06 = 4-BIT CLUT TWIDDLED
0x07 = 8-BIT DIRECT TWIDDLED
0X08 = 4-BIT DIRECT TWIDDLED
0x09 = RECTANGLE
0x0A = 
0x0B = RECTANGULAR STRIDE
0x0C = 
0x0D = RECTANGULAR TWIDDLED
0x0E = 
0x0F = 
0x10 = SMALL VQ
0x11 = SMALL VQ & MIPMAP
0x12 = SQUARE TWIDDLED & MIPMAP
________________________________________________________________________

[WIDTH AND HEIGHT]
The width and height of every PVR image is setup in multiples of 256 with 
4 bytes total representing both width and height.
The 2 bytes representing both BPP values are as follows:

0x0000 = 0
0x0001 = 256
0x0002 = 512
0x0003 = 768
0x0004 = 1024
....and so on.
________________________________________________________________________

[IMAGE DATA]
________________________________________________________________________

[PIXEL TYPE]
There are 7 different pixel image types used in PVR graphics that 
immediately follow the PVR header.

0x05 (4-BIT):
4-BIT images use a 1024 byte table for RGB colors which makes 64
possible 16-color palettes.

offset length description
--------------------------
0-3FF   1024  CLUT
400-?   ?     Image Data

0x06 (8-BIT):
8-BIT images use a 1024 byte table for RGB colors which makes 4 
possible 256-color palettes.

offset length description
--------------------------
0-3FF   1024  CLUT
400-?   ?     Image Data
```