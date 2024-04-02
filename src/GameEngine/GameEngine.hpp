#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "../Pemain/Pemain.hpp"
#include "../utils/readFile.h"

using namespace std;

class GameEngine
{
private:
    vector<Pemain *> pemainList;
    // vector<Hewan *> dataHewan;
    // vector<Tanaman *> dataTanaman;
    int currentPemain;
    int guldenMenang;
    int beratBadanMenang;
    pair<int, int> ukuranInventory;
    pair<int, int> ukuranLadang;
    pair<int, int> ukuranPeternakan;

    vector<vector<string>> listOfResepBangunan;
    vector<vector<string>> dataOfHewan;
    vector<vector<string>> dataOfTanaman;
    vector<vector<string>> dataOfProduct;

public:
    /**
     * @brief Konstruktor kelas Mediator
     * Langsung menjalankan fungsi populateData
     */
    GameEngine(/* args */);

    /**
     * @brief Destruktor kelas Mediator
     */
    ~GameEngine();

    /**
     * @brief Mengisi data dari file config ke dalam atribut kelas Mediator
     */
    void populateData();
};
