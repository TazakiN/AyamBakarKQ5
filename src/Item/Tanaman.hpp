#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include "Makhluk.hpp"

class Tanaman : public Makhluk
{
private:
    int umur;
    int durasiUntukPanen;

public:
    /**
     * @brief Konstruktor tanaman
     *
     * @param nama nama tanaman
     * @param kode_huruf tanaman 
     * @param tipe tipe tanaman
     * @param umur umur tanaman
     * @param harga harga tanaman
     * @param durasiUntukPanen durasi yang dibutuhkan untuk panen
     */
    Tanaman(string nama, string kode_huruf, string tipe, int umur, int harga, int durasiUntukPanen);

    /**
     * Destruktor makhluk
     */
    virtual ~Tanaman();

    /**
     * set umur tanaman
    */
    void setUmur(int umur);

    /**
     * @return boolean apakah tanaman siap dipanen (true) atau belum (false)
    */
    bool siapPanen();

    /**
     * @return umur tanaman
    */
    int getUmur();
};

#endif 