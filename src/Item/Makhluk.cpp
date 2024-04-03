#include "Makhluk.hpp"

Makhluk::Makhluk(string nama, string kode_huruf, string tipe, int harga) : Item(nama, kode_huruf, harga)
{
    this->tipe = tipe;
}

Makhluk::~Makhluk()
{
}

string Makhluk::getTipe()
{
    return this->tipe;
}
