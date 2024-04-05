#include "Hewan.hpp"

Hewan::Hewan(string nama, string kode_huruf, string tipe, int harga, int berat, int beratUntukPanen) : Makhluk(nama, kode_huruf, tipe, harga), berat(berat), beratUntukPanen(beratUntukPanen)
{
}

Hewan::~Hewan()
{
}

int Hewan::getBerat()
{
    return this->berat;
}

void Hewan::setBerat(int berat)
{
    this->berat = berat;
}

bool Hewan::siapPanen()
{
    return this->berat >= this->beratUntukPanen;
}