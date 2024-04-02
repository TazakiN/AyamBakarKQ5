#include <iostream>
#include "utils/readFile.h"
#include "utils/pcolor.hpp"
#include "Item/Herbivora.hpp"
#include "Item/Karnivora.hpp"
#include "Item/Omnivora.hpp"
#include "Item/Tanaman.hpp"

using namespace std;

int main()
{
    string filename = "config/animal.txt";
    stringstream buffer = bacaFile(filename);
    cout << p_magenta() <<buffer.str() << reset() << endl;

    // /* TEST HEWAN */
    // Herbivora cow("Sapi", "SPI", "HERBIVORE", 1000, 100, 500);
    // Karnivora snake("Ular", "ULR", "CARNIVORE", 500, 50, 100);
    // Omnivora chicken("Ayam", "CHN", "OMNIVORE", 700, 70, 200);

    // Produk grass("Rumput", "RPT", 5, "PRODUCT_FRUIT_PLANT", "TEAK_TREE ", 5, 50);
    // Produk meat("Daging", "DGT", 6, "PRODUCT_ANIMAL", "COW", 10, 100);

    // cow.makan(grass);
    // snake.makan(meat);
    // chicken.makan(grass);
    // cow.makan(meat);

    // /* TEST TANAMAN */
    // Tanaman wheat("Oak", "OAK", "MATERIAL_PLANT", 4, 4, 5); // Tanaman bahan baku (oak) dengan umur 4 dan durasi untuk panen 5
    // Tanaman apple("Apple", "APL", "FRUIT_PLANT", 6, 8, 5); // Tanaman buah (apel) dengan umur 6 dan durasi untuk panen 5

    // // Memeriksa apakah tanaman sudah siap panen
    // std::cout << wheat.getName() << " is ready for harvest: " << wheat.siapPanen() << std::endl;
    // std::cout << apple.getName() << " is ready for harvest: " << apple.siapPanen() << std::endl;


    return 0;
}
