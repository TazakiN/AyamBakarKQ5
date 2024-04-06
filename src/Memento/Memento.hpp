#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <vector>
#include "../Grid/Inventory.hpp"
#include "../Item/Item.hpp"

using namespace std;

class Memento{
    private:
        Inventory* inventory;
        int berat_badan;
        int gulden;
        int toko;
        vector<Item*> created_items;
        vector<Item> deleted_items;
        
};

#endif