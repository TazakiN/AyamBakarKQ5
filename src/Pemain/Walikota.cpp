#include "Walikota.hpp"

Walikota::Walikota(string name, int row, int col) : Pemain(name, row, col)
{
}

Walikota::~Walikota()
{
}

void Walikota::bangun(string jenis_bangunan)
{
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

float Walikota::HitungPajak(){
    return 0;
}
// void Walikota::tambahPemain(string nama_pemain, string peran_pemain)
// {
// }
