#include "Walikota.hpp"

Walikota::Walikota(string name, int row, int col) : Pemain(name, row, col)
{
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
        if (bahanBangunan[recipe[i]] < stoi(recipe[i + 1]))  // stoi: convert string to int
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


void Walikota::pungutPajak(vector<Pemain *> listPemain, int currPemain)
{
    for (auto itr = listPemain.begin(); itr != listPemain.end(); ++itr)
    {
        int pajak = (*itr)->HitungPajak();
        (*itr)->kurangiGulden(pajak);
        this->tambahkanGulden(pajak);
    }
}

float Walikota::HitungPajak()
{
    return 0;
}
// void Walikota::tambahPemain(string nama_pemain, string peran_pemain)
// {
// }
