# Fusing Maps Together

This page will show you how to "fuse" two maps into one.

This example will cover how to put Sakuragaoka into the Forklift Race Map on Disc 3.

Notes:

* Forklift Race Map: MA00
* Sakuragaoka Map: JD00

**BASIC TUTORIAL**:

1. Open the mapinfo for both MA00 and JD00 in a hex editor.

	* /SCENE/03/MA00/mapinfo.bin
	* /SCENE/03/MA00/mapinfo.bin

3. Delete all of the pre-ECAM hex code in JD00s mapinfo file.

4. Copy and paste/insert all of the pre-ECAM hex code from MA00's mapinfo file into JD00's mapinfo file.

5. Copy all of the contents of MA00, except for the mapinfo file, into JD00's folder and overwrite any files asked to do so.

6. Load the cdi and use JD00 entry point 99.

You will now have the two maps fused.