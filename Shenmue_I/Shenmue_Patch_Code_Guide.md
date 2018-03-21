# Shenmue Patch Code Guide

Shenmue Patch Code Guide
Shenmue I (Sega Dreamcast)
Version 1.10
By SSJ2 Dark

-------------------------------------------------------------------------------
Table of Contents:                                                             
-------------------------------------------------------------------------------

    For your browsing convenience, I've created a shortcut feature within this
  guide. Simply press Ctrl + F, and type in the character code next to the
  desired chapter. You'll be brought straight to that section!

    1. Preface (P1)
    2. Copyright Information (I2)
    3. Version History (V3)
    4. Hexadecimal Review (H4)
    5. The Basics of Codes (T5)
    6. General Codes (G6)
    7. Menu Item Codes (I7)
    8. Collectable Item Codes (I8)
    9. Cassette Codes (I9)
    10. Move Codes (M10)
    11. Value List Codes (V11)
    12. Custom Code Tutorial (T12)
    13. Future Updates (U13)
    14. Thanks (T14)

-------------------------------------------------------------------------------
Preface (P1)                                                                   
-------------------------------------------------------------------------------

    Welcome to the Shenmue Patch Code Guide, a full listing of unencrypted and
  encrypted codes for the greatest video game series ever: Shenmue! I've worked
  long and hard to uncover some elusive codes to make your gaming experience
  better. Whether you just want to "trade" in some of those slot machine prizes
  for Passport figures, or you want to completely open up the game, this guide
  will surely be of use to you. To use these codes, you'll need a game
  enhancing device such as GameShark or Code Breaker, DCcrypt, and a basic
  understanding of hex base. If you don't have the latter, don't worry. There
  is a section outlining hex base that will get you going in no time. Enjoy!

  Note: DCcrypt can be found at www.angelfire.com/planet/ssj2dark/DCcrypt.zip

-------------------------------------------------------------------------------
Copyright Information (I2)                                                     
-------------------------------------------------------------------------------

    This FAQ is copyright 2006 SSJ2 Dark (Jesse McCaffrey), and is intended for
  free public use. It may be printed, provided that it has not been modified
  with the intent to disguise the identity of the original author. Under no
  circumstances should anyone generate profits with this guide, nor should I
  find this document on any unauthorized website. Stealing other people's work
  is an insult to authors everywhere that work hard on projects, and is a
  federal and moral crime.

-------------------------------------------------------------------------------
Version History (V3)                                                            
-------------------------------------------------------------------------------

  V 0.30 [12-28-05] Began patch code search for codes. Expanded Collectables
                    codes, uncovered cassettes and move scrolls.
  V 0.60 [01-04-06] Refined codes, removed errors from address misallocations.
  V 0.90 [07-31-06] Developed code list into guide. Added explanations and
                    tutorials to make codes fully accessible.
  V 1.00 [08-02-06] First version of guide complete.
  V 1.10 [12-20-06] Fixed code errors, revamped customization section.

-------------------------------------------------------------------------------
Hexadecimal Review (H4)                                                         
-------------------------------------------------------------------------------

    Game enhancing codes generally use hexadecimal (hex) base for all numbers,
  including addresses and values. To use codes effectively, you should
  understand hex. The decimal system is base ten; once a digit is increased
  ten times, the next digit increases by one. The hexadecimal system is base
  sixteen; once a digit is increased sixteen times, the next digit increases by
  one. The extra six "numbers" in hex are the letters A-F. This is a
  progression table comparing sixteen decimal and hexadecimal values:

  Decimal | Hexadecimal
  ---------------------
  1       | 1
  2       | 2
  3       | 3
  4       | 4
  5       | 5
  6       | 6
  7       | 7
  8       | 8
  9       | 9
  10      | A
  11      | B
  12      | C
  13      | D
  14      | E
  15      | F
  16      | 10

    The most convenient method to convert decimal to hex is by using the basic
  Calculator program on your computer. Enable the Scientific option, then type
  in your decimal value, and enable hex mode. Your decimal number will be
  converted to a hexadecimal value. There are also freeware programs such as
  Hexit available, if you prefer.

