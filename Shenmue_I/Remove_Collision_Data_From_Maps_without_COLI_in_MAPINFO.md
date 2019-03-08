# Remove Collision Data From Maps without COLI in MAPINFO

This page will show you how to remove collision data from a map in *Shenmue I* that does not have its clipping in `MAPINFO.BIN`.

Specifically for Liu Barber and Hair Salon.
1. Open up IPAC Editor
2. Extract the file called `COLI` from the `MPK00.PKS`.
3. Hexedit that file and remove everything besides COLS at the beginning 
4. Inject it back into the PKS and you're done.

[[Video Demonstration](https://www.youtube.com/watch?v=En8n_npgIEU)]

Credits to [BlueMue](https://shenmuede.wordpress.com/).
