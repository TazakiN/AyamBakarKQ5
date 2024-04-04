#include "Item.hpp"

Item::Item(string name, string kode_huruf, int harga) : name(name), kode_huruf(kode_huruf)
{
    this->harga = harga;
}
Item::~Item()
{
}

string Item::getName() const
{
    return this->name;
}

string Item::getKode() const
{
    return this->kode_huruf;
}

int Item::getHarga() const
{
    return this->harga;
}