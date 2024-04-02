#include "Tanaman.hpp"

Tanaman::Tanaman(string nama, string kode_huruf, string tipe, int umur, int harga, int durasiUntukPanen) : Makhluk(nama, kode_huruf, tipe, harga)
{
    this->durasiUntukPanen = durasiUntukPanen;
    this->umur = umur;
    cout << endl;
    cout << p_yellow() << "Test: Tanaman " << getName() << " dengan detail: " << endl;
    cout << "Kode Huruf: " << kode_huruf << endl;
    cout << "Tipe: " << tipe << endl;
    cout << "Umur: " << umur << endl;
    cout << "Harga: " << harga << endl;
    cout << "Durasi Untuk Panen: " << durasiUntukPanen << endl << reset();
}

Tanaman::~Tanaman()
{
}

bool Tanaman::siapPanen()
{
    return this->umur >= this->durasiUntukPanen;
}

int Tanaman::getUmur()
{
    return this->umur;
}
