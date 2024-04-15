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
#include "Pemain/Walikota.hpp"
#include "GameEngine/GameEngine.hpp"

using namespace std;

int main()
{
    // UTAMA
    GameEngine gameEngine;
    gameEngine.initGame();
    // Toko toko;
    // gameEngine.copyDataToToko(toko);
    // Bangunan *b = new Bangunan("BAN", "BAN", 20);
    // Bangunan *b2 = new Bangunan("BAN", "BAN", 20);
    // Bangunan *b3 = new Bangunan("BAN3", "BAN3", 20);
    // toko.addItem(b);
    // toko.addItem(b2);
    // toko.addItem(b3);
    // toko.displayToko(1);
    // cout << "total item: " << toko.getTotalItem() << endl;
    // string itemken = toko.getItemKeN(16);
    // cout << itemken << endl;
    // std::cout << "item 16: " << toko.getTotalItemKeN(16) << endl;
    // cout<< "item 17: "  << toko.getTotalItemKeN(17) << toko.getTotalItemKeN(17) << endl;

    // gameEngine.initGame();

    // Walikota* w = new Walikota("walikota", 7, 7);
    // w->tambahkanGulden(50);
    // gameEngine.copyRecipeToWalikota(*w);
    // Tanaman* t1 = new Tanaman("SANDAL_WOOD", "SDW", "Tanaman", 20, 20, 20);
    // Tanaman* t2 = new Tanaman("TEAK_WOOD", "TKW", "Tanaman", 20, 20, 20);
    // w->masukanItem(t1);
    // w->masukanItem(t2);
    // w->getInventory()->printInventory();
    // list <int> list1 = w->getListIdxBahanBangunan("SANDAL_WOOD");
    // cout << "list sandal wood" << endl;
    // list <int> list2 = w->getListIdxBahanBangunan("TEAK_WOOD");
    // cout << "list teak wood" << endl;
    // w->bangun();
    // w->getInventory()->printInventory();
    
    // gameEngine.initGame();
    // vector<vector<string>> listOfResepBangunan = {
    //     {"SMH", "SMALL_HOUSE", "50", "TEAK_WOOD", "1", "SANDAL_WOOD", "1"},
    //     {"BGH", "BIG_HOUSE", "50", "TEAK_WOOD", "6", "SANDAL_WOOD", "8"}
    // };
    // cout << "Resep bangunan yang ada adalah sebagai berikut:" << endl;
    // int count = 1;
    // for (const auto& resep : listOfResepBangunan) {
    //     cout << "    " << count++ << ". " << resep[1] << " (" << resep[2] << " gulden, ";
    //     for (size_t i = 3; i < resep.size(); i += 2) {
    //         cout << resep[i + 1] << " " << resep[i];
    //         if (i + 2 < resep.size()) {
    //             cout << ", ";
    //         }
    //     }
    //     cout << ")" << endl;
    // }

    // TEST TOKO

    // GameEngine gameEngine;
    // // gameEngine.readConfig();
    // gameEngine.initGame();

    // Toko toko;
    // gameEngine.copyDataToToko(toko);
    // Omnivora* duck= new Omnivora("DUCK", "DCK", "OMNIVORE", 3, 100, 11);
    // toko.addItem(duck);

    // std::cout << "Display ke walikota" << endl;
    // toko.displayToko(1);

    // Toko toko1;
    // Toko toko2;
    // toko2.copyToko(&toko1);

    // std::cout << "Display ke walikota toko 2" << endl;
    // toko.displayToko(2);

    // /* TEST hasilPanen @denoseu*/
    // GameEngine game;
    // game.initGame();

    // Inventory inventory(8, 8);

    // // string nama, string kode_huruf, string tipe, int harga, int berat, int beratUntukPanen
    // Omnivora duck("DUCK", "DCK", "OMNIVORE", 3, 100, 11);
    // if (duck.siapPanen()) {
    //     vector<Produk*> hasilPanen = duck.konversiPanen();
    //     int c = 0;
    //     for (Produk* p : hasilPanen) {
    //         inventory.setItem(0, c, p);
    //         cout << "Hasil panen: " << p->getName() << endl;
    //         cout << "Tipe: " << p->getTipe() << endl;
    //         cout << "Origin: " << p->getOrigin() << endl;
    //         cout << "Pertambahan berat: " << p->getPertambahanBerat() << endl;
    //         cout << "Harga: " << p->getHarga() << endl;
    //         c++;
    //     }
    // }
    // else {
    //     cout << "Hewan belum siap panen" << endl;
    // }

    // // string nama, string kode_huruf, string tipe, int umur, int harga, int durasiUntukPanen
    // Tanaman jambu("GUAVA_TREE", "GAV", "FRUIT_PLANT", 14, 3, 14);
    // if (jambu.siapPanen()) {
    //     vector<Produk*> hasilPanen2 = jambu.konversiPanen();
    //     for (Produk* p : hasilPanen2) {
    //         inventory.setItem(1, 0, p);
    //         cout << "Hasil panen: " << p->getName() << endl;
    //         cout << "Tipe: " << p->getTipe() << endl;
    //         cout << "Origin: " << p->getOrigin() << endl;
    //         cout << "Pertambahan berat: " << p->getPertambahanBerat() << endl;
    //         cout << "Harga: " << p->getHarga() << endl;
    //     }
    // }
    // else {
    //     cout << "Tanaman belum siap panen" << endl;
    // }

    // inventory.printGridHeader();
    // inventory.printGrid();

    // game.tambahPemain("Dama2", 2, 4, 4);
    // Walikota w ("Dama", 4, 4);
    // game.copyRecipeToWalikota(w);
    // Tanaman teak ("TEAK_WOOD", "TEK", "MATERIAL_WOOD", 3, 3, 3);
    // Tanaman sandal ("SANDAL_WOOD", "SDT", "MATERIAL_WOOD", 3, 3, 3);
    // w.masukanItem(teak, 1, 1);
    // w.masukanItem(sandal, 1, 2);
    // w.getInventory()->printGrid();
    // w.bangun("SMALL_HOUSE");
    // w.getInventory()->printGrid();

    // Toko toko;

    // game.copyDataToToko(toko);

    // Bangunan b1("SMALL_HOUSE", "SML", 50);
    // Bangunan b3("SMALL_HOUSE", "SML", 50);
    // Bangunan b4("LARGE_HOUSE", "LRG", 50);
    // Bangunan b2("HOTEL", "HTL", 250);
    // Karnivora k1 ("KUCING", "KCG", "karnivora", 12, 2, 12);
    // Tanaman t1 ("APPLE", "APL", "tanaman", 1, 10, 5);

    // toko.addItem(b1);
    // toko.addItem(b3);
    // toko.addItem(b2);
    // toko.addItem(k1);
    // toko.addItem(t1);

    // // Display ke walikota
    // cout << "display walikota" << endl;
    // toko.displayToko(1);
    // // cout << "display proletar" << endl;
    // // toko.displayToko(2);

    // list <Item> list;

    // list = toko.removeItem(17, 1, 56, 52);
    // toko.displayToko(1);

    // // Display ke proletar
    // cout << "display proletar" << endl;
    // toko.displayToko(2);

    // size_t i = 0;
    // cout << "size: " << game.listOfResepBangunan.size() << endl;

    // while (i < game.listOfResepBangunan.size()/2)
    // {
    //     cout << " i = " << i << endl;
    //     vector<string> recipe = game.listOfResepBangunan[i];

    //     std::cout << i + 1 << " ";

    //     for (const auto &ingredient : recipe)
    //     {
    //         std::cout << ingredient << " ";
    //     }
    //     std::cout << std::endl;

    //     ++i;
    // }

    // vector<string> firstRecipe = game.listOfResepBangunan[0];

    // size_t i = 0;

    // while (i < game.listOfResepBangunan.size())
    // {
    //     cout << game.listOfResepBangunan[i] << " ";
    //     ++i;
    // }

    // Toko toko;

    // toko.addItem(Item("APPLE_FRUIT", "a1", 10));
    // toko.addItem(Item("APPLE_FRUIT", "a1", 10));
    // toko.addItem(Item("LARGE_HOUSE", "b1", 15));
    // toko.addItem(Item("LARGE_HOUSE", "b1", 15));
    // toko.addItem(Item("APPLE_FRUIT", "a1", 10));
    // toko.addItem(Item("Cherry", "c1", 20));
    // toko.addItem(Item("Avocado", "d1", 20));
    // toko.addItem(Item("APPLE_FRUIT", "a4", 10));

    // toko.displayToko(1);

    // std::list<Item> removedItems = toko.removeItem(1, 1, 266, 46);

    // toko.displayToko(2);

    // string filename = "config/animal.txt";
    // stringstream buffer = bacaFile(filename);
    // cout << p_magenta() <<buffer.str() << reset() << endl;

    // /* TEST HEWAN */
    // Omnivora *cow = new Herbivora("Sapi", "SPI", "HERBIVORE", 1000, 100, 500);
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
