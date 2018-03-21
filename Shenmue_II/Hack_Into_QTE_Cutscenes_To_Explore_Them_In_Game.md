# Hack Into QTE Cutscenes To Explore Them In Game

This tutorial will lay out the basics of hacking into QTE cutscene areas in *Shenmue II* to make them fully playable/walkable areas.

The Ryo & Ren Handcuff Jump QTE scene from Disc 3 will be used.

1. Dumped copy of *Shenmue II* Disc 3
2. Hex Editor ( HxD recommended)
3. VMU Explorer for Windows (Can be used on Linux with WINE if needed)
   * http://bswirl.kitsunet.org/tools/download/vmuexplorer.rar?lg=en&menu=on
4. Tools to compile disc
   * (binhack32, bootmake, etc)

Since we are using the same X/Y coordinates between both levels, in this very basic mod, we need to make sure that the floor level we save on is at the same height as where we want to be in the map we are going to hack into, so we can walk around in it at a normal height and not be super high in the air or underground, etc.

Here is how we can do it (using NULLDC & NULLDC VMUs as a reference):

1. Load up an ISO of *Shenmue II* Disc 3 and go to the Three Birds Building.
2. Go to floor 3 of the Three Birds Building and save the game to slot 1 (doesn't matter which slot, but we are using slot 1 as an example here)
3. Close the game and open up that virtual VMU file in a hex editor.
4. Search the hex code of the file for the SCENE code of the original map you saved in, this case being Three Birds Building which is QAE1
5. Replace QAE1 with QAXX
6. Save the VMU file
7. Open the VMU file in VMU Explorer and select the option FIX CRC
8. Save the VMU file
9. Close the VMU file and close VMU Explorer
10. In the dumped *Shenmue II* ISO go to SCENE/03/QAXX
11. Open up `mapinfo.bin` in a hex editor
12. Remove the FLDD --|DOOR sector as stated in: [Remove colision data from maps]()
13. Save the file
14. Compile the disc

[[Video Demonstration](http://youtube.com/watch?v=npMKxiUj4XE)]