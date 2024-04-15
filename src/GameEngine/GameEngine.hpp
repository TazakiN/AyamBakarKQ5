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
#include "../Item/MaterialPlant.hpp"
#include "../Item/FruitPlant.hpp"
#include "../Item/Produk.hpp"
#include "../Grid/Toko.hpp"
#include "../Memento/ActionHistory.hpp"
#include "../Memento/Memento.hpp"
#include "../Memento/PetaniMemento.hpp"
#include "../Memento/PeternakMemento.hpp"
#include "../Memento/WalikotaMemento.hpp"
#include "../utils/anim.hpp"

using namespace std;

class GameEngine
{
private:
    // TODO : tambahin di konstruktor list keseluruhan pemain
    vector<Pemain *> daftarPemainKeseluruhan;
    priority_queue<Pemain *> pemainList;
    priority_queue<Pemain *> pemainListNextTurn;
    Pemain *currentPemain;
    int guldenMenang;
    int beratBadanMenang;
    pair<int, int> ukuranInventory;
    pair<int, int> ukuranLadang;
    pair<int, int> ukuranPeternakan;

    vector<vector<string>> dataOfHewan;
    vector<vector<string>> dataOfTanaman;
    vector<vector<string>> dataOfProduct;
    vector<vector<string>> listOfResepBangunan;
    Toko *toko;

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
     * @brief Membuat objek Item berdasarkan nama Item
     *
     * @param itemName nama Item
     * @return pointer ke Item yang dibuat
     */
    Item *makeItem(string itemName);

    /**
     * @brief Membaca data dari file state.txt
     */
    void readState(string *filename);

    /**
     * @brief Memulai permainan
     */
    void initGame();

    /**
     * @brief Menyimpan data ke dalam file state.txt
     */
    void simpan(string *filepath);

    /**
     * @brief Menambahkan pemain ke dalam pemainList
     * @param nama_pemain nama pemain
     * @param peran_pemain peran pemain
     * @param row banyak baris Inventory pemain
     * @param col banyak kolom Inventory pemain
     */
    void tambahPemain(Pemain &pemain);

    /**
     * @brief Menambahkan pemain ke dalam pemainList
     * @param nama_pemain nama pemain
     * @param peran_pemain peran pemain
     * @param row banyak baris Inventory pemain
     * @param col banyak kolom Inventory pemain
     */
    void tambahPemain(Pemain &pemain,WalikotaMemento* wm);

    /**
     * @brief copy listOfResepBangunan ke Walikota
     * @param walikota Walikota yang akan diisi
     */
    void copyRecipeToWalikota(Walikota &walikota);

    void printListOfResepBangunan();

    /**
     * @brief copy dataOfHewan dan dataOfTanaman ke Toko
     * @param toko Toko yang akan diisi
     */
    void copyDataToToko(Toko &toko);

    // /**
    //  * @brief copy dataOfHewan ke Hewan
    // */
    // void copyDataToHewan(Hewan& hewan);

    // /**
    //  * @brief copy dataOfTanaman ke Tanaman
    // */
    // void copyDataToTanaman(Tanaman& tanaman);

    /**
     * @brief Driver untuk fungsi kasih_makan
     *
     * @param peternak Peternak yang akan memberi makan
     */
    void kasih_makan_driver(Peternak &peternak);

    /**
     * @brief Driver untuk fungsi beli
     *
     * @param pemain pemain yang akan beli
     */
    void beli_driver(Pemain &pemain);

    /**
     * @brief Driver untuk fungsi jual
     *
     * @param pemain pemain yang akan jual
     */
    void jual_driver(Pemain &pemain);

    //Buat ngetes aja 
    void printDataOfTanaman();
    void printDataOfHewan();
};

#endif