#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <vector>
#include "../Grid/Inventory.hpp"
#include "../Item/Item.hpp"
#include "../Grid/Toko.hpp"

using namespace std;

class Memento{
    private:
        Inventory* inventory;
        int berat_badan;
        int gulden;
        Toko* toko;
        vector<Item*> created_items;
        // vector<Item*> deleted_items;
        
    public:
        /**
         * @brief Construct a new Memento object
         * 
         * @param pemain_inventory  keadaan inventory pemain sebelum suatu action, nanti akan digunakan dengan copy constructor
         * @param pemain_bb         keadaan berat badan pemain sebelum suatu action
         * @param pemain_gulden     keadaan gulden pemain sebelum suatu action
         * @param toko              keadaan toko sebelum suatu action
         */
        Memento(Inventory& pemain_inventory, int pemain_bb, int pemain_gulden, Toko* toko);

        /**
         * @brief Destruktor
         * 
         */
        ~Memento();

        /**
         * @brief Merekap item yang terbuat setelah suatu action
         * 
         * @param item  item yang terbuat setelah suatu action 
         */
        void insertCreatedItem(Item* item);

        /**
         * @brief Merekap item yang terhapus setelah suatu action, setiap item akan dilakukan copy constructor
         * 
         * @param item 
         */
        // void insertDeletedItem(Item* item);

        /**
         * @brief Mengembalikan keadaan inventory pemain saat ini menjadi keadaan inventory pada memento
         * 
         * @param pemain_inventory 
         */
        void undoInventory(Inventory* pemain_inventory);

        /**
         * @brief Mendapatkan keadaan berat badan di memento
         * 
         * @return int 
         */
        int getBeratBadanMemento();

        /**
         * @brief Mendapatkan keadaan gulden di memento
         * 
         * @return int 
         */
        int getGuldenMemento();

        /**
         * @brief Mengembalikan keadaan toko dengan keadaan toko di memento
         * 
         * @param toko 
         */
        friend void undoToko(Toko* tokoGame, Memento* m);

        /**
         * @brief Menghapus item yang telah terbuat
         * 
         */
        void deleteCreatedItems();

        // void createDeletedItems();
};

#endif