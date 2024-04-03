#include "Item.hpp"

Item::Item(string name, string kode_huruf, int harga) : name(name), kode_huruf(kode_huruf)
{
    this->harga = harga;
}
Item::~Item()
{
}

string Item::getName()
{
    return this->name;
}

string Item::getKode()
{
    return this->kode_huruf;
}

int Item::getHarga()
{
    return this->harga;
}