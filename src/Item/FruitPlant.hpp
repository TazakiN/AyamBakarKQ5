#ifndef FRUITPLANT_HPP
#define FRUITPLANT_HPP

#include "Tanaman.hpp"

class FruitPlant : public Tanaman
{
private:
    /* data */
public:
    FruitPlant(string nama, string kode_huruf, string tipe, int harga, int umur, int durasiUntukPanen);
    ~FruitPlant();
};

#endif