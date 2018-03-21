# Increase the size of the Loading Screen area names


This method only works in Shenmue I.

Starting at `0x29AA58` there's a pointer system that's related to the Loading screen area names. It goes this way:
 - 4 bytes: Pointer to the stage filename/folder name.
 - 4 bytes: Pointer to the loading texture filename.
 - 2 bytes: X/Y scale for the actual graphic, Little Endian. **THIS CHANGES THE ACTUAL SIZE ON SCREEN.**
 - 2 bytes: Seem to be always `0x0000`/Purpose unknown.

