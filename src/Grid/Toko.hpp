#ifndef TOKO_HPP
#define TOKO_HPP

#include <map>
#include <string>
#include <list>
#include "../Item/Item.hpp"

class Toko
{
private:
    std::map<int, std::list<Item>> itemInToko;
    int total_key;

public:
    /**
     * @brief Konstruktor toko
     */
    Toko();

    /**
     * Destruktor toko
     */
    ~Toko();

    /**
     * Menambahkan item ke dalam map
     *
     * @param item
     */
    void addItem(const Item &item);

    /**
     * Menampilkan key item, nama item, dan quantity item
     */
    void displayMap();

    /**
     * Menghapus item dengan kuantitas tertentu dari map
     *
     * @param key item yang ingin dihapus
     * @param quantity item yang ingin dihapus
     *
     * @return list of item
     */
    std::list<Item> removeItem(const int key, int quantity);
};

#endif
