#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include "Makhluk.hpp"
#include <string>
#include <vector>

class Tanaman : public Makhluk
{
private:
    // int umur;
    // int durasiUntukPanen;
    // vector<vector<string>> dataOfTanaman;

public:
    /**
     * @brief Konstruktor tanaman
     *
     * @param nama nama tanaman
     * @param kode_huruf tanaman
     * @param tipe tipe tanaman
     * @param harga harga tanaman
     * @param umur umur tanaman
     * @param durasiUntukPanen durasi yang dibutuhkan untuk panen
     */
    Tanaman(string nama, string kode_huruf, string tipe, int harga, int umur, int durasiUntukPanen);

    /**
     * Destruktor makhluk
     */
    virtual ~Tanaman();

    /**
     * set umur tanaman
     * @param umur umur tanaman
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

    /**
     * Mengambil dataOfTanaman dari config oleh GameEngine
     */
    // void setDataOfTanaman(const vector<vector<string>> &dataOfTanaman);

    /**
     * @return Produk yang dihasilkan dari panen tanaman
     */
    vector<Produk *> konversiPanen();
};

#endif