-------------------------------------------------------------------------------
The Basics of Codes (T5)                                                        
-------------------------------------------------------------------------------

    Before you begin executing lines of code with your game enhancer of choice,
  it's a good idea to understand how those sequences of numbers and letters
  make things happen in your game. Similar to a computer, the memory for a
  video game is comprised of thousands of addresses, each holding a particular
  two bit value, which I often call 'xx'. The range of xx is from 0 to FF, or
  in decimal, 0 to 255. Game enhancing codes overwrite these values by
  specifying a certain address and a value to be written to that address. A
  template for these types of codes (while unencrypted) looks like this:

    ttaaaaaa zzyyxxww (Address Format)
    
    Where tt denotes the code type, aaaaaa is the starting address the code
  will modify, and zzyyxxww contains the quantities to be written (in hex
  base). An address line (ttaaaaaa) must be immediately followed by a quantity
  line (zzyyxxww), unless it is an advanced type (04 or higher). For our
  purposes, basic code types will suffice. These code types used are type 00,
  01, and 02. Following is a table comparing code types and abilities:

  Type |     Example     | Effect
  ------------------------------------------------------------------
  00   |00aaaaaa 000000xx| Assigns xx to aaaaaa
  ------------------------------------------------------------------
  01   |01aaaaaa 0000yyxx| Assigns xx to aaaaaa and yy to aaaaa(a+1)
  ------------------------------------------------------------------
  02   |02aaaaaa zzyyxxww| Assigns ww to aaaaaa
       |                 |         xx to aaaaa(a+1)
       |                 |         yy to aaaaa(a+2)
       |                 |         zz to aaaaa(a+3)

    At first, type 01 and 02 codes can be difficult to understand. In these
  codes, the quantity line possesses two or four values (xx and yy for 01 or
  ww, xx, yy, and zz for 02). Each of these values is written to a different
  address. The first value (xx for 01 or ww for 02) is written to the address
  aaaaaa. The second value (yy for 01 or xx for 02) is written to the address
  aaaaa(a+1), the address right after the address in the code. The third and
  fourth values for type 02 work similarly, affecting subsequent addresses. An
  important rule to remember is that the quantities for type 01 and 02 codes
  follow right to left, in that values on the right affect the first addresses,
  and values on the left affect the latter addresses.

    One aspect of codes that can be confusing is code encryption and
  decryption. For one reason or another, many game enhancers choose to encrypt
  their code lines, meaning that the lines themselves are meaningless, and give
  little insight as to what they do. The process of encryption basically
  reassigns values based on the sequence and identity of the original
  characters in the code. A useful rule is that unencrypted codes always begin
  with a 0, while encrypted codes do not. For the Sega Dreamcast, there are two 
  main choices for game enhancers: the GameShark, and the Code Breaker. The 
  GameShark requires encrypted codes, and their encryption method is quite
  complicated. You won't be encrypting codes in your head by adding 1 to every
  value. Fortunately for us, a tool has been created called DCcrypt. This nifty 
  utility allows us to encrypt and decrypt codes for the GameShark CDX, giving
  the average gamer access into the code realm. Operation of DCcrypt is as
  simple as type and click, with no settings to worry about. However, if you
  own a Code Breaker or other rare game enhancing device, you don't need to
  encrypt your codes. Since the GameShark/Action Replay is the most common game
  enhancer, I have written this guide assuming that you are using one. If
  you're lucky enough to have a Code Breaker or Xploder, skip the steps
  concerning encryption.

    Keep in mind the laws of game hacking: use codes carefully, in small
  groups, and check carefully before saving. In rare cases, an improperly
  entered code can have disastrous effects, but the threat is minimized if you
  only save when certain that the desired effect is the only change in the
  game. Only enable a few codes at a time to prevent interference and a halted
  load. Also, when deciding quantities and customizing codes, always try to
  hack within the limits of the game. Giving Ryo 255 Phoenix Mirrors may seem
  harmless, but you may run into a problem later in the game. Your goal should
  be to create the illusion that your game was never hacked at all. 

    Finally, it is good to note that in Shenmue, subsequent addresses contain
  information for similar items. For example, the addresses for all the Sonic
  collectables are right next to each other, and the addresses for all the move
  scrolls increase by two for each scroll. These patterns can be useful when
  you know the address of one item, but want to modify a similar item. Say you
  have the starting address for Hand moves (aaaaaa), but want to modify Elbow
  Assault, the fourth hand move. Knowing that addresses for moves increase by
  two for each move, you can deduce that the address for Elbow Assault is
  aaaaa(a + 2*(4-1) = a + 6), that is, six addresses after the starting
  address. This is the basic concept for custom code creation; advancing from
  a known address until the address for the item of interest is found.

