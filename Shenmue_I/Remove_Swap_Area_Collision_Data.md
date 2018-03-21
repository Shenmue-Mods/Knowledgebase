# Remove/Swap Area Collision Data

![](http://i.imgur.com/XWta03g.jpg)

This is a tutorial on how to remove the area collision data of any area of Shenmue, or, how to swap that data between two areas. [[Video Demonstration](https://youtu.be/6zkTar6CDBE)]

**Steps**:

- Open with a hex-editor the `MAPINFO.BIN` file of the area you want. In our case, we will work with the file of Dobuita, found in folder "SCENE/0X/D000" (0X = 01 or 02 or 03 ...).

- Search (`CTRL+F`) for "COLS" and find the first reference. Start highlighting from COLS and go all the way down ...

![](http://i.imgur.com/3sFf0AZ.png)

- ... until you find the first reference of "REGD". Stop exactly before REGD (that is not select any part from REGD or after it).

![](http://i.imgur.com/kx7SOuo.png)

- ... With all these lines being highlighted, press the Delete (`DEL`) button in your keyboard.

![](http://i.imgur.com/5YtNXT4.gif)

- Save the modified file. [Proceed to the necessary steps to create a self-bootable image file.]
***
**How to retain the vertical collision(?) (or the height) data (and everything else, except the horizontal collision data)**:

- With a hex editor (for this example, the hex editor named [HxD](https://en.wikipedia.org/wiki/HxD) has been used), open the file where the collision data is stored (usually the `MAPINFO.BIN` file)

- Search (`CTRL+F`) for the keyword COLS

- Look for the keyword COLI (which is located some bytes after the COLS)

- Take note of the 4 bytes after COLI. You will see something like e.g.: `D0 54 00 00`. These four bytes (or word) are in the Little Endian format. Convert them to the Big Endian format (in the previous example, the value `D0 54 00 00` will become `00 00 54 D0` when converted to the Big Endian format) and take note of that value.

- Place the cursor 8 bytes after the offset of COLI. Press `CTRL+E` to select a block of bytes. Select the radio button of "Length" and in the relevant text area write the aforementioned 4 bytes (as they are converted in the Big Endian format), then press `OK`. Press the `DEL` button.

- Overwrite the aforementioned 4 bytes from whatever value they are to the new value: `00 00 00 00`.

- Find how many bytes the COLS data section is. There are two ways to do this:
  1. Take note of the 4 bytes after COLS. You will see something like e.g.: `1C 55 01 00`. These 4 bytes (or word) are in the Little Endian format.
     1. Convert them to the Big Endian format (in the previous example, the value `1C 55 01 00` will become `00 01 55 1C` when converted to the Big Endian format) and take note of that value.
     2. Open a calculator which does hexadecimal computations. Subtract the value of the 4 bytes after COLS with the value of the 4 bytes after COLI
        * [but first, both byte values should be converted in the Big Endian format; for the previous examples, you would need to subtract `00 01 55 1C` with `00 00 54 D0`, and the result would be `00 01 00 4C` (that is `00 01 55 1C` minus(-) `00 00 54 D0` equals(=) `00 01 00 4C`)].
     3. You need to convert the result of the previous subtraction to the Little Endian format (for the previous example, the value `00 01 00 4C` will become `4C 00 01 00` when converted to the Little Endian format).
     4. Overwrite the 4 bytes after COLS with the converted to the Little Endian format value that you found as the result from the substraction.
  2. Place the cursor at the offset of COLS, continuously press down the left mouse button from that offset and move the cursor towards the bottom of the file until you reach the offset of REGD.
     1. Look for the "Length:" text at the bottom-center of the hex editor's window; it reports the length of the bytes you have selected.
     2. The value of the length is in the Big Endian format, so it needs to be converted in the Little Endian format [as explained how to do this previously].
     3. Overwrite the 4 bytes after COLS with the converted to the Little Endian format value that you saw at the "Length:" text.


***

**About Swapping the clipping information between two MAPINFO.BIN files of two different areas**:

- The only difference from the above steps, is to not Delete the highlighted part of the file, but Cut (`CTRL+X`) it and move it to the other file that you want to swap the clipping information with.
- That means you have to replace the "COLS ... (until before REGD)" lines of the one file, with the "COLS ... (until before REGD)" lines of the other file.

***
This tutorial is confirmed to work on the following maps in both Retail Shenmue and Beta Shenmue:
```
D000 - Retail Dobuita
JD00 - Retail Sakuragaoka
JD01 - Beta Sakuragaoka
JHD0 - Hazuki Residence
JOMO - Ryo's House
JU00 - Retail Yamanose
JU01 - Beta Yamanose
MFSY - Harbor
MKSG - Old Warehouse District
DYKZ - Nagai Industries
DURN - Lapis Fortune Teller
DTKY - Maeda Barber Shop
DSLT - Slot House
DSLI - Bar Linda
DSKI - Global Travel Agency
DRSA - Russiya China Shop
DRME - Manpukuken Ramen
DPIZ - Bob's Pizzaeria
DKTY - Antique Shop
DKPA - Nana's Karaoke Bar
DJAZ - MJQ Jazz Bar
DGCT - You Arcade
DCHA - Ajiichi
DBYO - Bar Yokosuka
DBHB - Heartbeats Bar
TATQ - Tattoo Parlor
JABE - Abe Store Candy Shop
MKYU - Harbor Lounge
YDB1 - Hazuki Basement
D001 - Wish Road
```
