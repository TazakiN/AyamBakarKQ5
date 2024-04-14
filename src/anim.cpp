#include <iostream>
#include <chrono>
#include <thread>
#include <string>

// #include "pcolor.hpp"
using namespace std;


string homePage1 =  R"(

            _  _ ____ _    ____ _    ____    _  _ ____ ____ ____  _ ____ ____ _  _
            |_/  |___ |    |  | |    |__|    |_/  |___ |__/ |__|  | |__| |__| |\ |
            | \_ |___ |___ |__| |___ |  |    | \_ |___ |  \ |  | _| |  | |  | | \|
)";

string code1 = R"(
                                        oooo   oooo    ooooooo      oooooooooo 
                                         888  o88    o888   888o    888        
                                         888888      888     888    888888888o 
                                         888  88o    888o  8o888    o     o888
                                        o888o o888o    88ooo88       888ooo88  
                                                           88o8  
)";

string homePage2 =  R"(

                _  _ ____ _    ____ _    ____    _  _ ____ ____ ____  _ ____ ____ _  _
                |_/  |___ |    |  | |    |__|    |_/  |___ |__/ |__|  | |__| |__| |\ |
                | \_ |___ |___ |__| |___ |  |    | \_ |___ |  \ |  | _| |  | |  | | \|
)";

string code2 = R"(
                                oooo   oooo    ooooooo      oooooooooo 
                                 888  o88    o888   888o    888        
                                 888888      888     888    888888888o 
                                 888  88o    888o  8o888    o     o888
                                o888o o888o    88ooo88       888ooo88  
                                                   88o8  
)";

string homeImage = R"(
       _                                                                        +&-
     _|=|__________          [][][] /""\ [][][]                               _.-^-._    .--.                 
    /              \          |::| /____\ |::|                             .-'   _   '-. |__|
   /                \         |[]|_|::::|_|[]|                            /     |_|     \|  |
  /__________________\        |::::::__::::::|                           /               \  |
   ||  || /--\ ||  ||         |:::::/||\:::::|                          /|     _____     |\ |
   ||[]|| | .| ||[]||         |:#:::||||::#::|                           |    |==|==|    |  |
 ()||__||_|__|_||__||()      #%*###&*##&*&#*&##      |---|---|---|---|---|    |--|--|    |  |
( )|-|-|-|====|-|-|-|( )    ##%%*####*%%%###*%*#     |---|---|---|---|---|    |==|==|    |  | 
^^^^^^^^^^====^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

)";


string peternak = R"(

                 L:rr:            r               
                gBRBBBbrL..    v .: s.            
             vb7RRdMSBB:i::    BK P vB.           
                 Kdg2B.       7PgBQsB             
             .BBsYZDXS          IB2:7             
            iBdPBqMXKQQBBS:   :UQBj               
          dBBJ  ZXR2PMSBrZBgLZBBKB:               
          RQBK  PSR1PgXB  iBQK:iMX.               
            .dBBZIg2PMPd       SB                 
              .:BPUD1Bi      :Bs                  
                BPUg1Q1      SQ.                  
              .qQdqBUEB.     B1                   
              .EgRULbDQK    :BB                   
              BKBZ. BKBD7   EQ                    
              BPBJ  JqBbB   B1                    
              gEB    iBSB:  B7                    
             vBRB    iBgZU :B                     
             bBBr     1BbBiBv                     
            :BBB       BBBRP       
)";

string peternak2 = R"(

                 L:rr:            r               
                gBRBBBbrL..    v .: s.            
             vb7RRdMSBB:i::    BK P vB.           
                 Kdg2B.       7PgBQsB             
     +dBB     .BBsYZDXS         IB2:7             
       "BBJ  iBdPBqMXKQQBBS:   :UQBj               
          dBBJ  ZXR2PMSBrZBgLZBBKB:               
          RQBK  PSR1PgXB  iBQK:iMX.               
               "Ig2PMPd       SB                 
               :BPUD1Bi      :Bs                  
                BPUg1Q1      SQ.                  
              .qQdqBUEB.     B1                   
              .EgRULbDQK    :BB                   
              BKBZ. BKBD7   EQ                    
              BPBJ  JqBbB   B1                    
              gEB    iBSB:  B7                    
             vBRB    iBgZU :B                     
             bBBr     1BbBiBv                     
            :BBB       BBBRP       
)";

string petani = R"(

      ::
  .=#@@@@:
 .%@%+: =@-
         .%+
            ##.             .-=-.
             -%:           .@@@@#
              .#=          *@@@@@=
                *+         .#@@@@*:
                 =#.      +@@@@@@@@%.
                  +@#===+%%*+@@@@@@@=
                   .*#=**-   @@@@@@@-
                      -*-:-+%@@@@@@@%
                       -@#+-+@@@@@@@@
                            %@@@#@@%*
                           =@@%. %@@+
                           %@@.  -@@+
                         :@@@.   +@@@
                         -@@@:   +@@@.
                         :%@=    :@@=
                     .. .#%= . ...-%%: 
)";

