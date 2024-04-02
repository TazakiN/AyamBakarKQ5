#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "Makhluk.hpp"
#include <iostream> // KALO ERROR INI TERDUGA PENYEBABNYA

class Hewan : public Makhluk
{
protected:
    int berat;
    int beratUntukPanen;
public:
    /**
     * @brief Konstruktor item 
     *
     * @param nama nama pemain
     * @param kode_huruf
     */
    Hewan(string nama, string kode_huruf, int pertambahanBerat, int harga, int berat, int beratUntukPanen);

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
    virtual void makan() = 0;
};

#endif