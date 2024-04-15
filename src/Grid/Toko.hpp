#ifndef TOKO_HPP
#define TOKO_HPP

#include <map>
#include <string>
#include <list>
#include <typeinfo>
#include <vector>
#include "../utils/readFile.h"
#include "../Item/Item.hpp"
#include "../Item/Bangunan.hpp"
#include "../Item/Herbivora.hpp"
#include "../Item/Karnivora.hpp"
#include "../Item/Omnivora.hpp"
#include "../Item/MaterialPlant.hpp"
#include "../Item/FruitPlant.hpp"
#include "../Exception/Exception.hpp"

using namespace std;

class Toko
{
private:
    std::list<list<Item *>> itemInToko;
    int total_item;
    int total_bangunan;

public:
    /**
     * @brief Konstruktor toko
     */
    Toko();

    /**
     * @brief Destruktor toko
     */
    ~Toko();

    void copyToko(Toko *toko);

    /**
     * @brief Memasukkan hewan dan tanaman yang unlimited dalam ke dalam toko
     *
     * @param list hewan
     * @param list tanaman
     */
    void initializedToko(const std::vector<std::vector<std::string>> &list, const std::vector<std::vector<std::string>> &listTanaman);

    /**
     * @brief Menambahkan item ke dalam toko
     *
     * @param item
     */
    void addItem(const Item *item);

    /**
     * @brief Menampilkan key item, nama item, dan quantity item
     *
     * @param tipe pemain (1: walikota, 2:peternak, 3:petani)
     */
    void displayToko(int tipe);

    /**
     * Menghapus item dengan kuantitas tertentu dari list toko
     *
     * @param key item yang ingin dihapus
     * @param quantity item yang ingin dihapus
     * @param gulden pemain
     * @param slot inventory pemain
     *
     * @return list of item
     */
    std::list<Item *> removeItem(const int key, int quantity, int gulden, int slot_inventory);

    int getTotalItem();

    int getTotalBangunan();

    string getItemKeN(int n);

    int getTotalItemKeN(int n);

    Item* itemKeN(int n);
};

#endif
