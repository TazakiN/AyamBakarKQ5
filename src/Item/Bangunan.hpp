#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include "Item.hpp"
#include <map>

/**
 * @brief Kelas Bangunan
 * untuk setiap bangunan yang diconstruct, akan memiliki resep
 * masukkan resep bangunan yang baru diconstruct dengan menggunakan
 * method tambahResep() - bisa tambah berkali-kali
 * 
 * contoh penggunaan:
 * Bangunan *rumah = new Bangunan("SMALL_HOUSE ", "SMH", 70);
 * rumah->tambahResep("ALOE_WOOD", 4);
 * rumah->tambahResep("IRONWOOD_WOOD", 4);
 * Bangunan hotel("HOTEL", "HTL", 100);
 * hotel.tambahResep("ALOE_WOOD", 1000);
 * 
 * ikuti cara printResep() untuk akses semua resep
*/

class Bangunan : public Item
{
    private:
        map<string, int> resep;
    public:
        /**
         * @brief Konstruktor bangunan
         *
         * @param nama nama bangunan
         * @param kode_huruf
         * @param harga
         */
        Bangunan(string nama, string kode_huruf, int harga);

        /**
         * Destruktor bangunan
         */
        virtual ~Bangunan();

        /**
         * Menambahkan resep bangunan
         * 
         * @param material nama produk yang akan ditambahkan
         * @param kuantitas kuantitas produk yang akan ditambahkan
         */
        void tambahResep(string material, int kuantitas);

        /**
         * Mengembalikan resep bangunan
        */
        map<string, int> getResep();

        /**
         * menampilkan reseo bangunan
        */
        void printResep();
};

#endif 