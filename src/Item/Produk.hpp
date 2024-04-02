#include "Item.hpp"

class Produk : public Item 
{
private:
    int id;
    string tipe;
    string origin;
    int pertambahan_berat;
    float harga;

public:


public:
    /**
     * @brief Konstruktor produk
     *
     * @param nama nama pemain
     * @param kode_huruf
     */
    Produk(string nama, string kode_huruf);

    /**
     * Destruktor item
     */
    virtual ~Produk();

    /**
     * Mengembalikan tipe item
     *
     * @return kode tipe item
     */
    string getType();
    
    Produk& operator=(const Produk& other);
};
