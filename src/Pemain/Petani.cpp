#include "Petani.hpp"

Petani::Petani(string name, int row, int col) : Proletar(name, row, col) {
    ladang = new Ladang(row, col);
}

Petani::~Petani() {
    delete ladang;
}

void Petani::tanam(Tanaman& nama_tanaman, int row, int col)
{
    // nanti
}

void Petani::CetakPetak() 
{
    ladang->printLadang();
}

void Petani::Panen() 
{
    // nanti
}

float Petani::HitungPajak() 
{
    float ktkp = 13;
    float kkp = getGulden();
    float tarif;
    if (kkp <= 6) {
        tarif = 0.05;
    } else if (6 < kkp && kkp <= 25) {
        tarif = 0.15;
    } else if (25 < kkp && kkp <= 50) {
        tarif = 0.25;
    } else if (50 < kkp & kkp <= 500) {
        tarif = 0.30;
    } else {
        tarif = 0.35;
    }

    return (hitungKekayaan()-ktkp)*tarif;
}

float Petani::hitungKekayaan() 
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
