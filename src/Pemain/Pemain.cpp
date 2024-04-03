#include "Pemain.hpp"

Pemain::Pemain(string name, int row, int col) : berat_badan(0), gulden(0), nama(name)
{
    inventory = new Inventory(row, col);
}

Pemain::~Pemain()
{
    delete inventory;
}

float Pemain::getBeratBadan()
{
    return berat_badan;
}

void Pemain::tambahBeratBadan(float bb)
{
    this->berat_badan += bb;
}

float Pemain::getGulden()
{
    return gulden;
}

void Pemain::tambahkanGulden(float g)
{
    this->gulden += g;
}

void Pemain::kurangiGulden(float g)
{
    this->gulden -= g;
}

string Pemain::getName()
{
    return nama;
}

void Pemain::keluarkanItem(int idx_row, int idx_col) {
    Item* item = inventory->getItem(idx_row, idx_col);

    if (item == nullptr) {
        cout << "Tidak ada item di posisi yang diberikan." << endl;
        return;
    }

    inventory->removeItem(idx_row, idx_col);

    cout << "Item berhasil dikeluarkan dari penyimpanan." << endl;
}

void Pemain::masukanItem(string nama_item, int idx_row, int idx_col) {
    Item* new_item = new Item(nama_item, "kode"); // "kode" masih temp, bingung gimana dapet kode?
    inventory->setItem(idx_row, idx_col, new_item);

    cout << "Item berhasil dimasukkan ke dalam penyimpanan." << endl;
}


void Pemain::beli(string nama_item, int kuantitas, int idx_row, int idx_col) 
{
    // cek apakah inventory cukup utk membeli
    if (inventory->isEmpty(kuantitas)) {
        cout << "Inventory Anda tidak cukup untuk membeli " << kuantitas << " " << nama_item << "." << endl;
        return;
    }

        // cek harga dari toko untuk barang yang ingin dibeli
        // int harga_per_barang = toko.getHarga(nama_item);
        int harga_per_barang = 10; // sementara
        int total_harga = harga_per_barang * kuantitas;

        // cek apakah gulden cukup
        if (gulden < total_harga) {
            cout << "Uang Anda tidak cukup untuk membeli " << kuantitas << " " << nama_item << "." << endl;
            return;
        }

        // membeli barang
        for (int i = 0; i < kuantitas; i++) {
            inventory->setItem(idx_row, idx_col + i, new Item(nama_item, "kode")); // "kode" masih temp, bingung gimana dapet kode?
        }

        // kurangi uang
        kurangiGulden(total_harga);
        cout << "Selamat Anda berhasil membeli " << kuantitas << " " << nama_item << ". Uang Anda tersisa " << gulden << " gulden." << endl;
}

void Pemain::jual(string nama_item, int kuantitas, int idx_row, int idx_col)
{
    // itung total harga jual
    // int harga_per_barang = toko.getHarga(nama_item);
    int harga_per_barang = 10; // sementara
    int total_harga = harga_per_barang * kuantitas;

    // menambah uang
    tambahkanGulden(total_harga);

    // menghapus barang dari inventory
    for (int i = 0; i < kuantitas; i++) {
        inventory->removeItem(idx_row, idx_col + i);
    }

    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << total_harga << " gulden." << endl;
}

void Pemain::makan() {
    // menampilkan isi penyimpanan
    cout << "Pilih makanan dari penyimpanan" << endl;
    inventory->printGridHeader();
    inventory->printGrid();

    // memilih makanan
    string slot;
    cout << "\nSlot: ";
    cin >> slot;

    // cek apakah slot yang dipilih valid
    int row = slot[0] - 'A';
    int col = stoi(slot.substr(1)) - 1;
    if (row < 0 || row >= inventory->getRow() || col < 0 || col >= inventory->getCol()) {
        cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
        return;
    }

    // cek apakah ada makanan di slot yang dipilih
    Item* item = inventory->getItem(row, col);
    // if (!item->isMakanan()) {
    //     cout << "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl;
    //     return;
    // }
    // gimana ya cek item itu makanan or no?

    // makan makanan
    string nama_makanan = item->getName();
    // int tambahan_berat_badan = gimana ambil tambahan berat badan dari makanan?
    int tambahan_berat_badan = 5; // sementara
    tambahBeratBadan(tambahan_berat_badan);

    // Menghapus makanan dari penyimpanan
    inventory->removeItem(row, col);

    cout << "\nDengan lahapnya, kamu memakan hidangan " << nama_makanan << endl;
    cout << "Alhasil, berat badan kamu naik menjadi " << berat_badan << endl;
}
