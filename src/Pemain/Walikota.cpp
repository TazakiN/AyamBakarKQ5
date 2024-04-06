#include "Walikota.hpp"

Walikota::Walikota(string name, int row, int col) : Pemain(name, row, col)
{
    bahanBangunan["TEAK_WOOD"] = 0;
    bahanBangunan["SANDAL_WOOD"] = 0;
    bahanBangunan["ALOE_WOOD"] = 0;
    bahanBangunan["IRONWOOD_WOOD"] = 0;
}

Walikota::~Walikota()
{
}

void Walikota::bangun(string jenis_bangunan, vector<vector<string>> listOfResepBangunan)
{
    size_t i = 0;
    int isFound = 0;
    int isEnough = 1;
    vector<string> recipe;
    while (i < listOfResepBangunan.size() && isFound == 0)
    {
        recipe = listOfResepBangunan[i];
        if (recipe[2] == jenis_bangunan)
        {
            isFound = 1;
        }
        ++i;
    }
    i = 4;
    while (i < recipe.size() - 1)
    {
        if (bahanBangunan[recipe[i]] < stoi(recipe[i + 1])) // stoi: convert string to int
        {
            MaterialTidakCukup e;
            throw e;
        }
        i += 2;
    }
    i = 4;
    while (i < recipe.size() - 1)
    {
        bahanBangunan[recipe[i]] -= stoi(recipe[i + 1]);
        i += 2;
    }
    Bangunan *b = new Bangunan(jenis_bangunan, recipe[1], stoi(recipe[3]));
    this->Pemain::masukanItem(b);
}

float Walikota::HitungPajak()
{
    return 0;
}

void Walikota::addResep(std::vector<string> &resep)
{
}

void Walikota::addBahanBangunan(string bahan, int jumlah)
{
}

int Walikota::countBahanBangunan(const Item &item)
{
    int count = 0;
    Inventory *inventory = this->getInventory();
    if (inventory)
    {
        int numRows = inventory->getRow();
        int numCols = inventory->getCol();
        for (int row = 0; row < numRows; ++row)
        {
            for (int col = 0; col < numCols; ++col)
            {
                if (this->getInventory()->getItem(row, col) == &item)
                {
                    count++;
                }
            }
        }
    }
    return count;
}
