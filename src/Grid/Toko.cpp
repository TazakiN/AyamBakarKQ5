#include "Toko.hpp"

Toko::Toko()
{
    this->total_bangunan = 0;
    this->total_item = 0;
}

Toko::~Toko() {
    while(itemInToko.size() > 0){
        while(itemInToko.back().size() > 0){
            delete itemInToko.back().back();
            itemInToko.back().pop_back();
        }
        itemInToko.pop_back();
    }
}

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
    for (size_t i = 0; i < listHewan.size(); ++i)
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
    for (size_t i = 0; i < listTanaman.size(); ++i)
    {
        string nama = trim(listTanaman[i][2]);
        string kode_huruf = trim(listTanaman[i][1]);
        string tipe = trim(listTanaman[i][3]);
        int harga = stoi(listTanaman[i][4]);
        int umur = 0;
        int day = stoi(listTanaman[i][5]);

        if (tipe == "MATERIAL_PLANT")
        {
            MaterialPlant *t = new MaterialPlant(nama, kode_huruf, tipe, harga, umur, day);
            std::list<Item *> newlistTanaman;
            newlistTanaman.push_back(t);
            itemInToko.push_back(newlistTanaman);
        }
        else if (tipe == "FRUIT_PLANT")
        {
            FruitPlant *t = new FruitPlant(nama, kode_huruf, tipe, harga, umur, day);
            std::list<Item *> newlistTanaman;
            newlistTanaman.push_back(t);
            itemInToko.push_back(newlistTanaman);
        }
    }
    this->total_item += 15; // ? ini apa dah -> 15 = 7 hewan yang unlimited + 8 tanaman yang unlimited
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
            else
            {
                cout << i + 1 << ". ";
                cout << (*itr.front()).getName() << " - " << (*itr.front()).getHarga() << " (" << itr.size() << ")" << endl;
                i++;
            }
        }
        else
        {
            cout << i + 1 << ". ";
            cout << (*itr.front()).getName() << " - " << (*itr.front()).getHarga() << endl;
            i++;
        }
    }
}

std::list<Item *> Toko::removeItem(const int idx, int quantity, int gulden, int slot_inventory)
{
    std::list<Item *> removedItem;
    int quantityLeft = quantity;

    auto iter = itemInToko.begin();
    std::advance(iter, idx - 1);

    // Kalo yang dibeli unlimited
    if (idx < 15)
    {
        Item *item = iter->front();
        while (quantityLeft > 0)
        {
            Omnivora *omnivora = dynamic_cast<Omnivora*>(item);
            if (omnivora != nullptr)
            {
                Omnivora *newOmnivora = new Omnivora(*omnivora);
                removedItem.push_back(newOmnivora);
            }

            Karnivora *karnivora = dynamic_cast<Karnivora *>(item);
            if (karnivora != nullptr)
            {
                Karnivora *newKarnivora = new Karnivora(*karnivora);
                removedItem.push_back(newKarnivora);
            }

            Herbivora *herbivora = dynamic_cast<Herbivora *>(item);
            if (herbivora != nullptr)
            {
                Herbivora *newHerbivora = new Herbivora(*herbivora);
                removedItem.push_back(newHerbivora);
            }
            MaterialPlant *materialPlant = dynamic_cast<MaterialPlant *>(item);
            if (materialPlant != nullptr)
            {
                MaterialPlant *newMaterialPlant = new MaterialPlant(*materialPlant);
                removedItem.push_back(newMaterialPlant);
            }
            FruitPlant *fruitPlant = dynamic_cast<FruitPlant *>(item);
            if (fruitPlant != nullptr)
            {
                FruitPlant *newFruitPlant = new FruitPlant(*fruitPlant);
                removedItem.push_back(newFruitPlant);
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
                // cout << "total bangunan ngurang" << endl;
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

Item *Toko::itemKeN(int n)
{
    auto it = itemInToko.begin();
    advance(it, n);
    list<Item *> &itemList = *it;
    Item *firstItem = itemList.front();
    return firstItem;
}