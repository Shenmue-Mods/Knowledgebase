# Make Beta Areas Playable

As an example, we will take the case of Sakuragaoka's Beta Area, which its data is found in `SCENE\01\JD99`.
We will also make the assumption, that you have the data of the retail version of `Shenmue I` (and not the BETA 0.400 version).

We will modify the contents of Sakuragaoka's Final-Version Area, which is found in `SCENE\01\JD00`.

### Steps

1. Delete everything in the folder `JD00`, except from the `MAPINFO.BIN` file (in case you want to back up these files, copy/paste
them some place else, instead of deleting).

2. Copy all the `MT5` files from `JD99` and paste them to `JD00`.

3. Go to `JD00` and open its `MAPINFO.BIN` with a [hex editor](https://mh-nexus.de/en/hxd/).

4. Go to `JD99` and open its `MAPINFO.BIN` with a hex editor.

5. Find (Ctrl+F) in the `MAPINFO.BIN` of `JD99` the tag `ECAM`.

    5.1. Select/highlight `ECAM` and everything else until the end of the file.
    
    5.2. Copy (Ctrl+C) everything that you have selected/highlighted.

6. Find (Ctrl+F) in the `MAPINFO.BIN` of `JD00` the tag `ECAM`.

    6.1. Select/highlight `ECAM` and everything else until the end of the file.
    
    6.2. Paste (Ctrl+V) the contents of the clipboard.
    
    6.3. Save (Ctrl+S).

7. Proceed to [Create a Bootable CDI](Dreamcast_Information/Create_Bootable_CDIs.md).

***

The general idea is this:
 - You need a folder/directory with the files of the Beta Area (in this case `JD99`'s).
 
 - In that folder, you need a `MAPINFO.BIN` which is comprised of this data:
 
   1. The *pre-ECAM* data of the Final-Version Area's `MAPINFO` (in this case `JD00`'s).
   2. And, immediately after that data, the *post-ECAM* (including `ECAM`) data of the Beta Area's `MAPINFO` (in this case `JD99`'s).
