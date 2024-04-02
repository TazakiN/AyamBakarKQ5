#include "Makhluk.hpp"

Makhluk::Makhluk(string nama, string kode_huruf, int pertambahanBerat, int harga) : Item(nama, kode_huruf), pertambahanBerat(pertambahanBerat)
{
    this->harga = harga;
}

Makhluk::~Makhluk()
{
}

int Makhluk::getHarga()
{
    return this->harga;
}

int Makhluk::getPertambahanBerat()
{
    return this->pertambahanBerat;
}