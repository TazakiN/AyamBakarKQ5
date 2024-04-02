#ifndef KARNIVORA_HPP
#define KARNIVORA_HPP

#include "Hewan.hpp"
#include "Produk.hpp"

class Karnivora : public Hewan
{
public:
    /**
     * @brief konstruktor hewan herbivora
     *
     * @param nama hewan herbivora
     * @param kode_huruf hewan herbivora
     * @param pertambahanBerat pertambahan berat hewan herbivora
     * @param harga harga hewan herbivora
     * @param berat berat hewan herbivora
     * @param beratUntukPanen berat hewan herbivora untuk panen
     */
    Karnivora(string nama, string kode_huruf, int pertambahanBerat, int harga, int berat, int beratUntukPanen);

    /**
     * Destruktor hewan karnivora
     */
    ~Karnivora();

    /**
     * Hewan karnivora makan
     * 
     * @param makanan yang akan dimakan
     */
    void makan(Produk &makanan);
};

#endif