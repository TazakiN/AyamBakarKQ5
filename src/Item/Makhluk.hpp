#ifndef MAKHLUK_HPP
#define MAKHLUK_HPP

#include "Item.hpp"

class Makhluk : public Item 
{
protected:
    int harga;
    string tipe;

public:
    /**
     * @brief Konstruktor makhluk
     *
     * @param nama nama makhluk
     * @param kode_huruf
     * @param pertambahanBerat
     */
    Makhluk(string nama, string kode_huruf, string tipe, int harga);

    /**
     * Destruktor makhluk
     */
    virtual ~Makhluk();

    /**
     * @return boolean apakah makhluk siap dipanen (true) atau belum (false)
     */
    virtual bool siapPanen() = 0;
    

    // /**
    //  * @return kebutuhan makhluk
    // */
    // int getNeeds();

    /**
     * @return harga makhluk
    */
    int getHarga();

    /**
     * @return tipe makhluk
    */
    string getTipe();
};

#endif