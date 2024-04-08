#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "Makhluk.hpp"
#include "Produk.hpp"
#include <iostream>
#include <string>
#include <vector>

class Hewan : public Makhluk
{
protected:
    int berat;
    int beratUntukPanen;
    vector<vector<string>> dataOfHewan;

public:
    /**
     * @brief Konstruktor item 
     *
     * @param nama nama pemain
     * @param kode_huruf
     * @param harga harga item
     * @param berat berat item
     * @param beratUntukPanen berat item untuk panen
     */
    Hewan(string nama, string kode_huruf, string tipe, int harga, int berat, int beratUntukPanen);

    /**
     * Destruktor item
     */
    virtual ~Hewan();

    /**
     * Mengembalikan nama item
     *
     * @return nama item
     */
    int getBerat();

    /**
     * Set berat hewan 
    */
    void setBerat(int berat);

    /**
     * Mengembalikan nilai apakah 
     *
     * @return kode huruf item
     */
    bool siapPanen();

    /**
     * Hewan makan
     *
     * @return kode huruf item
     */
    virtual void makan(Produk &makanan) = 0;

    /**
     * Mengambil dataOfHewan dari config oleh GameEngine
    */
    // void setDataOfHewan(const vector<vector<string>>& dataOfHewan);
};

#endif