#include "Toko.hpp"

Toko::Toko() : total_key(0) {}

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

void Toko::displayMap()
{
    for (const auto &pair : itemInToko)
    {
        std::cout << pair.first << ". ";
        if (!pair.second.empty())
        {
            const auto &firstItem = pair.second.front();
            std::cout << firstItem.getName() << " - " << firstItem.getHarga() << " (" << pair.second.size() << ")";
        }
        std::cout << std::endl;
    }
}

std::list<Item> Toko::removeItem(const int key, int quantity)
{
    std::list<Item> removedItems;
    auto itr = itemInToko.find(key);
    if (itr != itemInToko.end())
    {
        auto &itemList = itr->second;
        if (itemList.size() >= quantity)
        {
            auto itRemoved = itemList.begin();
            for (int i = 0; i < quantity; ++i)
            {
                removedItems.push_back(*itRemoved);
                ++itRemoved;
            }
            itemList.erase(itemList.begin(), itRemoved);
        }
        else
        {
            removedItems = itemList;
            itemList.clear();
        }
    }
    return removedItems;
}
