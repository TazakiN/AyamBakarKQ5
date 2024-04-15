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
    std::advance(iter, idx);

    // Kalo yang dibeli unlimited
    if (idx < 15)
    {
        while (quantityLeft > 0)
        {
            Item *item = iter->front();
            // print nama item
            cout << item->getName() << endl;
            Omnivora *omnivora = dynamic_cast<Omnivora*>(item);
    
            if (omnivora != nullptr) {
                // item is indeed a Herbivora or derived from Herbivora
                cout << "omnivora" << endl;
                Omnivora *newOmnivora = new Omnivora(*omnivora);
                removedItem.push_back(newOmnivora);
            }

            Karnivora *karnivora = dynamic_cast<Karnivora*>(item);
            if (karnivora != nullptr) {
                // item is indeed a Herbivora or derived from Herbivora
                cout << "karnivora" << endl;
                Karnivora *newKarnivora = new Karnivora(*karnivora);
                removedItem.push_back(newKarnivora);
            }

            Herbivora *herbivora = dynamic_cast<Herbivora*>(item);
            if (herbivora != nullptr) {
                // item is indeed a Herbivora or derived from Herbivora
                cout << "herbivora" << endl;
                Herbivora *newHerbivora = new Herbivora(*herbivora);
                removedItem.push_back(newHerbivora);
            }

            if (typeid(iter->front()) == typeid(Herbivora))
            {
                Herbivora *h = dynamic_cast<Herbivora *>(iter->front());
                Herbivora *newHerbivora = new Herbivora(*h);
                cout << newHerbivora->getName() << endl;
                removedItem.push_back(newHerbivora);
            }
            else if (typeid(iter->front()) == typeid(Karnivora))
            {
                Karnivora *h = dynamic_cast<Karnivora *>(iter->front());
                cout << h->getName() << endl;
                Karnivora *newKarnivora = new Karnivora(*h);
                cout << newKarnivora->getName() << endl;
                removedItem.push_back(newKarnivora);
            }
            else if (typeid(iter->front()) == typeid(Omnivora))
            {
                Omnivora *h = dynamic_cast<Omnivora *>(iter->front());
                cout << h->getName() << endl;
                Omnivora *newOmnivora = new Omnivora(*h);
                cout << newOmnivora->getName() << endl;
                removedItem.push_back(newOmnivora);
            }
            else if (typeid(iter->front()) == typeid(MaterialPlant))
            {
                MaterialPlant *p = dynamic_cast<MaterialPlant *>(iter->front());
                MaterialPlant *newMaterialPlant = new MaterialPlant(*p);
                removedItem.push_back(newMaterialPlant);
            }
            else if (typeid(iter->front()) == typeid(FruitPlant))
            {
                FruitPlant *p = dynamic_cast<FruitPlant *>(iter->front());
                FruitPlant *newFruitPlant = new FruitPlant(*p);
                removedItem.push_back(newFruitPlant);
            }
            quantityLeft--;
        }
        cout << "debug" << endl;
        for (const auto &item : removedItem)
        {
            std::cout << item->getName() << std::endl;
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
        cout << "debug" << endl;
        for (const auto &item : removedItem)
        {
            std::cout << item->getName() << std::endl;
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