-------------------------------------------------------------------------------
General Codes (G6)                                                              
-------------------------------------------------------------------------------

* (M) Code [Must be entered to allow use of other codes!]

  GameShark
  22C5F54A 00000002

  Address Format
  0B400000 00000002

* Funds Modifier

  GameShark
  2A27ADC8 xxxxxxxx

  Address Format
  02220A38 xxxxxxxx

* Token Modifier

  GameShark
  1C74D81C xxxxxxxx

  Address Format
  02220A3C xxxxxxxx

-------------------------------------------------------------------------------
Menu Item Codes (I7)                                                            
-------------------------------------------------------------------------------

* Quest Items

  GameShark
  1E905818 000000xx
  1E9C5818 000000xx
  1E985818 000000xx
  1EA45818 000000xx
  1EA05818 000000xx
  1EAC5818 000000xx
  1EA85818 000000xx

  Address Format
  00221A85 000000xx
  00221A86 000000xx
  00221A87 000000xx
  00221A88 000000xx
  00221A89 000000xx
  00221A8A 000000xx
  00221A8B 000000xx

* Saturn Games

  GameShark
  1E205818 000000xx
  1E2C5818 000000xx

  Address Format
  00221AA9 000000xx
  00221AAA 000000xx

* Photographs

  GameShark
  1EB45818 000000xx
  1EB05818 000000xx
  1EBC5818 000000xx
  1EB85818 000000xx
  1EC45818 000000xx
  1EC05818 000000xx
  1ECC5818 000000xx
  1EC85818 000000xx
  1ED45818 000000xx

  Address Format
  00221A8C 000000xx
  00221A8D 000000xx
  00221A8E 000000xx
  00221A8F 000000xx
  00221A90 000000xx
  00221A91 000000xx
  00221A92 000000xx
  00221A93 000000xx
  00221A94 000000xx

* Move Scrolls

  GameShark
  1ED05818 000000xx
  1ED85818 000000xx
  1EE05818 000000xx
  1EE85818 000000xx
  1EF05818 000000xx
  1EF85818 000000xx
  1E005818 000000xx
  1E085818 000000xx
  1E105818 000000xx
  1E185818 000000xx
  1E245818 000000xx

  Address Format
  00221A95 000000xx
  00221A97 000000xx
  00221A99 000000xx
  00221A9B 000000xx
  00221A9D 000000xx
  00221A9F 000000xx
  00221AA1 000000xx
  00221AA3 000000xx
  00221AA5 000000xx
  00221AA7 000000xx
  00221AA8 000000xx

* Maps

  GameShark
  1E385818 000000xx
  1E445818 000000xx
  1E405818 000000xx
  1E4C5818 000000xx
  1E485818 000000xx
  1E545818 000000xx
  1E505818 000000xx
  1E5C5818 000000xx

  Address Format
  00221AAF 000000xx
  00221AB0 000000xx
  00221AB1 000000xx
  00221AB2 000000xx
  00221AB3 000000xx
  00221AB4 000000xx
  00221AB5 000000xx
  00221AB6 000000xx

* Trip Fliers

  GameShark
  1E305818 000000xx
  1E3C5818 000000xx

  Address Format
  00221AAD 000000xx
  00221AAE 000000xx

* Winning Can Stock

  GameShark
  1F9C5818 000000xx

  Address Format
  00221AC6 000000xx

