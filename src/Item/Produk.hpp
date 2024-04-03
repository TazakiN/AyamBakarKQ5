#ifndef PRODUK_HPP
#define PRODUK_HPP

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
        /**
         * @brief Konstruktor produk
         *
         * @param nama nama pemain
         * @param kode_huruf
         */
        Produk(string nama, string kode_huruf, int id, string tipe, string origin, int pertambahan_berat, float harga);

        /**
         * Destruktor item
         */
        virtual ~Produk();

        /**
         * Mengembalikan tipe item
         *
         * @return kode tipe item
         */
        string getTipe();

        /**
         * Mengembalikan origin item
         *
         * @return origin item
         */
        string getOrigin();

        /**
         * Mengembalikan pertambahan berat item
         *
         * @return pertambahan berat item
         */
        int getPertambahanBerat();
        
        /**
         * Mengembalikan harga item
         *
         * @return harga item
         */
        float getHarga();

        /**
         * Mengembalikan boolean apakah produk ini bisa dimakan
        */
        bool isMakanan();

        /**
         * operator assignment
         * 
        */
        Produk& operator=(const Produk& other);

        /**
         * operator pembanding untuk tipe produk
        */
        bool operator==(const Produk& other);
};


#endif