#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include "../utils/readFile.h"
#include "../Pemain/Walikota.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Item/Bangunan.hpp"
#include "../Item/Karnivora.hpp"
#include "../Item/Herbivora.hpp"
#include "../Item/Omnivora.hpp"
#include "../Item/Produk.hpp"
#include "../Grid/Toko.hpp"

using namespace std;

class GameEngine
{
private:
    priority_queue<Pemain *> pemainList;
    int currentPemain;
    int guldenMenang;
    int beratBadanMenang;
    pair<int, int> ukuranInventory;
    pair<int, int> ukuranLadang;
    pair<int, int> ukuranPeternakan;

    vector<vector<string>> dataOfHewan;
    vector<vector<string>> dataOfTanaman;
    vector<vector<string>> dataOfProduct;

    // Toko *toko;

public:
    vector<vector<string>> listOfResepBangunan;
    /**
     * @brief Konstruktor kelas Mediator
     * Langsung menjalankan fungsi readConfig
     */
    GameEngine(/* args */);

    /**
     * @brief Destruktor kelas Mediator
     */
    ~GameEngine();

    /**
     * @brief Mengisi data dari file config ke dalam atribut kelas Mediator
     */
    void readConfig();

    /**
     * @brief Membaca data dari file state.txt
     */
    void readState();

    /**
     * @brief Memulai permainan
     */
    void initialize();

    /**
     * @brief Menyimpan data ke dalam file state.txt
     */
    void simpan();

    /**
     * @brief Memuat data dari file state.txt
     */
    void muat();

    void tambahPemain(string nama_pemain, int peran_pemain, int row, int col);
};

#endif