* Shenmue Snacks

  GameShark
  1F885818 000000xx
  1F945818 000000xx
  1F905818 000000xx

  Address Format
  00221AC3 000000xx
  00221AC4 000000xx
  00221AC5 000000xx

* Kitten Food

  GameShark
  1E705818 000000xx
  1E7C5818 000000xx
  1E785818 000000xx
  1F845818 000000xx
  1F805818 000000xx
  1F8C5818 000000xx

  Address Format
  00221ABD 000000xx
  00221ABE 000000xx
  00221ABF 000000xx
  00221AC0 000000xx
  00221AC1 000000xx
  00221AC2 000000xx

* Household Items

  GameShark
  1E585818 000000xx
  1E645818 000000xx
  1E605818 000000xx
  1E6C5818 000000xx
  1E685818 000000xx
  1E745818 000000xx

  Address Format
  00221AB7 000000xx
  00221AB8 000000xx
  00221AB9 000000xx
  00221ABA 000000xx
  00221ABB 000000xx
  00221ABC 000000xx

-------------------------------------------------------------------------------
Collectables Codes (I8)                                                         
-------------------------------------------------------------------------------

* Complete Collection

  GameShark
  16755819 E06B1041
  24943CAD 00000000

  Address Format
  02221CBC zzyyxxww
  02221CC0 zzyyxxww
  02221CC4 zzyyxxww
  02221CC8 zzyyxxww
  02221CCC zzyyxxww
  02221CD0 zzyyxxww
  02221CD4 zzyyxxww
  02221CD8 zzyyxxww
  02221CDC zzyyxxww
  02221CE0 zzyyxxww
  02221CE4 zzyyxxww
  02221CE8 zzyyxxww
  02221CEC zzyyxxww
  02221CF0 zzyyxxww
  02221CF4 zzyyxxww
  02221CF8 zzyyxxww
  02221CFC zzyyxxww
  02221D00 zzyyxxww
  02221D04 zzyyxxww
  02221D08 zzyyxxww
  02221D0C zzyyxxww
  02221D10 zzyyxxww
  02221D14 zzyyxxww
  02221D18 zzyyxxww
  02221D1C zzyyxxww
  02221D20 zzyyxxww
  02221D24 zzyyxxww
  02221D28 zzyyxxww
  02221D2C zzyyxxww
  02221D30 zzyyxxww
  02221D34 zzyyxxww
  02221D38 zzyyxxww
  02221D3C zzyyxxww
  02221D40 zzyyxxww
  02221D44 zzyyxxww
  02221D48 zzyyxxww
  02221D4C zzyyxxww
  02221D50 zzyyxxww
  02221D54 zzyyxxww
  02221D58 zzyyxxww
  02221D5C zzyyxxww
  02221D60 zzyyxxww

-------------------------------------------------------------------------------
Cassette Codes (I9)                                                             
-------------------------------------------------------------------------------

* Cassette Collection

  GameShark
  1274D819 bbyyaaxx
  1384D819 bbyyaaxx
  1394D819 bbyyaaxx
  13A4D819 bbyyaaxx
  13B4D819 bbyyaaxx
  13C4D819 bbyyaaxx
  13D4D819 bbyyaaxx
  13E4D819 bbyyaaxx
  13F4D819 bbyyaaxx
  1304D819 bbyyaaxx
  1314D819 bbyyaaxx
  1324D819 bbyyaaxx
  1334D819 bbyyaaxx
  134C1819 bbyyaaxx

  Address Format
  02221DBC bbyyaaxx
  02221DC0 bbyyaaxx
  02221DC4 bbyyaaxx
  02221DC8 bbyyaaxx
  02221DCC bbyyaaxx
  02221DD0 bbyyaaxx
  02221DD4 bbyyaaxx
  02221DD8 bbyyaaxx
  02221DDC bbyyaaxx
  02221DE0 bbyyaaxx
  02221DE4 bbyyaaxx
  02221DE8 bbyyaaxx
  02221DEC bbyyaaxx
  01221DF2 bbyyaaxx

  Note: aa and bb refer to Cassette Values, the identity of the cassette, while
  xx and yy refer to the quantity of that particular cassette.

