# 1ST_READ.BIN Interface Content

(Requires further research)

```
(UPDATED 2015-05-13)

KNOWN POINTER OFFSET: -C010000
NEW POINTER OFFSET? LAST TWO BYTES: 0900

0x140074: Points to 0x2123D8 - Blank area
0x140078: Points to 0x1CE600
0x14007C: Points to 0xE5954 - Takes to a group of many xx88 xx89 and text "BROM"
0x140080: Points to 0x2123D4 - Blank area
0x140084: Points to 0x7CAFC - Nearby are various "USE "
0x140088: Points to 0x2984EC - Point to "E", "F", "G", "S", "sprite". MULTI-4 info.
0x14008C: Points to 0x1CE654
0x140090: Points to "RESUME2"
0x140094: Points to ".SPR"
0x140098: Suspicious word: "RESU"
0x14009C: Points to "sprite"
0x1400A0: Points to 0xAE25E - Series of code xx2F
0x1400A4: Points to 0x1722E8 - Near words GBIX & TEXN. PVR-texture related?
0x1400A8: Points to "RESUME3"

0x1400BA: Suspicious word: "RESU"

0x140144 to 0x140172: Hex code series: 0x246110230173

0x1401AC: Points to "RESUME0"
0x1401B0: Points to ".SPR"
0x1401B4: Suspicious word: "RESU"
0x1401B8: Points to "sprite"
0x1401BC: Points to 0xAE25E - Series of code xx2F
0x1401C0: Points to 0x1722E8 - Near words GBIX & TEXN. PVR-texture related?
0x1401C4: Points to "BATTLE_"
0x1401C8: Points to ".GZ"
0x1401CC: Points to "misc"
0x1401D0: Points to 0xAE3D0 - Near word LINR. Series of code xx2F.
0x1401D4: Points to 0x1723A4 - Series of code xx2F. Near words GBIX & TEXN. PVR-texture related?

0x140288: Points to 0x2123D0 - Blank area
0x14028C: Points to 0x2123F8 - Blank area
0x140290: Points to "DISCCHG"
0x140294: Points to ".SPR"

==============================================================================================
RYO'S ROOM SAVE SCREEN STATUS: ONE AREA POSSIBLY FOUND, DATE POSITIONS (TARGET) NOT FOUND!!!!!
COMMA POSITION: X 415, Y (1) 93
OTHER POSIBLE NUMBERS: 405, 428, 443
==============================================================================================
0x140298: Suspicious word: "SAVE"
0x14029C: Points to 0x2384FC - Blank area
0x1402A0: Points to 0xAE25E.
0x1402A4: Points to 0xAE0EC.
0x1402A8: Points to 0x172356.

0x1403C0: Points to 0x1FE00C - Blank area
0x1403C4: FLOAT that caused a crash in the save screen.
0x1403C8: Points to 0x2123C8 - Blank area
0x1403CC: Points to 0x16E9AA.
0x1403D0: FLOAT, unknown.
0x1403D4: Points to 0x2123D4 - Blank area
0x1403D8: Points to 0x16E690.

0x1404D8: Unknown.

0x1404E8: Points to 0xE5954.
0x1404EC: Points to 0x1FE00C - Blank area
0x1404F0: Points to 0x141AB0.
0x1404F4: Points to 0x16E9AA.
0x1404F8: FLOAT, unknown.
0x1404FC: Points to 0x2123D4 - Blank area
0x140500: Points to 0x16E690.

0x14060E: Unknown.

0x140634: FLOAT, unknown.
0x140638: FLOAT, unknown.
0x14063C: Points to 0x1717CC.
0x140640: FLOAT, unknown.
0x140644: Points to 0x298500.
0x140648: FLOAT, unknown.

0x14078A: X Size of the lower box in the Save screen.
0x14078C: Y position of "Select file"'s first line, in the Save screen.
0x14078E: X position of "Select file"'s first line, in the Save screen.
0x140790: Unknown.
0x140792: Unknown.
0x140794: Color/transparency for both "Select file" lines in the Save screen.

0x1407A0: FLOAT (=380), Y position of the lower box in the Save screen.
0x1407A4: FLOAT (=320), X position of the lower box in the Save screen.
0x1407A8: Points to 0x1717CC.
0x1407AC: FLOAT, scale for both "Select file" lines in the Save screen.
0x1407B0: FLOAT X position of "Select file"'s second line, in the Save screen.
0x1407B4: FLOAT Y position of "Select file"'s second line, in the Save screen.
0x1407B8: FLOAT (=353) Y position of "Select file"'s second line, in the Save screen.
0x1407BC: Points to 0x298510.
0x1407C0: FLOAT (=300) X position of "Select file"'s second line, in the Save screen.
0x1407C4: FLOAT, X position of "Select file"'s second line, in the Save screen.
0x1407C8: FLOAT, moves Y position of "Select file"'s second line in the Save screen.
0x1407CC: FLOAT, unknown.
0x1407D0: FLOAT, unknown.
0x1407D4: FLOAT, unknown.
0x1407D8: FLOAT, unknown.

0x140A50: Unknown.
0x140A52: Unknown.

0x141000: FLOAT, unknown.

0x141090: Unknown, crashed the game.
0x141092: Unknown, crashed the game.

0x1411A4: FLOAT, unknown.
0x1411A8: FLOAT, unknown.

0x141254: FLOAT, texture section data related with disc numbers in the Save screen.

0x1412EA: X scale of the save boxes in the Save screen.
0x1412EC: X position of the File numbers in the Save screen.
0x1412EE: X position of the DISC\GameTime\SaveTime block in the Save screen.
0x1412F0: Unknown.
0x1412F2: X position of the disc numbers in the Save screen.
0x1412F4: FLOAT, unknown.

0x141300: FLOAT, X position of the save boxes in the Save screen.
0x141304: Points to 0x1717CC.
0x141308: Points to 0x27E9E0.
0x14130C: Points to 0x1CE618.
0x141310: Points to 0x27E9E8.

0x141318: Points to 0x27E9EC.

0x141320: Points to 0x298378.

0x141328: Points to 0x1CE0D0.
0x14132C: Points to 0x1CDF24.

0x141380: FLOAT, known to crash the game.

MISSING, NEED TO BE FOUND: X coordinates for the SaveTime/GameTime's date digits/months.

0x141B00: Suspicious word: "OP02"

0x142094: Unknown.

0x142D94: X position of Ryo's Room Action Selector (Sleep/Save/Train/Settings).

0x1434E4: Suspicious word: "SCEN"

==============================================================================================
LOADING SCREENS STATUS: FIRST FIX COMPLETE. DE-MERGE THE LOADING SCREEN'S YEAR'S SECOND DIGIT
X POSITION AND WHOLE NUMBER BLOCK, FIND THE X POSITION FOR THE COMMA, MOVE EVERYTHING
==============================================================================================

0x170762: (0x0004) Vertically flips the loading screen.
0x170764: (0x4001) X position of the area name in the loading screen.
0x170766: (0xE001) Unknown. Height screen size in pixels.
0x170768: (0x8002) Unknown. Width screen size in pixels.
0x17076A: (0xF000) Unknown.

0x1707EC: (0x8801) Unknown.

0x17082C: (0xA000) Y position of the area name in the loading screen.
0x17082E: (0x8000) X/Y scale of month/day in the loading screen.
0x170830: (0x5801) MERGED ITEM: X position of year's second digit AND Y position of the
     whole number block in the loading screen. TO DE-MERGE.
0x170832: (0x9000) X position of the month in the loading screen. CHANGE TO 0xE300.

0x1709E0: (0x6001) X/Y position (MERGED) of commas and periods in the loading screen.
0x1709E2: (0xCA00) X position of the period in the loading screen. CHANGE TO 0x1401.
0x1709E4: (0xE600) X position of day's first digit in the loading screen. CHANGE TO 0x7C00.
0x1709E6: (0x0201) X position of day's second digit in the loading screen. CHANGE TO 0x9800.
0x1709E8: (0x3C01) X position of year's first digit in the loading screen.
0x1709EA: (0x7401) X position of year's third digit in the loading screen.
0x1709EC: (0x9001) X position of year's fourth digit in the loading screen.
0x1709EE: (0xDC01) X position of weekday and its parenthesis in the loading screen.
0x1709F0: (0xE800) X position of the hour/minute block in the loading screen.
0x1709F2: (0xDC00) Unknown.
0x1709F4: (0x2801) Y position of the hour/minute block in the loading screen.

0x170B3A: (0x2C01) Y position of the AM/PM word in the loading screen.

0x170BB2: (0x6001) Unknown.

0x170C40: (0x0201) Unknown.
0x170C40: (0x0201) Unknown.

MISSING, NEED TO BE FOUND: X position of the comma (288, 0x2001; 352, 0x6001), and DE-MERGE? year's second digit X position.

0x170E16: (0x0001) Unknown.

==============================================================================================
0x175C2E: (0x4C01) Related to the main menu's saving information.
     Until 0x175C37 contains scales or non-interesting Y positions. TO RESEARCH.
==============================================================================================

0x175C2E: Unknown.
0x175C30: Unknown.
0x175C32: Scales (Strange amount) two of the three ":" in the Load screen.
0x175C34: X scale (Strange amount) one of the three periods in the Load screen.
0x175C36: Scales and moves (Strange amount) two of the three commas in the Load screen.
0x175C38: Unknown.

0x17D8C0: (0xE400) Unknown.

==============================================================================================
OPTIONAL TARGET: EXTEND WIDTH OF THE "DEFEATED" TEXT BOX (70 PERSON TIMED FREE BATTLE).
==============================================================================================

0x191498: Suspicious word: "FIGT"

0x193558: Suspicious word: "MFBT"

0x195974: FLOAT, unknown.

0x19597C: FLOAT, unknown.

0x195C94: Unknown.
0x195C96: Unknown.

0x195C9C: FLOAT, unknown.

0x195DE0: Unknown.
0x195DE4: Unknown.

0x195EE4: Unknown.
0x195EE6: Unknown.
0x195EE8: Unknown.
0x195EEA: Unknown.
0x195EEC: Unknown.

0x195F10: FLOAT, unknown.
0x195F20: FLOAT, unknown.

0x19623B: Unknown.

0x1963F0: Unknown.
0x1963F4: Unknown.
0x1963F8: Unknown.
0x1963FC: Unknown.
0x196400: Unknown.
0x196404: Unknown.
0x196408: Unknown.

0x196410: Points to "defeated" text (Used in the 70 person timed free battle)
0x196414: Points to 0x277625 (0xA1A7), stuff right after the original "defeated" string.
0x196418: Points to 0x277628.
0x19641C: Points to 0x277631.
0x196420: Points to 0x277636.
0x196424: Points to 0x27763B.
0x196428: Points to 0x277640.
0x19642C: Points to 0x277645.
0x196430: Points to 0x27764E.
0x196434: Points to 0x277653.
0x196438: Points to 0x27765A.
0x19643C: Points to 0x277661.
0x196440: Points to 0x277668.
0x196444: Points to 0x277670.

0x196528: Unknown, crashes the game on the 70P. Timed F.B.

0x196540: FLOAT, messes with textures on the 70P. Timed F.B.
0x196550: FLOAT, messes with textures on the 70P. Timed F.B.

0x19656E: Unknown, crashes the game on the 70P. Timed F.B.
0x196570: Unknown.
0x196572: Unknown, crashes the game on the 70P. Timed F.B.
0x196574: Points to 0x2174A8 - Blank area
0x196578: Points to 0x212644 - Blank area
0x19657C: Points to 0x217494 - Blank area

0x196580: Points to 0x27768C (LOADNUM.SPR)
0x196584: Points to 0x277684 (sprite)
0x196588: Points to 0xAE0EC.
0x19658C: Suspicious word: "LDTD"
0x196590: Points to 0x7CA10.
0x196594: Points to 0xAE1C0.
0x196598: Points to 0x217598 - Blank area
0x19659C: Points to 0x172356.
0x1965A0: Points to 0x7CAFC.
0x1965A4: Points to 0x29C8D0.
0x1965A8: Points to 0x29C8D4.
0x1965AC: Points to 0x29C8D4.

0x1966CE to 0x1966D3: Posibble coordinates. Unknown.

0x196812: Possible coordinates. Unknown.
0x196814: Possible coordinates. Unknown.
0x196816: Possible coordinates. Unknown.
0x196818: Possible coordinates. Unknown.
0x19681A: Possible coordinates. Unknown.
0x19681C: Possible coordinates. Unknown.
0x19681E: Possible coordinates. Unknown.
0x196820: Possible coordinates. Unknown.

0x1968F2: Possible coordinates. Unknown.

==============================================================================================
OPTIONAL TARGET: EXTEND THE WIDTH FOR THE PHRASE "FOCUS HAND/LEG TRAINING", AT THE TRAINING 
SCREEN IN RYO'S ROOM.
==============================================================================================

0x1A9950: Suspicious word: "WAZ2"

0x1AA060: Points to "Focus" text.
0x1AA064: Points to 0x29E860, which points to "train moves equally" text.
0x1AA068: Points to 0x1CE654.
0x1AA06C: Points to 0x217CB4 - Blank area.
0x1AA070: Unknown.
0x1AA074: Points to 0x1B8300.
0x1AA078: Points to "on the" text.
0x1AA07C: Points to "Move." text.
0x1AA080: Points to 0x217CB6 - Blank area.
0x1AA084: Points to 0x217CB8 - Blank area.
0x1AA088: Points to 0x217CBA - Blank area.

0x1AA2F4: FLOAT, Y position of the box used in "Wish to train specific moves?".
0x1AA2F8: Possibly color/transparency of the box used in "Wish to train specific moves?".
0x1AA2FC: Points to 0x1717CC.
0x1AA300: Points to 0x1A7554.
0x1AA304: FLOAT, X position of the centered text in the Training screen, Ryo's Room.
0x1AA308: Points to 0x217BB4 - Blank area.
0x1AA30C: Points to 0x217CB4 - Blank area.
0x1AA310: FLOAT, unknown.
0x1AA314: FLOAT, unknown.

0x1AA430: Points to 0x217B24 - Blank area.
0x1AA434: FLOAT, unknown.
0x1AA438: FLOAT, unknown.
0x1AA43C: FLOAT, related to the second line on the centered text, Training screen, Ryo's Room.
0x1AA440: Points to 0x217CB0 - Blank area.
0x1AA444: FLOAT, Y position of the entire centered text block, Training Screen, Ryo's Room.
0x1AA448: Points to 0x217CB2 - Blank area.
0x1AA44C: Points to 0x213774 - Blank area.
0x1AA450: Points to 0x217DCE - Blank area.
TO BE CONTINUED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

0x1AB728: Suspicious word: "WZMD"

0x1AB738: Suspicious word: "WZMZ"

0x1AF7A6: Possible coordinates. Unknown.
Offset: -C010000
0x27399C: Text "RESUME2"
0x2739A4: Text ".SPR"
0x2739AC: Text "sprite"
0x2739B4: Text "RESUME3"
0x2739BC: Text "RESUME0"

0x27768C: Text "LOADNUM.SPR"

Text LDRYROOM: 276F6C = C286F6C

0x2984FC: Points to "sprite"

0x29AA64: Pointers to "DKTY"/"LDBUNKAD.GZ"
0x29AA6C: X/Y scale of the Antique Shop Loading name. CHANGED TO 0x0002.

0x29ABFC: Pointers to "JABE"/"LDABESYO.GZ"
0x29AC04: X/Y scale of Abe's Store Loading name. CHANGED TO 0x0002.

0x29ADF4: Pointers to "MA00"/"LDRYROOM.GZ"
0x29ADFC: X/Y scale of Ryo's Room Loading name. CHANGED TO 0x0002.


0x29B576: Possible info for the Resume file's help box.

0x29B580: (0x4C01) X position of the help text in the Resume File menu.
0x29B582: (0x9A01) Y position of the help text in the Resume File menu.
0x29B584: (0x0002) X scale of the help text in the Resume File menu.
0x29B586: (0x4000) Y scale of the help text in the Resume File menu.

0x29B5A8: Possible info for the Load screen's help box.

0x29B5B2: (0x3F01) X position of the help text in the Load screen.
0x29B5B4: (0x9A01) Y position of the help text in the Load screen.
0x29B5B6: (0x0002) X scale of the help text in the Load screen.
0x29B5B8: (0x4000) Y scale of the help text in the Load screen.

==============================================================================================
LOAD SCREEN STATUS: DATES FOUND AND CHANGED. DONE!
OPTIONAL: MOVE UPWARDS THE PERIOD AND THE COMMA.
PERIOD: It's in Y=100, Target: Move to Y=98
COMMA: Move 1 pixel up
==============================================================================================
0x29B5F8: (0x8C01) X position of File 1's disc number. CHANGE TO 0x7F01
0x29B602: (0x8C01) X position of File 2's disc number. CHANGE TO 0x7F01
0x29B60C: (0x8C01) X position of File 3's disc number. CHANGE TO 0x7F01

0x29B620: (0x0201) X position of Resume File's disc number. CHANGE TO 0xF400

0x29B63C: (0xEE01) X position of the comma in all files.
0x29B63E: (0xB501) X position of the month in all files. CHANGE TO 0xD301
0x29B640: (0xC001) X position for something unknown.
0x29B642: (0xCA01) X position of the period in all files. CHANGE TO 0xE601
0x29B644: (0xD801) X position of day's first digit in all files. CHANGE TO 0xAB01
0x29B646: (0xE301) X position of day's second digit in all files. CHANGE TO 0xB601

//#FROM 29B7A0 TO 29B7BB ARE THE INITIALS OF LANGUAGES (USEFUL TO REMOVE OTHER LANGUAGES AND KEEPING ONE, BUT JUST FOR SOME FILES) AND OTHER SPR FILENAMES.

//#FROM 29B7D4 TO 29B7DB ARE SOUND FILENAMES.

//#FROM 29B7F4 TO 29B807 ARE THE FILENAMES FOR TXT_XX_X.

//FROM 29BEB0 TO 29C024 ARE POINTERS FOR SOMETHING UNKNOWN.

//#FROM 29C5C8 TO 29C5D7 IS SOMETHING WEIRD.

//#FROM 29C6CC TO 29C7B3 ARE COMBAT FILE NAMES.

//#FROM 29E19C TO 29E1AB ARE VOICE DATA POINTERS.

```
