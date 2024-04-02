#include "Herbivora.hpp"

Herbivora::Herbivora(string nama, string kode_huruf, int pertambahanBerat, int harga, int berat, int beratUntukPanen) : Hewan(nama, kode_huruf, pertambahanBerat, harga, berat, beratUntukPanen)
{
}

Herbivora::~Herbivora()
{
}

void Herbivora::Makan(Produk &makanan)
{
    if (makanan.getTipe() == "PRODUCT_MATERIAL_PLANT" || makanan.getTipe() == "PRODUCT_FRUIT_PLANT") {
        std::cout << "Test: Hewan herbivora makan " << makanan.getName() << std::endl;
        this->berat += makanan.getPertambahanBerat();
    }
    else {
        std::cout << "Test: Hewan herbivora tidak bisa makan " << makanan.getName() << std::endl;
    }
}