-------------------------------------------------------------------------------
Move Codes (M10)                                                                
-------------------------------------------------------------------------------

* Hand Move Proficiencies

  GameShark
  1A94D818 00yy00xx
  1AA4D818 00yy00xx
  1AB4D818 00yy00xx
  1AC4D818 00yy00xx
  1AD4D818 00yy00xx
  1AE4D818 00yy00xx
  1AF4D818 00yy00xx
  1A04D818 00yy00xx
  1A141818 000000xx

  Address Format
  02221B84 00yy00xx
  02221B88 00yy00xx
  02221B8C 00yy00xx
  02221B90 00yy00xx
  02221B94 00yy00xx
  02221B98 00yy00xx
  02221B9C 00yy00xx
  02221BA0 00yy00xx
  01221BA4 000000xx

* Leg Move Proficiencies

  GameShark
  1BDC1818 000000xx
  1BE4D818 00yy00xx
  1BF4D818 00yy00xx
  1B04D818 00yy00xx
  1B14D818 00yy00xx
  1B24D818 00yy00xx
  1B34D818 00yy00xx
  1B44D818 00yy00xx

  Address Format
  01221BD6 000000xx
  02221BD8 00yy00xx
  02221BDC 00yy00xx
  02221BE0 00yy00xx
  02221BE4 00yy00xx
  02221BE8 00yy00xx
  02221BEC 00yy00xx
  02221BF0 00yy00xx

* Throw Move Proficiencies

  GameShark
  1424D819 00yy00xx
  1434D819 00yy00xx
  1444D819 00yy00xx
  1454D819 00yy00xx
  1464D819 00yy00xx
  1474D819 00yy00xx
  1584D819 00yy00xx

  Address Format
  02221C28 00yy00xx
  02221C2C 00yy00xx
  02221C30 00yy00xx
  02221C34 00yy00xx
  02221C38 00yy00xx
  02221C3C 00yy00xx
  02221C40 00yy00xx

  Note: a value of 64 corresponds to complete mastery. Also, giving a value to
  a move not yet on the move scroll can be done, but the move will not be
  available until it is learned in the game.

-------------------------------------------------------------------------------
Value Lists (V11)                                                               
-------------------------------------------------------------------------------

* Quest Items List
  1: Cassette Player
  2: Letter to Father
  3: Watch
  4: Sword Handguard
  5: Phoenix Mirror
  6: Master Chen Introduction Letter
  7: Amulet

* Sega Saturn Games List
  1: Hang On
  2: Space Harrier

* Photograph List
  1: Father
  2: Friends
  3: Nozomi Fair Close
  4: Nozomi Cloudy Close
  5: Nozomi Cloudy Apart
  6: Nozomi Fair Apart
  7: Nozomi Snowy Close
  8: Nozomi Snowy Apart
  9: Hazuki Family

* Move Scrolls List
  1: Twin Blades
  2: Shadow Reaper
  3: Stab Armor
  4: Twin Swallow Leap
  5: Mud Spider
  6: Rising Flash
  7: Crawl Cyclone
  8: Tiger Storm
  9: Arm Break Fire
  10: Poetry Scroll
  10.5: Mysterious Scroll (Unlike other move scrolls, this scroll's address is
                           only one higher than the previous address.)

* Map List
  1: Route Map 1
  2: Route Map 2
  3: Route Map 3
  4: Route Map 4
  5: Route Map 5
  6: Race Course Map
  7: Old Depot Map (Original)
  8: Old Depot Map (Altered)

* Trip Fliers List
  1: Hong Kong Flier
  2: Bargain Flier

* Shenmue Snacks List
  1: Potato Chips
  2: Chocolate
  3: Caramel

* Kitten Food List
  1: Squid Legs
  2: Sliced Fish
  3: Milk
  4: Dried Fish
  5: Tuna
  6: Salami

* Household Items List
  1: Flashlight
  2: C Batteries
  3: AA Batteries
  4: Candles
  5: Matches
  6: Light Bulbs

