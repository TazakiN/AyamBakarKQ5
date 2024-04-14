#include "Pemain.hpp"

Pemain::Pemain(string name, int row, int col) : berat_badan(0), gulden(0), nama(name)
{
    inventory = new Inventory(row, col);
    action_history = new ActionHistory();
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

void Pemain::keluarkanItem(int idx_row, int idx_col)
{
    Item *item = inventory->getItem(idx_row, idx_col);

    if (item == nullptr)
    {
        cout << "Tidak ada item di posisi yang diberikan." << endl;
        return;
    }

    inventory->removeItem(idx_row, idx_col);

    cout << "Item berhasil dikeluarkan dari penyimpanan." << endl;
}

void Pemain::masukanItem(Item nama_item, int idx_row, int idx_col)
{
    Item *new_item = new Item(nama_item);
    inventory->setItem(idx_row, idx_col, new_item);

    cout << "Item berhasil dimasukkan ke dalam penyimpanan." << endl;
}

void Pemain::masukanItem(Item *item)
{
    // cari slot kosong di inventory
    int tempRow = 0;
    int tempCol = 0;
    while (inventory->getItem(tempRow, tempCol) != nullptr)
    {
        tempCol++;
        if (tempCol == inventory->getCol())
        {
            tempCol = 0;
            tempRow++;
        }
    }

    inventory->setItem(tempRow, tempCol, item);
}

void Pemain::beli(Item nama_item, int kuantitas, int idx_row, int idx_col)
{
    // cek apakah inventory cukup utk membeli
    if (inventory->isEmpty(kuantitas))
    {
        cout << "Inventory Anda tidak cukup untuk membeli " << kuantitas << " " << nama_item.getName() << "." << endl;
        return;
    }

    // cek harga dari toko untuk barang yang ingin dibeli
    int harga_per_barang = nama_item.getHarga();
    int total_harga = harga_per_barang * kuantitas;

    // cek apakah gulden cukup
    if (gulden < total_harga)
    {
        cout << "Uang Anda tidak cukup untuk membeli " << kuantitas << " " << nama_item.getName() << "." << endl;
        return;
    }

    // membeli barang
    for (int i = 0; i < kuantitas; i++)
    {
        inventory->setItem(idx_row, idx_col + i, new Item(nama_item));
    }

    // kurangi uang
    kurangiGulden(total_harga);
    cout << "Selamat Anda berhasil membeli " << kuantitas << " " << nama_item.getName() << ". Uang Anda tersisa " << gulden << " gulden." << endl;
}

void Pemain::jual(vector<string> posisiItemDijual)
{
    int total_uang_tambahan = 0;

    // cari harga item dan hapus item dari inventory
    for (const string &posisi : posisiItemDijual)
    {
        pair<int, int> koor = positionStringToPair(posisi);
        int row = koor.first;
        int col = koor.second;
        int hargaItem = inventory->getItem(row, col)->getHarga();
        total_uang_tambahan += hargaItem;
        inventory->removeItem(row, col);
    }

    // menambah uang
    tambahkanGulden(total_uang_tambahan);
    // NANTI TAMBAHIN KALO MISALNYA JUAL BANGUNAN, KURANGIN STOKKKKKK
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << total_uang_tambahan << " gulden." << endl;
}

void Pemain::makan()
{
    while (true)
    {
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
        if (row < 0 || row >= inventory->getRow() || col < 0 || col >= inventory->getCol())
        {
            cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
            cout << "Silahkan masukan slot yang berisi makanan." << endl;
            continue;
        }

        // cek apakah ada makanan di slot yang dipilih
        Item *item = inventory->getItem(row, col);
        Produk *produk = dynamic_cast<Produk *>(item);

        if (produk)
        {
            if (produk->isMakanan() == false)
            {
                cout << "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl;
                cout << "Silahkan masukan slot yang berisi makanan." << endl;
                continue;
            }
            else
            {
                // makan makanan
                string nama_makanan = item->getName();
                // int tambahan_berat_badan = gimana ambil tambahan berat badan dari makanan?
                int tambahan_berat_badan = 5; // sementara
                tambahBeratBadan(tambahan_berat_badan);

                // Menghapus makanan dari penyimpanan
                inventory->removeItem(row, col);

                cout << "\nDengan lahapnya, kamu memakan hidangan " << nama_makanan << endl;
                cout << "Alhasil, berat badan kamu naik menjadi " << berat_badan << endl;
                break;
            }
        }
    }
}

Inventory *Pemain::getInventory()
{
    return inventory;
}

ActionHistory *Pemain::getActionHistory()
{
    return action_history;
}

void Pemain::saveMemento(Memento *m)
{
    ActionHistory *act_his = this->getActionHistory();
    act_his->pushMemento(m);
}