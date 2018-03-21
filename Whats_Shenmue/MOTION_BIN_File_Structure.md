# MOTION.BIN File Structure

The `Motion.Bin` file contains a set of animations for Ryo, including his "crouch", walking, opening doors and various fighting moves.

Other motion files (starting with "M_") also share this same structure, such as SCENE\80\TKIN\ `M_DJUC.BIN` (which contains the motion animations for when Ryo is drinking a soda at the vending machine - although testing of this file in What's Shenmue shows that its content is embedded inside another file `SIMM.DATA` which gets loaded instead).
```
Offset in file : [value] Description
00 0000 : [always 00000020] File offset to the start of the Motion Data Look-up Table.
00 0004 : [00012AC4] File offset to the first entry in the Motion Name Look-up Table.
00 0008 : [0001B178] File offset to the start of the Motion Data Table.
00 000C : [05] Single byte. Total number of animations contained in this file, plus one.
00 000D : ??
00 0010 : [001CA5F8] File length
00 0014 : ??
00 001C : [00000000] Null bytes

---------- Motion Data Look-up Table ----------
00 0020 : [00000000] Table offset in the Motion Data Table for the first animation. (An additional 0D bytes must also be added to allow for the table header).
00 0024 : [00007564] File offset to "extra data" for the first animation.

00 0028 : [0000035C] Table offset in the Motion Data Table for the second animation. (An additional 0D bytes must also be added to allow for the table header).
00 002C : [00007CC0] File offset to "extra data" for the second animation.
...
---------- End of Motion Data Look-up Table ----------

---------- Extra Data Table (purpose not confirmed) ----------
00 7564 : First entry
00 7CC0 : Second entry
...
---------- End of Extra Data Table ----------

---------- Motion Name Look-up Table ----------
01 2AC4 : [00014284] File offset to the first Motion Name ("AB_031")
01 2AC8 : [0001428B] File offset to the second Motion Name ("AB_041_VF3")
...
---------- End of Motion Name Look-up Table ----------

---------- Motion Name Data ----------
01 4284 : ["AB_031"] First entry (name of first animation). 
01 428B : ["AB_041_VF3"] First entry (name of first animation). 
...
---------- End of Motion Name Data ----------

---------- Motion Data Table ----------
----------  Note, each entry starts with the following 40-byte sequence:
----------  F8 01 38 02 38 0A C0 11 38 12 38 18 C0 1F 38 20
----------  38 24 C0 29 38 2A C0 2F 38 32 38 34 C0 3B 38 3C
----------  38 3E 38 40 C0 47 38 48

01 B178 : [BE 00 00 00 36 00 75 00 A8 03 AC 04]  ?? Header of 12 bytes. Meaning unknown. 
01 B184 : First entry (data for the first animation, AB_031). This is the zero-offset entry.
01 B4E0 : Second entry (data for the second animation, AB_041_VF3).
...
---------- End of Motion Data ----------

1C A5D8 : "Fri Jul 16 19:22:06 1999" (Date of file creation)
1C A5F4 : [00000000] Null bytes
```