* Hand Moves List
  1: Tiger Knuckle
  2: Elbow Slam/Pit Blow
  3: Twist Knuckle
  4: Elbow Assault
  5: Upper Knuckle
  6: Sleeve Strike
  7: Rain Thrust
  8: Big Wheel
  9: Twin Hand Waves/Double Blow
  10: Backfist Willow
  11: Avalanche Mist
  12: Katana Mist Slash
  13: Mistral Flash
  14: Twin Blades
  15: Rising Flash
  16: Stab Armor
  17: Swallow Flip

* Leg Moves List
  1: Crescent Kick
  2: Trample Kick
  3: Side Reaper Kick/Swallow Dive
  4: Against Cascade/Tornado Kick
  5: Surplice Slash
  6: Thunder Kick
  7: Hold Against Leg
  8: Brutal Tiger
  9: Dark Moon
  10: Cyclone Kick
  11: Windmill
  12: Shadow Reaper
  13: Mud Spider
  14: Crawl Cyclone
  15: Twin Swallow Leap

* Throw Moves List
  1: Overthrow
  2: Sweep Throw
  3: Vortex Throw
  4: Mist Reaper
  5: Demon Drop
  6: Shoulder Buster
  7: Tengu Drop
  8: Darkside Hazuki
  9: Back Twist Drop
  10. Tiger Storm
    11: Arm Break Fire
    12: Shadow Step
    13: Shadow Blade
    14: Cross Charge

* Complete Collection List
  1: Akira 1
  2: Akira 2
  3: Jacky 1
  4: Jacky 2
  5: Sarah 1
  6: Sarah 2
  7: Lau 1
  8: Lau 2
  9: Pai 1
  10: Pai 2
  11: Wolf 1
  12: Wolf 2
  13: Jeffry 1
  14: Jeffry 2
  15: Kage 1
  16: Kage 2
  17: Dural Silver
  18: Dural Gold
  19: Wooden Man
  20: Rent-A-Hero
  21: TRY-Z
  22: Solo Wing
  23: Mr. Yukawa Happi
  24: Mr. Yukawa Suit
  25: Kids Akira 1
  26: Kids Akira 2
  27: Kids Jacky 1
  28: Kids Jacky 2
  29: Kids Sarah 1
  30: Kids Sarah 2
  31: Kids Lau 1
  32: Kids Lau 2
  33: Kids Pai 1
  34: Kids Pai 2
  35: Kids Wolf 1
  36: Kids Wolf 2
  37: Kids Jeffry 1
  38: Kids Jeffry 2
  39: Kids Kage 1
  40: Kids Kage 2
  41: Kids Shun Di 1
  42: Kids Shun Di 2
  43: Kids Lion 1
  44: Kids Lion 2
  45: Kids Dural Silver
  46: Kids Dural Gold
  47: NiGHTS 1
  48: NiGHTS 2
  49: Sonic 1
  50: Sonic 2
  51: Super Sonic
  52: Tails
  53: Knuckles
  54: Bark
  55: Bean
  56: Fang
  57: Amy
  58: Espio
  59: Metal Sonic
  60: Eggman
  61: Hang On 1
  62: Hang On 2
  63: Hang On 3
  64: Hang On 4
  65: Hang On 5
  66: Hang On Gold
  67: Space Harrier
  68: Ruber
  69: Binsbein 1
  70: Binsbein 2
  71: Binsbein 3
  72: Binsbein Gold
  73: Pochi
  74: John
  75: Kelly
  76: Kuro
  77: Tora
  78: Big Robin
  79: Little Robin
  80: Robins
  81: Big Philip
  82: Little Philip
  83: Philips
  84: Chip
  85: Rap
  86: Pop
  87: Pip
  88: Mary
  89: Pyonta
  90: Myau
  91: Chicken Leg
  92: Chao & Pian
  93: Ristar
  94: Alex Kidd
  95: Opa-Opa
  96: Jet Opa-Opa
  97: Poppors
  98: Coba Beach
  99: Aida II
  100: Shop
  101: Heavy Bomb 1
  102: Heavy Bomb 2
  103: Heavy Bomb 3
  104: MOBO
  105: ROBO
  106: Bonanza Brothers
  107: Motor Scooter
  108: Delivery Moped
  109: Coupe' 1
  110: Coupe' 2
  111: Coupe' 3
  112: Coupe' 4
  113: Coupe' 5
  114: Hornet
  115: Wagon 1
  116: Wagon 2
  117: Wagon 3
  118: Wagon 4
  119: Truck 1
  120: Truck 2
  121: Truck 3
  122: Truck 4
  123: Hot Dog Truck
  124: Bus
  125: Forklift
  126: Forklift No. 1
  127: Forklift No. 2
  128: Forklift No. 3
  129: Forklift No. 4
  130: Forklift No. 5
  131: Forklift Red
  132: Forklift Blue
  133: Crane
  134: Shenmue Container
  135: Container
  136: Wooden Crate
  137: Anchor
  138: Ferry
  139: Steering Wheel
  140: Float
  141: X Button
  142: Y Button
  143: A Button
  144: B Button
  145: Cherry
  146: Mini Jukebox
  147: Mini Slot Game
  148: Mini QTE Title
  149: Mini Harrier
  150: Mini Hang On
  151: R-360
  152: Mini Darts
  153: Mini QTE
  154: Mini Pool
  155: Matsuyama Prize
  156: Mitsuzuka Prize
  157: Megadra Brother
  158: Gear-O
  159: Sataro
  160: Dreamcasko
  161: Harrier Token
  162: Hang On Token
  163: Super Ball 1
  164: Super Ball 2
  165: Super Ball 3
  166: Dice 1
  167: Dice 2
  168: Dice 3

