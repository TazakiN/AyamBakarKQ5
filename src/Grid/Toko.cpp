#include "Toko.hpp"

Toko::Toko()
{
    this->total_bangunan = 0;
    this->total_item = 0;
}

Toko::~Toko() {}

void Toko::copyToko(Toko *toko)
{
    this->total_item = toko->total_item;
    this->total_bangunan = toko->total_bangunan;

    for (const auto &itemList : toko->itemInToko)
    {
        std::list<Item *> newItemList;
        for (const auto &item : itemList)
        {
            if (dynamic_cast<Herbivora *>(item) != nullptr)
            {
                newItemList.push_back(new Herbivora(*dynamic_cast<Herbivora *>(item)));
            }
            else if (dynamic_cast<Karnivora *>(item) != nullptr)
            {
                newItemList.push_back(new Karnivora(*dynamic_cast<Karnivora *>(item)));
            }
            else if (dynamic_cast<Omnivora *>(item) != nullptr)
            {
                newItemList.push_back(new Omnivora(*dynamic_cast<Omnivora *>(item)));
            }
            else if (dynamic_cast<MaterialPlant *>(item) != nullptr)
            {
                newItemList.push_back(new MaterialPlant(*dynamic_cast<MaterialPlant *>(item)));
            }
            else if (dynamic_cast<FruitPlant *>(item) != nullptr)
            {
                newItemList.push_back(new FruitPlant(*dynamic_cast<FruitPlant *>(item)));
            }
            else if (dynamic_cast<Bangunan *>(item) != nullptr)
            {
                newItemList.push_back(new Bangunan(*dynamic_cast<Bangunan *>(item)));
            }
            else
            {
                // harusnya gaada else nya si
            }
        }
        itemInToko.push_back(newItemList);
    }
}

void Toko::initializedToko(const std::vector<std::vector<std::string>> &listHewan, const std::vector<std::vector<std::string>> &listTanaman)
{
    // Masukin hewan
    for (size_t i = 0; i < listHewan.size() / 2; ++i)
    {
        string nama = trim(listHewan[i][2]);
        string kode_huruf = trim(listHewan[i][1]);
        string tipe = trim(listHewan[i][3]);
        int harga = stoi(listHewan[i][4]);
        int berat = 0;
        int beratUntukPanen = stoi(listHewan[i][5]);

        if (tipe == "HERBIVORE")
        {
            Herbivora *h = new Herbivora(nama, kode_huruf, tipe, harga, berat, beratUntukPanen);
            std::list<Item *> newlistHewan;
            newlistHewan.push_back(h);
            itemInToko.push_back(newlistHewan);
        }
        else if (tipe == "CARNIVORE")
        {
            Karnivora *h = new Karnivora(nama, kode_huruf, tipe, harga, berat, beratUntukPanen);
            std::list<Item *> newlistHewan;
            newlistHewan.push_back(h);
            itemInToko.push_back(newlistHewan);
        }
        else if (tipe == "OMNIVORE")
        {
            Omnivora *h = new Omnivora(nama, kode_huruf, tipe, harga, berat, beratUntukPanen);
            std::list<Item *> newlistHewan;
            newlistHewan.push_back(h);
            itemInToko.push_back(newlistHewan);
        }
    }

    // Masukin tanaman
    for (size_t i = 0; i < listTanaman.size() / 2; ++i)
    {
        string nama = trim(listTanaman[i][2]);
        string kode_huruf = trim(listTanaman[i][1]);
        string tipe = trim(listTanaman[i][3]);
        int harga = stoi(listTanaman[i][4]);
        int umur = 0;
        int day = stoi(listTanaman[i][5]);

        if (tipe == "MATERIAL_PLANT")
        {
            MaterialPlant *t = new MaterialPlant(nama, kode_huruf, tipe, umur, harga, day);
            std::list<Item *> newlistTanaman;
            newlistTanaman.push_back(t);
            itemInToko.push_back(newlistTanaman);
        }
        else if (tipe == "FRUIT_PLANT")
        {
            FruitPlant *t = new FruitPlant(nama, kode_huruf, tipe, umur, harga, day);
            std::list<Item *> newlistTanaman;
            newlistTanaman.push_back(t);
            itemInToko.push_back(newlistTanaman);
        }
    }
    this->total_item += 15; // ? ini apa dah
}

