# Changing Fighting Style

**Steps:**

1. Open the `1ST_READ.BIN` file in a hex editor.
2. Search for `EN_%s.BIN`.
3. Find the ID reference that you want to change with another one.
4. Find the relevant EN_XXX(X).BIN file [where "XXX(X)" is the ID of the fighting style that you want to use] in one of the area folders found in the path "DATA/SCENE/XX". Copy that file and paste it in the area folder that you want to load (required that in this area folder is the character that has been assigned with the fighting style of your choice).

*Note: This method currently works only during "Free Battles". If this method will be attempted while on "Practice", then Shenmue will freeze.*

Here is the list of the (58) fighting styles references:

| **Character**      | **ID** | **Notes**                    |
| ------------------ | ------ | ---------------------------- |
| Bob Dickson        | BOB    |                              |
| Chai               | CHAI   |                              |
| Chai               | CHAI2  |                              |
|                    | CHALY  |                              |
|                    | CHARY  |                              |
|                    | COMM1  |                              |
|                    | COMM4  |                              |
|                    | COMM5  |                              |
| dummy file(?)      | DEKU   |                              |
| Dick Philips       | DICK   |                              |
| Enoki Akio         | ENOKI  |                              |
| Fukuhara Masayuki  | FUKU   |                              |
| Fukuhara Masayuki  | FUKU2  |                              |
| Goro Mihashi       | GORO   |                              |
| Tadashi Hama       | HAMA   |                              |
| Harry Thompson     | HARRY  |                              |
| Yoshihide Hatanaka | HATA   |                              |
|                    | HOGAN  |                              |
| Jones Henders      | JONES  |                              |
| Guizhang Chen      | KISY2  | Identical with KISY3, KISYO. |
| Guizhang Chen      | KISY3  | Identical with KISY2, KISYO. |
| Guizhang Chen      | KISYO  | Identical with KISY2, KISY3. |
| Takuya Maruyama    | MARU   |                              |
|                    | MBOS1  |                              |
| Shingo Murasaki    | MURA   |                              |
| Ko Muratani        | MURA2  |                              |
| Tetsuya Nagashima  | NAGAS  |                              |
| Minoru Okayasu     | OKA    |                              |
| Paulo McCoy        | PAURO  |                              |
|                    | PEDR2  |                              |
| Pedro Warren       | PEDRO  |                              |
| Robert Wells       | RBERT  |                              |
| Ryo Hazuki         | RYOU   |                              |
| Satoshi Nagata     | SATOS  |                              |
| Masato Wada        | SATS2  |                              |
| Takeshi Sera       | SERA   |                              |
| Smith Bradley      | SMITH  |                              |
|                    | TAKO1  |                              |
|                    | TAKO2  |                              |
|                    | TAKO3  |                              |
|                    | TAKO4  |                              |
|                    | TAKO5  |                              |
| Terry Ryan         | TERRY  |                              |
|                    | TIME1  |                              |
|                    | TIME2  |                              |
|                    | TIME3  |                              |
|                    | TIME4  |                              |
|                    | TIME5  |                              |
| Tony Abrams        | TONY   |                              |
| Naomichi Tsukamoto | TSUKA  |                              |
|                    | WARU1  |                              |
|                    | WARU2  |                              |
|                    | ZAKO1  |                              |
|                    | ZAKO2  |                              |
|                    | ZAKO3  |                              |
|                    | ZAKO4  |                              |
|                    | ZAKO5  |                              |
|                    | ZAKO6  |                              |