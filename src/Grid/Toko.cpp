#include "Toko.hpp"

Toko::Toko() : total_key(7)
{
    // Ini cuma buat coba2, fixnya nunggu config
    itemInToko[1].push_back(Item("COW", "COW", 20));
    itemInToko[2].push_back(Item("SHEEP", "SHP", 15));
    itemInToko[3].push_back(Item("HORSE", "HRS", 18));
    itemInToko[4].push_back(Item("RABBIT", "RBT", 10));
    itemInToko[5].push_back(Item("SNAKE", "SNK", 13));
    itemInToko[6].push_back(Item("CHICKEN", "CHK", 12));
}

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
        this->total_key++;
    }
    int countBangunan = 0;
    auto &items = itemInToko[key];

    // Hitung bangunannya ada berapa
    for (auto it = items.begin(); it != items.end();)
    {
        if (it->getKode() == "SMALL_HOUSE" || it->getKode() == "MEDIUM_HOUSE" || it->getKode() == "LARGE_HOUSE" || it->getKode() == "HOTEL")
        {
            countBangunan++;
        }
    }

    // Pindahin bangunan ke bawah
    // int countBangunanleft = countBangunan;
    // for (auto it = itemInToko.begin(); it != itemInToko.end();)
    // {
    //     if (it->second.getKode() != "SMALL_HOUSE" && it->getKode() != "MEDIUM_HOUSE" && it->getKode() != "LARGE_HOUSE" && it->getKode() != "HOTEL")
    //     {
    //         it-> -= countBangunan;
    //     }
    //     else{
    //         pair.first = total_key - 1 - countBangunanleft;
    //         countBangunanleft--;
    //     }
    // }
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
        else if (quantity > slot_inventory)
        { // inventory penuh
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
