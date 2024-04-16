#include "anim.hpp"
using namespace std;

/* Frame animasi */
void printLoadingAnimation() {
    int numFrames = 10; 
    int delay = 150;

    // Frame animasi loading
    string frames[] = {
        "[        ]",
        "[#       ]",
        "[##      ]",
        "[###     ]",
        "[####    ]",
        "[#####   ]",
        "[######  ]",
        "[####### ]",
        "[########]",
        "[########]"
    };

    // Cetak animasi loading
    for (int i = 0; i < numFrames; ++i) {
        cout << p_rgb(255, 255, 153) << "Memuat " << frames[i % 10] << reset() << "\r";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay));
    }

    cout << p_green() << "State berhasil dimuat!    " << endl << reset();
}
string title1 =  R"(

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

string title2 =  R"(

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

string homePage1 = title1 + code1 + homeImage;
string homePage2 = title2 + code2 + homeImage;

string welcome = "Silahkan mulai permainan atau ketik MUAT untuk memuat state permainan...\n";

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
                         -#+-+@@@@@@@@
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

/* Fungsi untuk mencetak animasi */
void printAnimation(const string& frame1, const string& frame2, int numFrames, int delay, string color) {
    // Memecah frame jadi baris-baris
    istringstream iss1(frame1);
    istringstream iss2(frame2);
    vector<string> frame1Lines;
    vector<string> frame2Lines;
    string line;
    while (getline(iss1, line)) {
        frame1Lines.push_back(line);
    }
    while (getline(iss2, line)) {
        frame2Lines.push_back(line);
    }

    // Cetak animasi
    cout << color << frame1 << reset();
    for (int i = 0; i < numFrames; ++i) {
        this_thread::sleep_for(chrono::milliseconds(delay));

        // Memindahkan kursor ke atas sejumlah baris yang sesuai
        for (size_t j = 0; j < frame1Lines.size(); ++j) {
            cout << "\033[1A";
        }

        // Cetak frame bergantian
        if (i % 2 == 0) {
            cout << color << frame2 << reset();
        } else {
            cout << color << frame1 << reset();
        }
    }
}

void printHomePage(const string& frame1, const string& frame2, int numFrames, int delay) {
    // Memecah frame jadi baris-baris
    istringstream iss1(frame1);
    istringstream iss2(frame2);
    vector<string> frame1Lines;
    vector<string> frame2Lines;
    string line;
    while (getline(iss1, line)) {
        frame1Lines.push_back(line);
    }
    while (getline(iss2, line)) {
        frame2Lines.push_back(line);
    }

    // Cetak animasi
    cout << p_rgb(255, 255, 153) << title1 << reset();
    cout << p_rgb(255, 204, 153) << code1 << reset();
    cout << p_rgb(255, 153, 153) << homeImage << reset();
    for (int i = 0; i < numFrames; ++i) {
        this_thread::sleep_for(chrono::milliseconds(delay));

        // Memindahkan kursor ke atas sejumlah baris yang sesuai
        for (size_t j = 0; j < frame1Lines.size(); ++j) {
            cout << "\033[1A";
        }

        // Cetak frame bergantian
        if (i % 2 == 0) {
            cout << p_rgb(255, 255, 153) << title2 << reset();
            cout << p_rgb(255, 204, 153) << code2 << reset();
            cout << p_rgb(255, 153, 153) << homeImage << reset();
        } else {
            cout << p_rgb(255, 255, 153) << title1 << reset();
            cout << p_rgb(255, 204, 153) << code1 << reset();
            cout << p_rgb(255, 153, 153) << homeImage << reset();
        }
    }
}