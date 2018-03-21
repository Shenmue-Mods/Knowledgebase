# Notebook Hacking

This section will mention the specific details about *What's Shenmue* Notebook Hacking. For a full review on the Notebook, check *Shenmue I*'s Notebook Hacking page.

The texts are between `0x237948` to `0x239068`. Unlike *Shenmue I* and *II*, the text is read from a massive kanji table, and if you input English characters, they will show the standard font, not the notebook font. So you'll need to edit the kanjis inside *RYOU.FON* to make it LOOK LIKE the notebook uses the English characters.

The pointers and flags, this time, are interwoven one and another. The actual *What's Shenmue* data starts at `0x24C1E8` (For Adult Mode), following this system:
 - 2 bytes: Page number
 - 2 bytes: Flag for that line
 - 4 bytes: Text pointer

Childs Mode pointers and flags start at `0x24C430`.