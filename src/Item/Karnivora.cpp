#include "Karnivora.hpp"

Karnivora::Karnivora(string nama, string kode_huruf, int pertambahanBerat, int harga, int berat, int beratUntukPanen) : Hewan(nama, kode_huruf, pertambahanBerat, harga, berat, beratUntukPanen)
{
}

Karnivora::~Karnivora()
{
}

void Karnivora::Makan(Produk &makanan)
{
    if (makanan.getTipe() == "PRODUCT_ANIMAL") {
        std::cout << "Test: Hewan karnivora makan " << makanan.getName() << std::endl;
        this->berat += makanan.getPertambahanBerat();
    }
    else {
        std::cout << "Test: Hewan karnivora tidak bisa makan " << makanan.getName() << std::endl;
    }
}