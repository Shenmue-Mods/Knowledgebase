# Remove Warp Zone from Tomato Convenience Store

Even if you remove the COLS data from The Tomato Convenience Store, the warp zone still exists for the door and surrounding perimeter.

Described here: [Change Loaded Area When Leaving Tomato Convenience Store]()

To remove the warp zone needs a lot of investigation, so an approachable hack is to swap the map with the Abe Candy Shop in Sakuragaoka.

**Steps**:

1. Load up ROOT:/SCENEXX/DCBN/mapinfo.bin into a hex editor
2. Load up ROOT:/SCENEXX/JABE/mapinfo.bin into a hex editor
3. In the DCBN map info, highlight all of the hex from the beginning of the code to one bit before ECAM.
4. Delete that code.
5. In the JABE mapinfo, highlight all of the hex from the beginning of the code to one bit before ECAM.
6. Copy that code.
7. Paste/insert that code at offset `00000000000`/beginning of file in the DCBN mapinfo.
8. Build cdi/gdi.
9. Test with AREA= DCBN ENTRY= 00


This has the following issues:
- You replace all of the NPCS with null values so no one will be outside.
- The automatic door will now be openable via hand and transport you to Sakuragaoka.
- The Tomato workers are replaced with the Abe Store lady who will be in the middle of an item rack due to her placement in the Abe Store.

[[Video Demonstration](http://youtube.com/watch?v=8DNYYXVmAQY)]