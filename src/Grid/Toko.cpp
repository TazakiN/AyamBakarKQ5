#include "Toko.hpp"

Toko::Toko()
{
    this->total_bangunan = 0;
    this->total_item = 0;
}

Toko::~Toko() {}

void Toko::initializedToko(const std::vector<std::vector<std::string>> &listHewan, const std::vector<std::vector<std::string>> &listTanaman)
{
    // Masukin hewan
    for (size_t i = 0; i < listHewan.size()/2; ++i)
    {
        string nama = listHewan[i][2];
        string kode_huruf = listHewan[i][1];
        string tipe = listHewan[i][3];
        int harga = stoi(listHewan[i][4]);
        int berat = 0;
        int beratUntukPanen = stoi(listHewan[i][5]);

        if (tipe == "HERBIVORE")
        {
            Herbivora h(nama, kode_huruf, tipe, harga, berat, beratUntukPanen);
            std::list<Item> newlistHewan;
            newlistHewan.push_back(h);
            itemInToko.push_back(newlistHewan);
        }
        else if (tipe == "CARNIVORE")
        {
            Karnivora h(nama, kode_huruf, tipe, harga, berat, beratUntukPanen);
            std::list<Item> newlistHewan;
            newlistHewan.push_back(h);
            itemInToko.push_back(newlistHewan);
        }
        else if (tipe == "OMNIVORE")
        {
            Omnivora h(nama, kode_huruf, tipe, harga, berat, beratUntukPanen);
            std::list<Item> newlistHewan;
            newlistHewan.push_back(h);
            itemInToko.push_back(newlistHewan);
        }
    }

    // Masukin tanaman
    for (size_t i = 0; i < listTanaman.size()/2; ++i)
    {
        string nama = listTanaman[i][2];
        string kode_huruf = listTanaman[i][1];
        string tipe = listTanaman[i][3];
        int harga = stoi(listTanaman[i][4]);
        int umur = 0;
        int day = stoi(listTanaman[i][5]);
        Tanaman t(nama, kode_huruf, tipe, umur, harga, day);
        std::list<Item> newlistTanaman;
        newlistTanaman.push_back(t);
        itemInToko.push_back(newlistTanaman);
    }
    this->total_item += 15;
}

void Toko::addItem(const Item &item)
{
    // Masukin item ke list yang udah ada
    bool isFound = false;
    for (auto &itr : itemInToko)
    {
        if (!itr.empty() && itr.front().getName() == item.getName())
        {
            itr.push_back(item);
            isFound = true;
            break;
        }
    }
    // Ato bikin list baru
    if (!isFound)
    {
        std::list<Item> newList;
        newList.push_back(item);
        if (dynamic_cast<const Bangunan *>(&item) != nullptr)
        {
            itemInToko.push_back(newList);
            total_bangunan++;
        }
        else
        {
            int idx = total_item - total_bangunan;
            auto itr = itemInToko.begin();
            std::advance(itr, idx);
            itemInToko.insert(itr, newList);
        }
        total_item++;
    }
}

void Toko::displayToko(int current_pemain)
{
    int i = 0;
    for (auto &itr : itemInToko)
    {
        if (i > 14)
        {
            if (current_pemain == 1 && (itr.front().getName() == "SMALL_HOUSE" || itr.front().getName() == "MEDIUM_HOUSE" || itr.front().getName() == "LARGE_HOUSE" || itr.front().getName() == "HOTEL"))
            {
                break;
            }
            cout << i + 1 << ". ";
            cout << itr.front().getName() << " - " << itr.size() << endl;
            i++;
        }
        else
        {
            cout << i + 1 << ". ";
            cout << itr.front().getName() << endl;
            i++;
        }
    }
}

std::list<Item> Toko::removeItem(const int idx, int quantity, int gulden, int slot_inventory)
{
    std::list<Item> removedItem;
    int quantityLeft = quantity;

    if (idx < 1 || idx > itemInToko.size())
    {
        throw IndexOutOfRange();
    }

    auto iter = itemInToko.begin();
    std::advance(iter, idx - 1);

    if (iter->size() < quantity)
    {
        throw QuantityTokoTidakCukup();
    }

    int totalPrice = iter->front().getHarga() * quantity;
    if (gulden < totalPrice)
    {
        throw GuldenTidakCukup();
    }

    if (quantity > slot_inventory)
    {
        throw InventoryPenuh();
    }

    // Kalo yang dibeli unlimited
    if (idx < 15)
    {
        while (quantityLeft > 0)
        {
            removedItem.push_back(iter->back());
            quantityLeft--;
        }
        return removedItem;
    }
    else
    {
        if (iter->size() == quantity)
        {
            removedItem = *iter;
            itemInToko.erase(iter);
            this->total_item--;
            if (typeid(removedItem.front()) == typeid(Bangunan))
            {
                this->total_bangunan--;
            }
        }
        else
        {
            while (quantityLeft > 0)
            {
                removedItem.push_back(iter->back());
                iter->pop_back();
                quantityLeft--;
            }
        }
        return removedItem;
    }
}