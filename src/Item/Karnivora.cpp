#include "Karnivora.hpp"

Karnivora::Karnivora(string nama, string kode_huruf, string tipe, int harga, int berat, int beratUntukPanen) : Hewan(nama, kode_huruf, tipe, harga, berat, beratUntukPanen)
{
}

Karnivora::~Karnivora()
{
}

void Karnivora::makan(Produk &makanan)
{
    if (getTipe() == "CARNIVORE" && makanan.getTipe() == "PRODUCT_ANIMAL") {
        std::cout << p_green() << "Test: Hewan karnivora makan " << makanan.getName() << std::endl << reset();
        this->berat += makanan.getPertambahanBerat();
    }
    else {
        std::cout << p_red() << "Test: Hewan karnivora tidak bisa makan " << makanan.getName() << std::endl << reset();
    }
}