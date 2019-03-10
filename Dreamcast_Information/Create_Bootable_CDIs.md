# Create Bootable CDIs

1. Extract all contents of the original CDI image to a folder
(e.g. using [GDROM Explorer](https://japanese-cake.livejournal.com/tag/gdrom%20explorer)).

    1.1. Extract the `IP.BIN` file to that folder, too.

2. Download [`binhack32.exe`](https://sourceforge.net/projects/binhack32/) and save it to that folder.

3. Make your desired modifications to the extracted files.

4. Open a Command Prompt in that folder and run `binhack32.exe`.

5. It will ask for three things as you can see in bold text below. You should type the relevant inputs as shown:

    5.1. **Enter name of binary:** `1ST_READ.BIN`
    
    5.2. **Enter name of bootsector:** `IP.BIN`
    
    5.3. **Enter msinfo value:** `11702`

6. Download [BootDreams](https://code.google.com/archive/p/bootdreams/downloads) and install it.

7. Run BootDreams:

    7.1. Click the *Browse* button and select the folder with the extracted/modified files.
    
    7.2. For *Disc format* select *Audio/Data* (unless you specifically need *Data/Data*, like with e.g. `Shenmue II`).
    
    7.3. Click *Process*.
