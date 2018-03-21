# How to Play Any Music Track in the Title Screen

<p align="center"> **Tutorial how to play any music track**

**in the title** (more precisely, the menu) **screen of Shenmue II.** </p>

***

How to play "0003_001.SND" (Kowloon intro)

**STEPS**:

```
1) In Shenmue II's root folder, find and open the file "1ST_READ.BIN" with a hex editor (and leave it open).
2) Navigate to \SCENE\03\SOUND; find and copy (CTRL+C) the file "0003_001.SND".
3) Navigate (go up) to MISC and paste (CTRL+V) (the file "0003_001.SND").
4) In the MISC folder, find and open the file "TIT_SND.BIN" with a hex editor (and leave it open).
5) Navigate to \SCENE\03\0200; find and open the file "MAPINFO.BIN" with a hex editor.
5.1) Find (CTRL+F) the text-string reference of SMAP (in the file "MAPINFO.BIN").
5.2) Place the cursor before the character S of the text-string SMAP.
5.3) Press the combination of keys CTRL+E (to select a block of bytes).
5.4) Select the radio-button of the "Length:" legend.
5.5) In the text-area, replace the highlighted text with 194.
5.6) Make sure the radio-button of the "hex" legend is selected (below).
5.7) Click on the "OK" button.
5.8) Copy (CTRL+C) the selected/highlighted block of bytes (in your clipboard).
6) In the hex editor, select the TIT_SND.BIN tab.
6.1) Select all (CTRL+A) the bytes.
6.2) Paste (CTRL+V) the content of your clipboard.
6.3) Select/highlight the text-string 0200A000 and copy (CTRL+C) it.
7) In the hex editor, select the 1ST_READ.BIN tab.
7.1) Find (CTRL+F) the text-string reference of "tit_snd.bin".
7.2) Look (with your eyes) for the text-string "0002S000.sbt" before the "tit_snd.bin" one, select/highlight the "0002S000" bit of it and replace it with "0200A000".
7.3) Look (with your eyes) for the text-string "0002S000.smp" after the "tit_snd.bin" one, select/highlight the "0002S000" bit of it and replace it with "0200A000".
```

***

How to play "0002_023.SND" (Guilin intro)

**STEPS**:

```
1) In Shenmue II's root folder, find and open the file "1ST_READ.BIN" with a hex editor (and leave it open).
2) Navigate to \SCENE\04\SOUND; find and copy (CTRL+C) the file "0002_023.SND".
3) Navigate (go up) to MISC and paste (CTRL+V) (the file "0002_023.SND").
4) In the MISC folder, find and open the file "TIT_SND.BIN" with a hex editor (and leave it open).
5) Navigate to \SCENE\04\KRF1; find and open the file "MAPINFO.BIN" with a hex editor.
5.1) Find (CTRL+F) the text-string reference of SMAP (in the file "MAPINFO.BIN").
5.2) Place the cursor before the character S of the text-string SMAP.
5.3) Press the combination of keys CTRL+E (to select a block of bytes).
5.4) Select the radio-button of the "Length:" legend.
5.5) In the text-area, replace the highlighted text with 194.
5.6) Make sure the radio-button of the "hex" legend is selected (below).
5.7) Click on the "OK" button.
5.8) Copy (CTRL+C) the selected/highlighted block of bytes (in your clipboard).
6) In the hex editor, select the TIT_SND.BIN tab.
6.1) Select all (CTRL+A) the bytes.
6.2) Paste (CTRL+V) the content of your clipboard.
6.3) Select/highlight the text-string 0500A000 and copy (CTRL+C) it.
7) In the hex editor, select the 1ST_READ.BIN tab.
7.1) Find (CTRL+F) the text-string reference of "tit_snd.bin".
7.2) Look (with your eyes) for the text-string "0002S000.sbt" before the "tit_snd.bin" one, select/highlight the "0002S000" bit of it and replace it with "0500A000".
7.3) Look (with your eyes) for the text-string "0002S000.smp" after the "tit_snd.bin" one, select/highlight the "0002S000" bit of it and replace it with "0500A000".
```

*Note (valid for both STEPS sections above)*: the step 6.3 is potentially unusable, however, it was left just to emphasize where the text-string "`0200A000`"/"`0500A000`" comes from when it used later on (steps 7.2-7.3). Also, in this tutorial the hex editor named [HxD](https://en.wikipedia.org/wiki/HxD) was used.

***

How to play any other music track

**STEPS**:

```
1) Navigate to \SCENE\0X\SOUND (where X is a number); find and copy (CTRL+C) the .SND file (of the music track you want to play).
2) Navigate (go up) to MISC and paste (CTRL+V) (the .SND file).
3) In the MISC folder, find and open the file "TIT_SND.BIN" with a hex editor.
3.1) Select/highlight the text-string 0017_012.
3.2) Replace the selected/highlighted text-string with the prefix of the .SND file.
```