* Cassette Values (Used in quantity lines, not address advancement)
  00: Go Go
  01: Feel Tired Song
  02: Hip De Hop
  03: Like a Feeling
  04: Heart Beats
  05: Flower Girl
  06: Antiquity Tree
  07: Dandy Old Man
  08: Liquor
  09: Linda
  0A: M.S. Shower
  0B: Hang On
  0C: Space Harrier
  0D: Final Takeoff
  0E: Destiny
  0F: Boz Nov
  10: Be-Witch
  11: MJQ
  12: Harbor Bar
  13: NaNa
  14: Spider
  15: Glyfada
  16: Y.A.D.A.
  17: Yokosuka Blues
  18: Strong
  19: Harbor Beats
  1A: Shenmue
  1B: Sha Hua

-------------------------------------------------------------------------------
Custom Code Tutorial (T12)                                                    
-------------------------------------------------------------------------------

    Many of the codes listed here are code type 02, meaning that they modify
  four address values. In certain cases, you may only want to modify only one
  or two address values. The best solution for this situation is a custom code;
  one that is created entirely by you. A code is comprised of three parts: a
  code type, starting address, and quantity line. When you create a custom
  code, you must determine each of these parts. This section is devoted to
  helping you finalize each section of code, and putting it all together to
  form the complete custom code.

* Code Type
    The code type will determine how many address values are modified. So, you
      need to know how many address values need to be changed. The following list
      notes the recommended number of address value changes for particular items:

  Menu/Collectable Items: 1
  Cassettes/Moves: 2

    Now, recall that the 00 code type modifies one address value, and the 01
  code type modifies two address values. Now you have your code type. Later on,
  you'll need a number called n, which is equal to the number of address values
  changed by your code (found in the list above). Note whether n = 1 or 2, and
  keep that in mind for the next step. 

* Starting Address
    Determining the starting address is the most difficult procedure in
      creating custom codes. First, your item of interest has a value associated
      with it. The following list outlines the guidelines for these values:

  Menu Items: its order in a value list
  Collectable Items: its order in the Complete Collection value list
  Cassettes: the cassette slot to be modified
  Moves: its order in the Hand, Leg, or Throw value list

    Record the item's value (v) and the name of the value list it appears in
  (or Cassette Collection for cassettes). Next, scroll up to the code list with
  the same name as the value list. Look at the Address Format section, and
  record the first address in the list (remember that Address Format is
  ttaaaaaa, where aaaaaa is the address). This address will be called s. Now,
  you need to solve for t, the value to be added to s. Use this formula to
  solve for t:

    t = (v - 1) * n
    
    Convert t to hex base (0h[t]), and add it to s just as you would two
  values. The final result is your custom code's starting address!

