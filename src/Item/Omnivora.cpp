#include "Omnivora.hpp"

Omnivora::Omnivora(string nama, string kode_huruf, string tipe, int harga, int berat, int beratUntukPanen) : Hewan(nama, kode_huruf, tipe, harga, berat, beratUntukPanen)
{
}

Omnivora::Omnivora(const Omnivora &other) : Hewan(other.getName(), other.getKode(), other.getTipe(), other.getHarga(), other.getProgressPanen(), other.getTargetPanen())
{
}

Omnivora::~Omnivora()
{
}

void Omnivora::makan(Produk &makanan)
{
    if (getTipe() == "OMNIVORE" && makanan.getTipe() == "PRODUCT_ANIMAL" || makanan.getTipe() == "PRODUCT_FRUIT_PLANT")
    {
        std::cout << p_green() << "Test: Hewan omnivora makan " << makanan.getName() << std::endl
                  << reset();
        setProgressPanen(makanan.getPertambahanBerat() + getProgressPanen());
    }
    else
    {
        std::cout << p_red() << "Test: Hewan omnivora tidak bisa makan " << makanan.getName() << std::endl
                  << reset();
    }
}