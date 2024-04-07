#include "Walikota.hpp"

Walikota::Walikota(string name, int row, int col) : Pemain(name, row, col)
{
}

Walikota::~Walikota()
{
}

void Walikota::bangun(string jenis_bangunan)
{
    size_t i = 0;
    int isFound = 0;
    vector<string> recipe;
    while (i < listofResepBangunan.size() && isFound == 0)
    {
        recipe = listofResepBangunan[i];
        if (recipe[2] == jenis_bangunan)
        {
            isFound = 1;
        }
        ++i;
    }
    i = 4;
    while (i < recipe.size() - 1)
    {
        if (getListIdxBahanBangunan(recipe[i]).size() < stoi(recipe[i + 1])) // stoi: convert string to int
        {
            MaterialTidakCukup e;
            throw e;
        }
        i += 2;
    }
    if (!this->getInventory()->isEmpty(1))
    {
        InventoryPenuh e;
        throw e;
    }
    i = 4;
    int row, col;
    while (i < recipe.size() - 1)
    {
        list <int> idx = getListIdxBahanBangunan(recipe[i]);
        int banyakBahan = stoi(recipe[i + 1]);
        while (banyakBahan > 0){
            row = idx.back();
            idx.pop_back();
            col = idx.back();
            idx.pop_back();
            this->Pemain::keluarkanItem(row, col);
            banyakBahan--;
        }
        i += 2;
    }
    Bangunan *b = new Bangunan(jenis_bangunan, recipe[1], stoi(recipe[3]));
    this->Pemain::masukanItem(b);
    cout << "Sukses ngebangun yeay" << endl; // nanti coutnya diganti wkwk
}

float Walikota::HitungPajak()
{
    return 0;
}

void Walikota::addResep(std::vector<string> &resep)
{
    this->listofResepBangunan.push_back(resep);
}

std::list<int> Walikota::getListIdxBahanBangunan(std::string item)
{
    std::list<int> itemPosition;
    Inventory *inventory = this->getInventory();
    if (inventory)
    {
        int numRows = inventory->getRow();
        int numCols = inventory->getCol();
        for (int row = 0; row < numRows; ++row)
        {
            for (int col = 0; col < numCols; ++col)
            {
                Item *currentItem = inventory->getItem(row, col);
                if (currentItem && currentItem->getName() == item)
                {
                    itemPosition.push_back(row);
                    itemPosition.push_back(col);
                }
            }
        }
    }
    return itemPosition;
}
