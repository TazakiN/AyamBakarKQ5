#include "Makhluk.hpp"

Makhluk::Makhluk(string nama, string kode_huruf, string tipe, int harga) : Item(nama, kode_huruf)
{
    this->tipe = tipe;
    this->harga = harga;
}

Makhluk::~Makhluk()
{
}

int Makhluk::getHarga()
{
    return this->harga;
}

string Makhluk::getTipe()
{
    return this->tipe;
}
