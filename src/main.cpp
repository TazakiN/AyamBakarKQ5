#include <iostream>
#include "utils/readFile.h"
#include "utils/pcolor.hpp"
#include "Item/Herbivora.hpp"
#include "Item/Karnivora.hpp"
#include "Item/Omnivora.hpp"

using namespace std;

int main()
{
    string filename = "config/animal.txt";
    stringstream buffer = bacaFile(filename);
    cout << p_magenta() <<buffer.str() << reset() << endl;

    /* TEST HEWAN */
    // Herbivora cow("Sapi", "SPI", "HERBIVORE", 1000, 100, 500);
    // Karnivora snake("Ular", "ULR", "CARNIVORE", 500, 50, 100);
    // Omnivora chicken("Ayam", "CHN", "OMNIVORE", 700, 70, 200);

    // Produk grass("Rumput", "RPT", 5, "PRODUCT_FRUIT_PLANT", "TEAK_TREE ", 5, 50);
    // Produk meat("Daging", "DGT", 6, "PRODUCT_ANIMAL", "COW", 10, 100);

    // cow.makan(grass);
    // snake.makan(meat);
    // chicken.makan(grass);
    // cow.makan(meat);

    return 0;
}
