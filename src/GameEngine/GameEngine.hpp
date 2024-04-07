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
    vector<vector<string>> listOfResepBangunan;
    // Toko *toko;

public:
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
     * @brief Mengembalikan nilai dari dataOfHewan
     *
     * @param getSomething atribut yang ingin dicari
     * @param bySomething atribut tempat mencari
     * @param keyword string yang ingin dicari
     * @return string data yang dicari
     */
    string getHewanAttributeByAny(const string &getSomething, const string &bySomething, const string &keyword) const;

    /**
     * @brief Mengembalikan nilai dari dataOfTanaman
     *
     * @param getSomething atribut yang ingin dicari
     * @param bySomething atribut tempat mencari
     * @param keyword string yang ingin dicari
     * @return string data yang dicari
     */
    string getTanamanAttributeByAny(const string &getSomething, const string &bySomething, const string &keyword) const;

    /**
     * @brief Mengembalikan nilai dari dataOfProduct
     *
     * @param getSomething atribut yang ingin dicari
     * @param bySomething atribut tempat mencari
     * @param keyword string yang ingin dicari
     * @return string data yang dicari
     */
    string getProductAttributeByAny(const string &getSomething, const string &bySomething, const string &keyword) const;

    /**
     * @brief Mengembalikan nilai material dari kode di listOfResepBangunan
     */
    vector<pair<string, int>> getMaterialsByRecipeCode(const string &recipeCode) const;

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

    void copyRecipeToWalikota(Walikota& walikota);

    void copyDataToToko(Toko& toko);
};

#endif