#include "Toko.hpp"

Toko::Toko() : total_key(15)
{
    // Key 1 - 15 isi sama benih dari config
}

// 1 COW COW HERBIVORE 20 6
// 2 SHP SHEEP HERBIVORE 15 5
// 3 HRS HORSE HERBIVORE 18 5
// 4 RBT RABBIT HERBIVORE 10 4
// 5 SNK SNAKE CARNIVORE 13 4
// 6 CHK CHICKEN OMNIVORE 12 3
// 7 DCK DUCK OMNIVORE 11 3
// 1 TEK TEAK_TREE MATERIAL_PLANT 15 5
// 2 SDT SANDALWOOD_TREE MATERIAL_PLANT 10 4
// 3 ALT ALOE_TREE MATERIAL_PLANT 9 6
// 4 IRN IRONWOOD_TREE MATERIAL_PLANT 11 5
// 5 APL APPLE_TREE FRUIT_PLANT 13 4
// 6 ORG ORANGE_TREE FRUIT_PLANT 12 4
// 7 BNT BANANA_TREE FRUIT_PLANT 16 3
// 8 GAV GUAVA_TREE FRUIT_PLANT 14 3

Toko::~Toko() {}

void Toko::addItem(const Item &item)
{
    char keyChar = item.getKode()[0];
    int key = keyChar - 'a' + 1;

    if (itemInToko.find(key) != itemInToko.end())
    {
        itemInToko[key].push_back(item);
    }
    else
    {
        itemInToko[key] = {item};
    }
}

void Toko::displayToko(int current_pemain)
{
    for (const auto &pair : itemInToko)
    {
        if (current_pemain == 1 && !pair.second.empty())
        {
            const auto &firstItem = pair.second.front();
            if (firstItem.getName() == "SMALL_HOUSE" || firstItem.getName() == "MEDIUM_HOUSE" || firstItem.getName() == "LARGE_HOUSE" || firstItem.getName() == "HOTEL")
            {
                continue;
            }
        }
        std::cout << pair.first << ". ";
        if (!pair.second.empty())
        {
            const auto &firstItem = pair.second.front();
            std::cout << firstItem.getName() << " - " << firstItem.getHarga() << " (" << pair.second.size() << ")";
        }
        std::cout << std::endl;
    }
}

std::list<Item> Toko::removeItem(const int key, int quantity, int gulden, int slot_inventory)
{
    std::list<Item> removedItems;
    auto itr = itemInToko.find(key);
    if (itr != itemInToko.end())
    {
        auto &itemList = itr->second;
        int totalPrice = itemList.front().getHarga() * quantity;
        if (itemList.size() <= quantity)
        {
            QuantityTokoTidakCukup e;
            throw e;
        }
        else if (gulden < totalPrice)
        {
            GuldenTidakCukup e;
            throw e;
        }
        else if (quantity > slot_inventory) { // inventory penuh
            InventoryPenuh e;
            throw e;
        }
        else
        {
            auto itRemoved = itemList.begin();
            for (int i = 0; i < quantity; ++i)
            {
                removedItems.push_back(*itRemoved);
                ++itRemoved;
            }
            itemList.erase(itemList.begin(), itRemoved);
        }
    }
    return removedItems;
}
