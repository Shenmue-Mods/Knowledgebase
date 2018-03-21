# Remove Collision Data

It works pretty much the same as the method for *Shenmue I*, except that you have to look for FLDD instead of COLS. So open the `mapinfo.bin` of the area you want to visit without collision data in your favorite hex editor. 

Search for FLDD and start marking the code from there.

![](http://i.imgur.com/Ew2pIZQ.jpg)

You wanna go down all the way until you reach DOOR. If you want to modify a map that doesn't have doors you'll have to look for REGD. It's a *huge* portion of the code, about 80-90%, so you'll have to go almost to the end of it. 

![](http://i.imgur.com/oYmbb1t.png)

Once it's removed just save and build your image with the modified map file.

***

Like in *Shenmue I* there are some downsides:

* The collision data of the floor is removed too, so Ryo will stay at the same height as when the area is loaded, ignoring stairs or slopes. Most of the NPCs will be gone, with some exceptions.
* Objects like signs and the vending and toy capsule machines still work.
* Doors and elevators work but warping points mostly don't, so you won't be able to easily travel to the next area.
* A major downside to *Shenmue I* is that there is no beta where you could just load any area you want. On the plus side however you can save anywhere and just switch between the regular game for traveling and the modded one for exploration. Pretty cumbersome but better than nothing.

***

Removing the collision data from the more minor shops works differently. You'll need to look through the map folder where the shops are located and pick out the corresponding PKS file. Now open it with the [IPAC Browser](http://sourceforge.net/projects/shenmuesubs/files/IPAC%20Browser/) and extract the COLIFELD file. Open it with your hex editor, remove all the code except for the FLDD line in the beginning, save it and inject the modified file back into the PKS.

![](http://i.imgur.com/54HhjZL.png)

***

Below is a compiled list of what areas the map folders are linked to. This list is not 100% complete yet, but it covers all the major areas. Areas that are just for cutscenes or QTEs are left out.

```
Aberdeen
AB00 = Beverly Hills Wharf
AK00 = Fortune's Pier
AK09 = Fortune's Pier Copy
AKS0 = Forturne's Eatery
AKS1 = Blue Sky
AKTx = Gambling Warehouses (x=0-3)
AKY0 = Warehouse F
AR01 = Worker's Pier Arrival Area
AR02 = Worker's Pier
AR03 = Queen's Street
AR09 = Queen's Street Copy
ARA0 = Bar Swing
ARC0 = Pigeon Cafe
ARM0 = Hong Kong Souveniers
ARSF = Rooftop Fight
ARZ0 = General Store

Wan Chai
WB00 = Scarlet Hills
WB01 = Man Mo Temple
WBBK = Airing out books
WE00 = Golden Qr.
WECF = Moon Cafe
WEG0 = Pine Game Arcade
WEM1 = S.I.C. Pool Hall
WES1 = Slot House W
WET0 = Tomato Convenience Store
WK00 = South Carmain Qr.
WK09 = South Carmain Qr. Copy
WKA0 = Yan Tin Apartments
WN00 = Lucky Charm Qr.
WR00 = White Dynasty Qr.
WRS2 = Bar Liverpool
WS00 = Green Market Qr.
WS09 = Green Market Qr. Copy
WSG1 = Green Market Qr. (Guang Martial Arts School)
WSY0 = Come Over Guest House
WT00 = Wise Mens Qr.
WTA0 = Da Yuan Appartments

Kowloon
Q100 = Thousand White Qr.
Q109 = Thousand White Qr. Copy
Q200 = Stand Qr.
Q300 = Dimsum Qr.
QA00 = Three Birds, Tea Break, Dimsum & Dancing Dragon Bldg.
QA11 = Three Birds Roof
QA22 = Slot House K
QAE1 = Three Birds & Tea Break Bldg. 1F
QAE6 = Three Birds & Tea Break Bldg. 6F
QAW1 = Dancing Dragon & Dimsum Bldg. 1F
QAW6 = Dancing Dragon & Dimsum Bldg. 6F
QB00 = Great View Bldg.
QBAA = Great View Herbs
QC00 = Thousand White Bldg.
QC01 = Thousand White Bldg. 1F
QC06 = Thousand White Bldg. 6F
QCAE = Thousand White Warehouse
QD00 = Ghost Hall & God of Wealth Bldg.
QD01 = Ghost Hall & God of Wealth Bldg. 1F
QDKJ = Five Stars Corp. (Yuanda Zhu's Room)
QE00 = Moon Child, Golden Flower & Black Heaven Bldg.
QE01 = Moon Child, Golden Flower & Black Heaven Bldg. 1F
QE06 = Moon Child, Golden Flower & Black Heaven Bldg. 6F
QEDJ = Yuan's Room
QEEC = Kai's Room
QEHI = Moon Child Orphanage
QF00 = Yellow Head Bldg.
QF01 = Yellow Head Bldg. 1-2F
QF02 = Yellow Head Bldg. 3-4F
QF06 = Yellow Head Bldg.
QF39 = Big Ox Bldg. 40F
QF40 = Dou Niu's Room
QFHG = Hang On Room
QFRR = Yellow Head Rooftop
QGBT = Blue Dragon Garden
QJBT = Phoenix Bldg.
QKBT = Big Ox Bldg. B5F ?
QLBT = Black Heaven Bdlg.
QR00 = Dragon Street
QR09 = Dragon Street Copy
QRC0 = Huang's Room
QRR0 = Ren's Hideout
QSFA = Former Barracks
QSFB = Small Dragon Garden
QSFC = Star Gazing Point
QSFD = Construction Base
QT09 = Thunder House
QTB1 = Former Factory Site
QTB2 = Old Government Office Site
QTB3 = Thunder House Copy
QTB4 = Fighting Place
QUG0 = Underground

Guilin 
KES1 = Stone Pit
KMZ1 = Forest
KMZ2 = Forest 2 
KMZ3 = Forest 3
KMZ4 = Forest 4
KRF1 = Kowloon Intro
KRH1 = Langhuishan
KSH1 = Shenhua's House
KWM1 = Green Field
KWW1 = Path Through a Wood
KWW4 = Cloud Bird Trail
```

Credits to [BlueMue](http://shenmuedojo.net/forum/viewtopic.php?f=37&t=49248) (from Shenmue Dojo).