# Change Loaded Area When Leaving Tomato Convenience Store

When you remove the COLS data from The Tomato Convenience Store (DCBN), the warp point for the door still exists. This warp point does not only exist at the door but also exists all around the store.

If you walk through any of the walls, you will warp back into Dobuita (D000).

To change which area you warp to, perform the following:
*Note: this is written as if you have removed the COLS data from the mapinfo.bin. The hex placements will change if you didn't.*

Open up ROOT:/SCENEXX/DCBN/mapinfo.bin in a hex editor.

1. Do a search for D000
   * there should be an instance of it at `27C1C` - `27C1F` offsets.
2. Replace that value with any Map Code.

This is tested with replacing D000 with DCBN. Every time you walk through the door or through a wall, you go back into the Tomato Store.