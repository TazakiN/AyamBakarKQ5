#include "Omnivora.hpp"

Omnivora::Omnivora(string nama, string kode_huruf, int pertambahanBerat, int harga, int berat, int beratUntukPanen) : Hewan(nama, kode_huruf, pertambahanBerat, harga, berat, beratUntukPanen)
{
}

Omnivora::~Omnivora()
{
}

void Omnivora::makan(Produk &makanan)
{
    if (makanan.getTipe() == "PRODUCT_ANIMAL" || makanan.getTipe() == "PRODUCT_FRUIT_PLANT"){
        std::cout << p_green() << "Test: Hewan omnivora makan " << makanan.getName() << std::endl << reset();
        this->berat += makanan.getPertambahanBerat();
    }
    else {
        std::cout << p_red() << "Test: Hewan omnivora tidak bisa makan " << makanan.getName() << std::endl << reset();
    }
}