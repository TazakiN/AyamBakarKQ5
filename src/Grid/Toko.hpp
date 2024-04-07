#ifndef TOKO_HPP
#define TOKO_HPP

#include <map>
#include <string>
#include <list>
#include <typeinfo>
#include <vector>
#include "../Item/Item.hpp"
#include "../Item/Bangunan.hpp"
#include "../Item/Herbivora.hpp"
#include "../Item/Karnivora.hpp"
#include "../Item/Omnivora.hpp"
#include "../Item/Tanaman.hpp"
// #include "../GameEngine/GameEngine.hpp"
#include "../Exception/Exception.hpp"

using namespace std;

class Toko
{
private:
    std::list<list<Item>> itemInToko;
    int total_item;
    int total_bangunan;

public:
    /**
     * @brief Konstruktor toko
     */
    Toko();

    /**
     * Destruktor toko
     */
    ~Toko();

    void initializedToko(const std::vector<std::vector<std::string>>& list, const std::vector<std::vector<std::string>>& listTanaman);

    /**
     * Menambahkan item ke dalam map
     *
     * @param item
     */
    void addItem(const Item &item);

    /**
     * Menampilkan key item, nama item, dan quantity item
     */
    void displayToko(int current_pemain);

    /**
     * Menghapus item dengan kuantitas tertentu dari map
     *
     * @param key item yang ingin dihapus
     * @param quantity item yang ingin dihapus
     *
     * @return list of item
     */
    std::list<Item> removeItem(const int key, int quantity, int gulden, int slot_inventory);
};

#endif