string petani2 = R"(

     
      ..
.=#@@@@:
.%@%+: =@-              .-=-.
"      -%=;            .@@@@#
          =#.          *@@@@@=
            *+=         .#@@@@*:
               =#.      +@@@@@@@@%.
                  +@#===+%%*+@@@@@@@=
                   .*#=**-   @@@@@@@-
                      -*-:-+%@@@@@@@%
                       -@#+-+@@@@@@@@
                            %@@@#@@%*
                           =@@%. %@@+
                           %@@.  -@@+
                         :@@@.   +@@@
                         -@@@:   +@@@.
                         :%@=    :@@=
                     .. .#%= . ...-%%: 
)";


string walikota = R"(
            _,,,_
           =@@@%@.
           -@@@@#
            =%@@.     .*+
         . -= *=@*+=   @@
       .-   %@*#@@@@%- :@%
       :@=+@#+@@@@@@@@#%@@
      .%@@@*. :@@@@@@@@@@+
      #@@@@=:  :%@@@==++=
      :++*@@#   .#@%
         -@@@@@-   =
          %@@@@@*   .
          %@@@%@@@@=
          #@@@+#@@@=
          #@@@-*@@@=
          #@@@:+@@@-
          #@@@.=@%@=
          *@@@::@@@=
          *@@@:.@@@=
          *@@#: @@@=
         :%@@+-.#@@*.
        -#@%+   -*@@*:
)";

string walikota2 = R"(
            _,,,_
           =@@@%@.
           -@@@@#
            =%@@.         .*+
         . -= *=@*+=      @@
       .-   %@*#@@@@%-  :@%
       :@=+@#+@@@@@@@@#%@@
      .%@@@*. :@@@@@@@@@@+
      #@@@@=:  :%@@@==++=
      :++*@@#   .#@%
         -@@@@@-   =
          %@@@@@*   .
          %@@@%@@@@=
          #@@@+#@@@=
          #@@@-*@@@=
          #@@@:+@@@-
          #@@@.=@%@=
          *@@@::@@@=
          *@@@:.@@@=
          *@@#: @@@=
         :%@@+-.#@@*.
        -#@%+   -*@@*:
)";

// int main() {
//     // Compile  command:
//     // cd src
//     // g++ -o anim anim.cpp
//     // ./anim

//     // Jumlah frame yang ingin ditampilkan
//     int numFrames = 5;

//     // Waktu jeda antara setiap frame (milidetik)
//     int delayMilliseconds = 500;

//     // Menampilkan animasi
//     for (int i = 0; i < numFrames; ++i) {
//         // Bersihkan terminal sebelum mencetak frame baru
//         cout << "\033[2J\033[1;1H";

//         // Cetak frame pertama atau kedua bergantian
//         if (i % 2 == 0) {
//             cout << homePage1 << endl;
//             cout << code1 << endl;
//             cout << homeImage << endl;
//         } else {
//             cout << homePage2 << endl;
//             cout << code2 << endl;
//             cout << homeImage << endl;
//         }

//         // Tunggu sebelum mencetak frame berikutnya
//         this_thread::sleep_for(chrono::milliseconds(delayMilliseconds));
//     }

//     // Menampilkan peternak
//     for (int i = 0; i < numFrames; ++i) {
//         // Bersihkan terminal sebelum mencetak frame baru
//         cout << "\033[2J\033[1;1H";

//         // Cetak frame pertama atau kedua bergantian
//         if (i % 2 == 0) {
//             cout << peternak << endl;
//         } else {
//             cout << peternak2 << endl;
//         }

//         // Tunggu sebelum mencetak frame berikutnya
//         this_thread::sleep_for(chrono::milliseconds(delayMilliseconds));
//     }

//     // Menampilkan petani
//     for (int i = 0; i < numFrames; ++i) {
//         // Bersihkan terminal sebelum mencetak frame baru
//         cout << "\033[2J\033[1;1H";

//         // Cetak frame pertama atau kedua bergantian
//         if (i % 2 == 0) {
//             cout << petani << endl;
//         } else {
//             cout << petani2 << endl;
//         }

//         // Tunggu sebelum mencetak frame berikutnya
//         this_thread::sleep_for(chrono::milliseconds(delayMilliseconds));
//     }

//      // Menampilkan walikota
//     for (int i = 0; i < numFrames; ++i) {
//         // Bersihkan terminal sebelum mencetak frame baru
//         cout << "\033[2J\033[1;1H";

//         // Cetak frame pertama atau kedua bergantian
//         if (i % 2 == 0) {
//             cout << walikota << endl;
//         } else {
//             cout << walikota2 << endl;
//         }

//         // Tunggu sebelum mencetak frame berikutnya
//         this_thread::sleep_for(chrono::milliseconds(delayMilliseconds));
//     }


//     return 0;
// }
