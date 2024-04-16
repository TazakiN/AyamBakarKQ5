#include "Herbivora.hpp"

Herbivora::Herbivora(string nama, string kode_huruf, string tipe, int harga, int berat, int beratUntukPanen) : Hewan(nama, kode_huruf, tipe, harga, berat, beratUntukPanen)
{
}

Herbivora::Herbivora(const Herbivora &other) : Hewan(other.getName(), other.getKode(), other.getTipe(), other.getHarga(), other.getProgressPanen(), other.getTargetPanen())
{
}

Herbivora::~Herbivora()
{
}

void Herbivora::makan(Produk &makanan)
{
    if (getTipe() == "HERBIVORE" && makanan.getTipe() == "PRODUCT_FRUIT_PLANT")
    {
        std::cout << p_green() << "Hewan herbivora makan " << makanan.getName() << std::endl
                  << reset();
        setProgressPanen(makanan.getPertambahanBerat() + getProgressPanen());
    }
    else
    {
        std::cout << p_red() << "Hewan herbivora tidak bisa makan " << makanan.getName() << std::endl
                  << reset();
    }
}