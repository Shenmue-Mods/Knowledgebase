# Notebook Editing

Notebook Editing in *Shenmue II* is quite different from the previous games.

The main bulk of the text files reside in FRENCH-GERMAN-SPANISH-SPRITE\ `BUNKI.BIN`, `MEMODATA.BIN` and `MEMOFLG.BIN`.

While this file can be edited with SiZious' Notebook Editor, there's some missing stuff: There are strings with a negative flag, meaning that they show up with a number near `65000`. Those flags are used for alternative strings.

*Shenmue I* had one design issue: Nobody could achieve a 100% complete notebook as alternatives had their own lines: If you went left in a specific part, you'll get the "going left" lines, while going right would get the "going right".

*Shenmue II* fixed this with strings that had two options or alternatives depending on the route you'd take. The first alternative, per example, would be finding Wong, Sam and Larry and beating them the first time around, or losing and having to search for them further times.

These alternatives are inside `BUNKI.BIN`. There's a (unreleased) tool that can edit BUNKI, but here's the Dreamcast structure:
 - `0x0C` bytes (12): Code stuff, don't touch.
 - 4 bytes: Two-byted file size from `0x00` until the end of the text block and the start of the pointer/flag block.
 - Contents of the text block.
 - 16 bytes: One variable information:
   - 4 bytes: First variable flag, little endian.
   - 4 bytes: Second variable flag, little endian.
   - 4 bytes: First variable text, little endian.
   - 4 bytes: Second variable text, little endian.
When a flag/pointer has an empty string, it should read `0x00000000`.

BUNKI system is different in XBOX and has to be researched. All I know is that everything's inside the `Default.xbe`, with changes in the format.