* Quantity Line
    Finally, you need to write a quantity line to accompany your address line.
      The following list will help you create the proper quantity line:

  Menu/Collectable Items: 000000xx (xx = quantity of item)
  Cassettes: 0000aaxx (aa = identity of cassette, xx = quantity of cassette)
  Moves: 000000xx (xx = proficiency of move, 64 is complete mastery)

    Once you have written your quantity line, you have all three sections for
  your custom code! Simply place them together following the code model:
  ttaaaaaa xxxxxxxx. If you are using a GameShark, there is one final step
  before your custom code is usable.

* Encryption (GameShark Only)
    In order for your custom code to work on a GameShark, you must now encrypt
      the code. Open DCcrypt, and paste the address line into the text box. Click
      Encrypt, and place the result above your quantity line. This is your
      encrypted custom code, ready to use with your GameShark!

* Examples
    In order to help you through your first custom codes, I've written two
      common examples of custom codes, and the steps required for the final result. 

* Super Sonic Example (Set 1 Super Sonic figure to collection)

  * Step 1: Code Type
    Code Type: 00
    n = 1

  * Step 2: Starting Address
    v = 51 (Found in Complete Collection Value list)
    Value List Name: Complete Collection
    s = 221CBC (first Address Format code line in Complete Collection list is
                02221CBC, remove first two characters to get starting address)
    t = (v - 1) * n = (51 - 1) * 1 = 50
    0h[t] = 32 (50 in decimal = 32 in hex)
    Starting Address = s + 0h[t] = 221CBC + 32 = 221CEE

  * Step 3: Quantity Line
    Quantity Line Model: 000000xx
    xx = 01 (One figure desired)
    Quantity Line: 00000001

  * Unencrypted Code: 00221CEE 00000001

  * Encrypted Code: 173C5819 00000001

* Hip De Hop Example (Set 3 Hip De Hop cassettes to the tenth cassette slot)

  * Step 1: Code Type
    Code Type: 01
    n = 2

  * Step 2: Starting Address
    v = 10 (tenth cassette slot)
    Value List Name: Cassette Collection
    s = 221DBC (first Address Format code line in Cassette Collection list is
                02221DBC, remove first two characters to get starting address)
    t = (v - 1) * n = (10 - 1) * 2 = 18
    0h[t] = 12 (18 in decimal = 12 in hex)
    Starting Address = s + 0h[t] = 221DBC + 12 = 221DCE

  * Step 3: Quantity Line
    Quantity Line Model: 0000aaxx
    aa = 02 (Found in Cassette Values list)
    xx = 03 (Three cassettes desired)
    Quantity Line: 00000203

  * Unencrypted Code: 01221DCE 00000203

  * Encrypted Code: 13BC1819 00000203

-------------------------------------------------------------------------------
Future Updates (U13)                                                            
-------------------------------------------------------------------------------

  Look for these additions in the future!

* Addresses to enable moves not yet learned.
* Addresses to unlock Passport features.
* Addresses to unlock Notebook entries.

-------------------------------------------------------------------------------
Thanks (T14)                                                                    
-------------------------------------------------------------------------------

  Thanks to these people who made this guide possible:

    Interact, for providing starting addresses to search.
    ADnova, for the thorough Dreamcast Hacking guide.
    Unknown, for writing DCcrypt (I wish I knew who made this).
    Yu Suzuki, for creating the greatest video game series ever: Shenmue.
    CJayC, for making GameFAQs the best place for gamers to communicate.
    Hellraiser and LanDC, for maintaining the Shenmue Dojo.
    You, the readers, for reading my guide!

-------------------------------------------------------------------------------
                        * * * * * * * END * * * * * * *                         
-------------------------------------------------------------------------------