void Toko::addItem(const Item *item)
{
    // Masukin item ke list yang udah ada
    bool isFound = false;
    for (auto &itr : itemInToko)
    {
        if (!itr.empty() && (*itr.front()).getName() == item->getName())
        {
            itr.push_back((Item *)item);
            isFound = true;
            break;
        }
    }
    // Ato bikin list baru
    if (!isFound)
    {
        std::list<Item *> newList;
        newList.push_back((Item *)item);
        if (dynamic_cast<const Bangunan *>(item) != nullptr)
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

void Toko::displayToko(int tipe)
{
    int i = 0;
    for (auto &itr : itemInToko)
    {
        if (i > 14)
        {
            if (tipe == 1 && ((*itr.front()).getName() == "SMALL_HOUSE" || (*itr.front()).getName() == "MEDIUM_HOUSE" || (*itr.front()).getName() == "LARGE_HOUSE" || (*itr.front()).getName() == "HOTEL"))
            {
                break;
            }
            cout << i + 1 << ". ";
            cout << (*itr.front()).getName() << " - " << itr.size() << endl;
            i++;
        }
        else
        {
            cout << i + 1 << ". ";
            cout << (*itr.front()).getName() << endl;
            i++;
        }
    }
}

std::list<Item *> Toko::removeItem(const int idx, int quantity, int gulden, int slot_inventory)
{
    std::list<Item *> removedItem;
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

    int totalPrice = (*iter).front()->getHarga() * quantity;
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
            if (typeid(iter->front()) == typeid(Herbivora))
            {
                removedItem.push_back(new Herbivora(*dynamic_cast<Herbivora *>((*iter).back())));
            }
            // if (typeid(iter->front()) == typeid(Hewan))
            // {
            //     Hewan hewanNew((*iter).back());
            // }
            else if (typeid(iter->front()) == typeid(Karnivora))
            {
                removedItem.push_back(new Karnivora(*dynamic_cast<Karnivora *>((*iter).back())));
            }
            else if (typeid(iter->front()) == typeid(Omnivora))
            {
                removedItem.push_back(new Omnivora(*dynamic_cast<Omnivora *>((*iter).back())));
            }
            else if (typeid(iter->front()) == typeid(MaterialPlant))
            {
                removedItem.push_back(new MaterialPlant(*dynamic_cast<MaterialPlant *>((*iter).back())));
            }
            else if (typeid(iter->front()) == typeid(FruitPlant))
            {
                removedItem.push_back(new FruitPlant(*dynamic_cast<FruitPlant *>((*iter).back())));
            }
            quantityLeft--;
        }
        return removedItem;
    }
    else
    {
        if (iter->size() == quantity)
        {
            for (auto &item : *iter)
            {
                removedItem.push_back(item);
            }
            itemInToko.erase(iter);
            this->total_item--;
            if (typeid(iter->front()) == typeid(Bangunan))
            {
                this->total_bangunan--;
            }
        }
        else
        {
            while (quantityLeft > 0)
            {
                removedItem.push_back((*iter).back());
                iter->pop_back();
                quantityLeft--;
            }
        }
        return removedItem;
    }
}

int Toko::getTotalItem()
{
    return this->total_item - 15;
}

int Toko::getTotalBangunan()
{
    return this->total_bangunan;
}

string Toko::getItemKeN(int n)
{
    auto it = itemInToko.begin();
    advance(it, n);
    list<Item *> &itemList = *it;
    Item *firstItem = itemList.front();
    return firstItem->getName();
}

int Toko::getTotalItemKeN(int n)
{
    auto it = itemInToko.begin();
    advance(it, n);
    list<Item *> &itemList = *it;
    return itemList.size();
}

Item* Toko::itemKeN(int n){
    auto it = itemInToko.begin();
    advance(it, n);
    list<Item *> &itemList = *it;
    Item *firstItem = itemList.front();
    return firstItem;
}