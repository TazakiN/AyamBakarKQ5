#include "Proletar.hpp"

Proletar::Proletar(string name, int row, int col) : Pemain(name, row, col)
{
    ladang = new Inventory(row, col);
}

Proletar::~Proletar()
{
    delete ladang;
}

float Proletar::hitungKekayaan()
{
    int total_kekayaan = 0;
    
    // hitung total kekayaan dari barang-barang di ladang
    for (int i = 0; i < ladang->getRow(); i++) {
        for (int j = 0; j < ladang->getCol(); j++) {
            Item* item = ladang->getItem(i, j);
            if (item != nullptr) {
                total_kekayaan += item->getHarga();
            }
        }
    }

    // hitung total kekayaan dari barang-barang di inventory
    Inventory* proletar_inventory = getInventory();
    for (int i = 0; i < proletar_inventory->getRow(); i++) {
        for (int j = 0; j < proletar_inventory->getCol(); j++) {
            Item* item = proletar_inventory->getItem(i, j);
            if (item != nullptr) {
                total_kekayaan += item->getHarga();
            }
        }
    }

    return total_kekayaan;
}