# Character Swapping Tutorial

**Phase 1**

1. Open "SCENE\XX\STREAM" folder (where XX is a number). 
2. Find the files "HUMANS.AFS" and "HUMANS.IDX" and Cut [CTRL+X] them.
3. Create a folder (name it as you want). *[We will reference it as "your folder" from now on.]*
4. Paste the files "HUMANS.AFS" and "HUMANS.IDX" inside your folder.
5. Run "[AFS Utils](http://shenmuesubs.sourceforge.net/download/#afs)".
6. Navigate on the menu as: "File => Open files..."
7. Find your folder and select the file "HUMANS.AFS" and Open it.
8. Select "HUMANS.AFS" on the Files List.
9. Navigate on the menu as: "Edit => Extract all files..."
10. Select your folder to extract the files.

*Note*: The rest of the steps are always the same, no matter what characters you want/attempt to swap with. However, the names (of the two files of the characters) can change in each case. For example, in this tutorial we will try to swap "Wang Guang Ji" (with ID "YKHI") with "Lan Di" (with ID "SORY").

**Phase 2**

1. Take note of the characters' IDs: "YKHI" and "SORY".
2. Find the file "YKHI.PKF". Open it with a [hex editor](http://en.wikipedia.org/wiki/Hex_editor). Search for and replace all occurrences of "YKHI" with "SORY".
3. Find the file "YKHI.PKS". Open it with a hex editor. Search for and replace all occurrences of "YKHI" with "SORY".
4. Find the file "SORY.PKF". Open it with a hex editor. Search for and replace all occurrences of "SORY" with "YKHI".
5. Find the file "SORY.PKS". Open it with a hex editor. Search for and replace all occurrences of "SORY" with "YKHI". *[Note: Don't worry if there isn't any.]*
6. Find the file "HUMANS.IDX". Open it with a hex editor. Search for and replace "YKHI" with "SORY" and vice versa. *[Warning: Here the idea is to swap the IDs; therefore, make sure each ID can be found only once and not in the same place.]* 

**Phase 3**

1. Open (or run again) "AFS Utils".
2. Navigate on the menu as: "File => New...".
3. Navigate on the (new) menu as: "File => Import XML list..."
4. Select and open the file "HUMANS_list.xml".
5. Navigate on the menu as: "File => Save Afs...".
6. Enter "File name:" as "HUMANS" and Save it.

**Phase 4**

1. Find the files "HUMANS.AFS" and "HUMANS.IDX" and Cut [CTRL+X] them.
2. Open "SCENE\XX\STREAM" folder (where XX is a number).
3. Paste the files "HUMANS.AFS" and "HUMANS.IDX" inside that folder.
