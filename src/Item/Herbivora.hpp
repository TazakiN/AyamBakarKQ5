#ifndef HERBIVORA_HPP
#define HERBIVORA_HPP

#include "Hewan.hpp"
#include "Produk.hpp"

class Herbivora : public Hewan
{
public:
    /**
     * @brief konstruktor hewan herbivora
     *
     * @param nama hewan herbivora
     * @param kode_huruf hewan herbivora
     * @param harga harga hewan herbivora
     * @param berat berat hewan herbivora
     * @param beratUntukPanen berat hewan herbivora untuk panen
     */
    Herbivora(string nama, string kode_huruf, string tipe, int harga, int berat, int beratUntukPanen);

    /**
     * Destruktor hewan herbivora
     */
    ~Herbivora();

    /**
     * Hewan herbivora makan
     * 
     * @param makanan yang akan dimakan
     */
    void makan(Produk &makanan);
};

#endif