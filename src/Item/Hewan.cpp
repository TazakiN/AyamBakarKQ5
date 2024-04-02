#include "Hewan.hpp"

Hewan::Hewan(string nama, string kode_huruf, int pertambahanBerat, int harga, int berat, int beratUntukPanen) : Makhluk(nama, kode_huruf, pertambahanBerat, harga), berat(berat), beratUntukPanen(beratUntukPanen)
{
}

Hewan::~Hewan()
{
}

int Hewan::getBerat()
{
    return this->berat;
}

bool Hewan::siapPanen()
{
    return this->berat >= this->beratUntukPanen;
}