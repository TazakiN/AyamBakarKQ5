#ifndef MATERIALPLANT_HPP
#define MATERIALPLANT_HPP

#include "Tanaman.hpp"

class MaterialPlant : public Tanaman
{
private:
    /* data */
public:
    MaterialPlant(string nama, string kode_huruf, string tipe, int harga, int umur, int durasiUntukPanen);
    ~MaterialPlant();
};

#endif