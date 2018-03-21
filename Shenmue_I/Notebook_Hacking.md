# Notebook Hacking

This page will show you how to edit the notebook in *Shenmue I*. This process is the same for all versions of *S1* including the *BETA 0.400*.

Instructions:

1. Open `1ST_READ.BIN` in a hex editor.

2. Search for a known notebook entry to find its place in the file.

3. Directly edit the Unicode found in the hex.

4. - Be careful about the dots. The dots represent new lines in the notebook.

5. Try to match the number of characters already in the notebook when editing or else you may throw text out of bounds, thus crashing the notebook when you turn to that page and locking the game.

**Notebook Extended Hacking**

If you want to fully edit the Notebook, first go see the 1ST_READ Text/Pointer modifications page. Then, here's the following data (Based on the PAL version):

- The Notebook entries are located between `0x26E4E8` and `0x271C67`. If you want to do a full edit, you only have that space, unless you've optimized other parts from the game and have empty space in other blocks, as the texts can be virtually anywhere inside the `1ST_READ.BIN` (The problem being overwriting what you shouldn't overwrite...)

 - The Notebook pointer system goes from `0x289D14` until `0x28AEB0`. Every four bytes are being used, if the string is empty, the pointer MUST be replaced with `0x00000000`.
\- The Flags System, which tell the game under what conditions should each line appear, go from `0x2892E4` to `0x289D10`. Keep in mind that even the notebook's front and back cover have strings which should NOT have content inside. The first page is page 03, which starts at `0x289350`. It's a bit different from WS's system and S2's system. Here's the full structure:

- 4 bytes: Screen number (One screen is two pages, left and right. This is the left page)
- 16 bytes: Each two bytes are a line's flag code. If the line is empty, it should read `0000`.
- 4 bytes: Screen number (One screen is two pages, left and right. This is the right page)
- 16 bytes: Each two bytes are a line's flag code. If the line is empty, it should read `0000`.