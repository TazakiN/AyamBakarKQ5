#include <iostream>
#include "utils/readFile.h"
#include "utils/pcolor.hpp"
#include "Item/Herbivora.hpp"
#include "Item/Karnivora.hpp"
#include "Item/Omnivora.hpp"
#include "Item/Tanaman.hpp"
#include "Grid/Inventory.hpp"
#include "Item/Bangunan.hpp"
#include "Grid/Toko.hpp"

using namespace std;

int main()
{
    Toko toko;

    toko.addItem(Item("APPLE_FRUIT", "a1", 10));
    toko.addItem(Item("APPLE_FRUIT", "a1", 10));
    toko.addItem(Item("LARGE_HOUSE", "b1", 15));
    toko.addItem(Item("LARGE_HOUSE", "b1", 15));
    toko.addItem(Item("APPLE_FRUIT", "a1", 10));
    toko.addItem(Item("Cherry", "c1", 20));
    toko.addItem(Item("Avocado", "d1", 20));
    toko.addItem(Item("APPLE_FRUIT", "a4", 10));

    toko.displayToko(1);

    std::list<Item> removedItems = toko.removeItem(1, 1, 266, 46);

    // toko.displayToko(2);
 

    // string filename = "config/animal.txt";
    // stringstream buffer = bacaFile(filename);
    // cout << p_magenta() <<buffer.str() << reset() << endl;

    // /* TEST HEWAN */
    // Herbivora *cow = new Herbivora("Sapi", "SPI", "HERBIVORE", 1000, 100, 500);
    // Karnivora *snake = new Karnivora("Ular", "ULR", "CARNIVORE", 500, 50, 100);
    // Omnivora *chicken = new Omnivora("Ayam", "CHN", "OMNIVORE", 700, 70, 200);

    // Produk *grass = new Produk("Rumput", "RPT", 5, "PRODUCT_FRUIT_PLANT", "TEAK_TREE ", 5, 50);
    // Produk *meat = new Produk("Daging", "DGT", 6, "PRODUCT_ANIMAL", "COW", 10, 100);

    // cow->makan(*grass);
    // snake->makan(*meat);
    // chicken->makan(*grass);
    // cow->makan(*meat);

    // /* TEST INVENTORY */
    // Inventory inventory(8, 8);
    // inventory.setItem(0, 0, cow);
    // inventory.setItem(0, 1, snake);
    // inventory.setItem(0, 2, chicken);

    // inventory.printGridHeader();
    // inventory.printGrid();

    // /* TEST TANAMAN */
    // Tanaman wheat("Oak", "OAK", "MATERIAL_PLANT", 4, 4, 5); // Tanaman bahan baku (oak) dengan umur 4 dan durasi untuk panen 5
    // Tanaman apple("Apple", "APL", "FRUIT_PLANT", 6, 8, 5); // Tanaman buah (apel) dengan umur 6 dan durasi untuk panen 5

    // // Memeriksa apakah tanaman sudah siap panen
    // std::cout << wheat.getName() << " is ready for harvest: " << wheat.siapPanen() << std::endl;
    // std::cout << apple.getName() << " is ready for harvest: " << apple.siapPanen() << std::endl;

    // /* TEST BANGUNAN */
    // Bangunan *rumah = new Bangunan("SMALL_HOUSE", "SMH", 70);
    // Bangunan hotel("HOTEL", "HTL", 100);

    // rumah->tambahResep("ALOE_WOOD", 4);
    // rumah->tambahResep("IRONWOOD_WOOD", 4);
    // hotel.tambahResep("ALOE_WOOD", 1000);

    // rumah->printResep();
    // hotel.printResep();

    return 0;
}
