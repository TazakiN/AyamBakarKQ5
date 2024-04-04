#include "Petani.hpp"

Petani::Petani(string name, int row, int col) : Proletar(name, row, col) {
    ladang = new Ladang(row, col);
}

Petani::~Petani() {
    delete ladang;
}

void Petani::tanam(int row, int col)
{
    Inventory* inventory = getInventory();

    // pilih tanaman dari penyimpanan
    cout << "Pilih tanaman dari penyimpanan: " << endl;
    inventory->printGridHeader();
    inventory->printGrid();

    string slot;
    cout << "\nSlot: ";
    cin >> slot;

    // cek slot yang dipilih
    int inv_row = slot[0] - 'A';
    int inv_col = stoi(slot.substr(1)) - 1;
    if (inv_row < 0 || inv_row >= inventory->getRow() || inv_col < 0 || inv_col >= inventory->getCol()) {
        cout << "Slot yang dipilih tidak valid." << endl;
        return;
    }

    // cek apakah item di slot yang dipilih adalah tanaman
    Item* item = ladang->getItem(inv_row, inv_col);
    Tanaman* tanaman = dynamic_cast<Tanaman*>(item);
    if (tanaman == nullptr) {
        cout << "Item yang dipilih bukan tanaman." << endl;
        return;
    }

    cout << "Kamu memilih " << tanaman->getName() << endl;
    
    // pilih petak di ladang
    cout << "\nPilih petak tanah yang akan ditanami: " << endl;
    ladang->printLadang();

    string petak;
    cout << "\nPetak tanah: ";
    cin >> petak;

    // cek apakah petak yang dipilih valid
    int field_row = petak[0] - 'A';
    int field_col = stoi(petak.substr(1)) - 1;
    if (field_row < 0 || field_row >= ladang->getRow() || field_col < 0 || field_col >= ladang->getCol()) {
        cout << "Petak yang dipilih tidak valid." << endl;
        return;
    }

    // cek apakah petak ladang kosong
    if (ladang->getItem(field_row, field_col) != nullptr) {
        cout << "Petak ladang sudah terisi." << endl;
        return;
    }

    // pindahin tumbuhan ke petak ladang
    ladang->setItem(field_row, field_col, tanaman);
    inventory->removeItem(inv_row, inv_col);

    cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
    cout << tanaman->getName() << " berhasil ditanam" << endl;
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
