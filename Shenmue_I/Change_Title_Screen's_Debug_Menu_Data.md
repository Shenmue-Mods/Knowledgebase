# Change Title Screen's Debug Menu Data

* Open the "1ST_READ.BIN" file with a hex editor.
* Search (CTRL+F) for "PCHAF" [or go to (CTRL+G) offset `3AC358`].

*Note*: You will see keywords with 4 characters each (e.g. D000, CHAF, KOTF, SYPF, NETJ and so on). - Each keyword represents an Area. Areas are folders, as found in SCENE/XX/ (where XX is a double digit number).

To change an Area keyword:

- Highlight a keyword and replace it with the one you want. (Keywords must explicitly be of 4 characters.)

------

*Note*: One offset *before* each keyword is the information of their relevant Scene. Scenes are (sub-)folders, as found in the SCENE folder; these sub-folders have names which consist of two digits (e.g. 01, 02, 03, 80 etc). In these folders Areas are stored (as sub-folders, with names consisted of 4 characters, as said with the keywords).

To change the Scene value:

- Highlight the hexadecimal value (which is found one offset *before* the keyword) and replace it with the one you want.
- *Note*: If you want to set the Scene to 80 (as seen in the debug menu of Shenmue's title screen), then set the hexadecimal value to 50 (which in the text area of the hex editor it appears as "P"). - [Remember that all values should be in hexadecimal form (for example, if you want to set the Scene to 17, then change the hexadecimal value to 11).]

------

*Note*: One offset *after* each keyword is the information of the Entry. Entries usually set the position of the player, the progress (the STEP) of the events, which cut-scene to play as soon as the Area is loaded et cetera.

To change the Entry value:

- Highlight the hexadecimal value (which is found one offset *after* the keyword) and replace it with the one you want.
- *Note*: the Entry can take values from 0-99. - [Remember that all values should be in hexadecimal form (for example, if you want to set the Entry to 30, then change the hexadecimal value to 1E).]