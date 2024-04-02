#include "Omnivora.hpp"

Omnivora::Omnivora(string nama, string kode_huruf, int pertambahanBerat, int harga, int berat, int beratUntukPanen) : Hewan(nama, kode_huruf, pertambahanBerat, harga, berat, beratUntukPanen)
{
}

Omnivora::~Omnivora()
{
}

void Omnivora::Makan(Produk &makanan)
{
    if (makanan.getTipe() == "PRODUCT_ANIMAL") {
        std::cout << "Test: Hewan omnivora makan " << makanan.getName() << std::endl;
        this->berat += makanan.getPertambahanBerat();
    }
    else {
        std::cout << "Test: Hewan omnivora tidak bisa makan " << makanan.getName() << std::endl;
    }
}