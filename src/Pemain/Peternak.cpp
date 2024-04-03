#include "Peternak.hpp"

Peternak::Peternak(string name, int row, int col) : Proletar(name, row, col) {}

Peternak::~Peternak() {}

void Peternak::kasih_makan(int row, int col) {
    Inventory* ladang = getLadang();
    Hewan* hewan = dynamic_cast<Hewan*>(ladang->getItem(row, col));

    if (hewan == nullptr) {
        cout << "Tidak ada hewan di petak yang diberikan." << endl;
        return;
    }

    cout << "Kamu memilih " << hewan->getName() << "untuk diberi makan." << endl;
    
    // menampilkan isi penyimpanan
    cout << "Pilih pangan yang akan diberikan: " << endl;
    getInventory()->printGridHeader();
    getInventory()->printGrid();

    // meemilih makanan
    string slot;
    cout << "\nSlot: ";
    cin >> slot;

    // cek apakah slot yang dipilih valid
    int inv_row = slot[0] - 'A';
    int inv_col = stoi(slot.substr(1)) - 1;
    if (inv_row < 0 || inv_row >= getInventory()->getRow() || inv_col < 0 || inv_col >= getInventory()->getCol()) {
        // cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
        // cout << "Silahkan masukkan slot yang berisi makanan." << endl;
        // mau output kayak gitu apa throw exception?
        return;
    }

    // Cek apakah ada makanan di slot yang dipilih
    Item* item = getInventory()->getItem(inv_row, inv_col);
    Produk* produk = dynamic_cast<Produk*>(item);

    if (produk) {
        if (produk->isMakanan() == false) {
            // cout << "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl;
            // cout << "Silahkan masukkan slot yang berisi makanan." << endl;
            // mau output kayak gitu apa throw exception?
            return;
        } else {
            // makan makanan
            string nama_makanan = item->getName();
            // validasi makanannya cocok untuk tipe hewannya apa ngga?? (carnivore/herbivore/omnivore)
            // menambah berat badan hewan
            hewan->makan(*produk);
            // menghapus makanan dari penyimpanan
            getInventory()->removeItem(inv_row, inv_col);
            cout << "\n" << hewan->getName() << " sudah diberi makan dan beratnya menjadi " << hewan->getBerat() << endl;
            return;
        }
    } else {
        cout << "Item yang dipilih bukanlah makanan." << endl;
    }
}

void Peternak::ternak(int row, int col)
{
    // nanti
}

void Peternak::CetakPetak() {
    Inventory* ladang = getLadang();
    cout << "    ================[ Peternakan ]==================" << endl;
    cout << "       A     B     C     D     E     F     G     H   " << endl;
    cout << "     +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
    for (int i = 0; i < ladang->getRow(); i++) {
        if (i < 9) {
            cout << " ";
        }
        cout << i + 1 << "  |";
        for (int j = 0; j < ladang->getCol(); j++) {
            Item* item = ladang->getItem(i, j);
            if (item == nullptr) {
                cout << "     |";
            } else {
                Hewan* hewan = dynamic_cast<Hewan*>(item);
                if (hewan && hewan->siapPanen()) {
                    cout << " " << p_green() << hewan->getTipe().substr(0, 3) << reset() << " |";
                } else if (hewan) {
                    cout << " " << p_red() << hewan->getTipe().substr(0, 3) << reset() << " |";
                }
            }
        }
        cout << endl;
    cout << "     +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
    }
}

void Peternak::Panen()
{
    // nanti

}

float Peternak::HitungPajak() 
{
    float ktkp = 11;
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