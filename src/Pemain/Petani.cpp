#include "Petani.hpp"
#include <vector>
#include <map>

Petani::Petani(string name, int row, int col) : Proletar(name, row, col)
{
    ladang = new Ladang(row, col);
}

Petani::~Petani()
{
    delete ladang;
}

void Petani::tanam()
{
    Inventory *inventory = getInventory();

    // pilih tanaman dari penyimpanan
    cout << "Pilih tanaman dari penyimpanan: " << endl;
    inventory->printGridHeader();
    inventory->printGrid();

    string slot;
    cout << "\nSlot: ";
    cin >> slot;

    // cek slot yang dipilih
    int inv_col = slot[0] - 'A';
    int inv_row = stoi(slot.substr(1)) - 1;
    if (inv_col < 0 || inv_col >= inventory->getRow() || inv_row < 0 || inv_row >= inventory->getCol())
    {
        cout << "Slot yang dipilih tidak valid." << endl;
        return;
    }

    // cek apakah item di slot yang dipilih adalah tanaman
    Item *item = ladang->getItem(inv_row, inv_col);
    Tanaman *tanaman = dynamic_cast<Tanaman *>(item);
    if (tanaman == nullptr)
    {
        cout << "Item yang dipilih bukan tanaman." << endl;
        return;
    }

    cout << "Kamu memilih " << tanaman->getName() << endl;

    // pilih petak di ladang
    cout << "\nPilih petak tanah yang akan ditanami: " << endl;
    ladang->printLadangWithHeader();

    string petak;
    cout << "\nPetak tanah: ";
    cin >> petak;

    // cek apakah petak yang dipilih valid
    int farm_col = petak[0] - 'A';
    int farm_row = stoi(petak.substr(1)) - 1;
    if (farm_col < 0 || farm_col >= ladang->getRow() || farm_row < 0 || farm_row >= ladang->getCol())
    {
        cout << "Petak yang dipilih tidak valid." << endl;
        return;
    }

    // cek apakah petak ladang kosong
    if (ladang->getItem(farm_row, farm_col) != nullptr)
    {
        cout << "Petak ladang sudah terisi." << endl;
        return;
    }

    // pindahin tumbuhan ke petak ladang
    ladang->setItem(farm_row, farm_col, tanaman);
    inventory->removeItem(inv_row, inv_col);

    cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
    cout << tanaman->getName() << " berhasil ditanam" << endl;
}

void Petani::tambahDurasiTanamanDiLadang()
{
    for (int i = 0; i < ladang->getRow(); i++)
    {
        for (int j = 0; j < ladang->getCol(); j++)
        {
            Item *item = ladang->getItem(i, j);
            if (item != nullptr)
            {
                Tanaman *tanaman = dynamic_cast<Tanaman *>(item);
                if (tanaman != nullptr)
                {
                    tanaman->tambahDurasiTanaman();
                }
            }
        }
    }
}

void Petani::CetakPetak()
{
    ladang->printLadangWithHeader();
}

void Petani::Panen() 
{
    Petani::CetakPetak();

    // daftar petak yang siap panen
    for (int i = 1; i <= ladang->getRow(); i++) {
        for (int j = 1; j <= ladang->getCol(); j++) {
            Tanaman* tanaman = ladang->getItem(i, j);
            if (tanaman != nullptr && tanaman->Makhluk::siapPanen()) {
                // Menyesuaikan lebar kolom untuk nomor baris
                string nomor_baris = to_string(i + 1);
                if (nomor_baris.length() == 1) {
                    nomor_baris = "0" + nomor_baris;
                }
                cout << " - " << (char)('A' + j) << nomor_baris << ": " << tanaman->getName() << endl;
            }
        }
    }

    // daftar tanaman yg siap panen pke vector
    vector<string> tanaman_siap_panen;
    // key = nama tanaman siap panen, value = brp byk petak dia
    map<string, int> petak_tanaman_siap_panen;

    for (int i = 1; i <= ladang->getRow(); i++)
    {
        for (int j = 1; j <= ladang->getCol(); j++)
        {
            Tanaman *tanaman = static_cast<Tanaman *>(ladang->getItem(i, j));
            if (tanaman != nullptr && tanaman->Makhluk::siapPanen())
            {
                string jenis_tanaman = tanaman->getKode();
                if (petak_tanaman_siap_panen.find(jenis_tanaman) == petak_tanaman_siap_panen.end())
                {
                    tanaman_siap_panen.push_back(jenis_tanaman);
                    petak_tanaman_siap_panen[jenis_tanaman] = 1;
                }
                else
                {
                    petak_tanaman_siap_panen[jenis_tanaman]++;
                }
            }
        }
    }

    // display tanaman siap panen
    cout << "\nPilih tanaman siap panen yang kamu miliki: \n";
    for (int i = 0; i < tanaman_siap_panen.size(); ++i)
    {
        cout << i + 1 << ". " << tanaman_siap_panen[i] << " (" << petak_tanaman_siap_panen[tanaman_siap_panen[i]] << " petak siap panen)" << endl;
    }

    // pilih jenis tanaman yang mau dipanen
    int pilihan;
    cout << "\nNomor tanaman yang ingin dipanen: ";
    cin >> pilihan;
    pilihan--;

    // validasi tanaman
    if (pilihan < 0 || pilihan >= tanaman_siap_panen.size())
    {
        cout << "Pilihan tanaman tidak valid." << endl;
        return;
    }

    string jenis_tanaman_dipanen = tanaman_siap_panen[pilihan];
    int jumlah_petak_siap_panen = petak_tanaman_siap_panen[jenis_tanaman_dipanen];

    // input jumlah petak yang mau dipanen
    int jumlah_petak_dipanen;
    cout << "\nBerapa petak yang ingin dipanen: ";
    cin >> jumlah_petak_dipanen;

    // validasi jumlah petak yang mau dipanen
    if (jumlah_petak_dipanen <= 0 || jumlah_petak_dipanen > jumlah_petak_siap_panen)
    {
        cout << "Jumlah petak yang ingin dipanen tidak valid." << endl;
        return;
    }

    // memilih petak untuk dipanen
    cout << "\nPilih petak yang ingin dipanen:\n";
    vector<string> petak_dipanen;
    for (int i = 1; i <= jumlah_petak_dipanen; i++)
    {
        string petak;
        cout << "Petak ke-" << i << ": ";
        cin >> petak;

        // validasi petak
        int row = stoi(petak.substr(1)) - 1;
        int col = petak[0] - 'A';

        if (row < 0 || row >= ladang->getRow() || col < 0 || col >= ladang->getCol())
        {
            cout << "Petak tidak valid." << endl;
            return;
        }

        Tanaman *tanaman = static_cast<Tanaman *>(ladang->getItem(row, col));
        if (tanaman == nullptr || tanaman->getKode() != jenis_tanaman_dipanen || !tanaman->Makhluk::siapPanen())
        {
            cout << "Petak tidak valid atau tanaman belum siap dipanen." << endl;
            return;
        }

        petak_dipanen.push_back(petak);
    }

    // menampilkan hasil panen
    cout << endl
         << jumlah_petak_dipanen << " petak tanaman " << jenis_tanaman_dipanen << " pada ";
    for (int i = 0; i < petak_dipanen.size(); ++i)
    {
        if (i > 0)
            cout << ", ";
        cout << petak_dipanen[i];
    }
    cout << " telah dipanen!" << endl;

    // add hasil panen ke inventory
    // BELUM pasti?
    Inventory *inventory = getInventory();
    for (const string &petak : petak_dipanen)
    {
        // row col petak
        // item dari peternakan
        // item -> produk
        // gimana dapetin hasilnya?
        // inventory->setItem(row, col, produk);

        // Bener ga begini? @denoseu --------------------
        int row = stoi(petak.substr(1)) - 1;
        int col = petak[0] - 'A';

        Tanaman* tanaman = ladang->getItem(row, col);
        vector<Produk*> hasilPanen = tanaman->konversiPanen();
        for (Produk* produk : hasilPanen) {
            inventory->setItem(row, col, produk);
        }
        // ----------------------------------------------
    }
    
}

float Petani::HitungPajak()
{
    float ktkp = 13;
    float kkp = getGulden();
    float tarif;
    if (kkp <= 6)
    {
        tarif = 0.05;
    }
    else if (6 < kkp && kkp <= 25)
    {
        tarif = 0.15;
    }
    else if (25 < kkp && kkp <= 50)
    {
        tarif = 0.25;
    }
    else if (50 < kkp & kkp <= 500)
    {
        tarif = 0.30;
    }
    else
    {
        tarif = 0.35;
    }

    return (hitungKekayaan() - ktkp) * tarif;
}

float Petani::hitungKekayaan()
{
    int total_kekayaan = 0;

    // hitung total kekayaan dari barang-barang di ladang
    for (int i = 0; i < ladang->getRow(); i++)
    {
        for (int j = 0; j < ladang->getCol(); j++)
        {
            Item *item = ladang->getItem(i, j);
            if (item != nullptr)
            {
                total_kekayaan += item->getHarga();
            }
        }
    }

    // hitung total kekayaan dari barang-barang di inventory
    Inventory *proletar_inventory = getInventory();
    for (int i = 0; i < proletar_inventory->getRow(); i++)
    {
        for (int j = 0; j < proletar_inventory->getCol(); j++)
        {
            Item *item = proletar_inventory->getItem(i, j);
            if (item != nullptr)
            {
                total_kekayaan += item->getHarga();
            }
        }
    }

    return total_kekayaan;
}

Ladang *Petani::getLadang()
{
    return ladang;
}

void Petani::masukanTanamanKeLadang(Tanaman *tanaman, string posisi)
{
    pair<int, int> pos = positionStringToPair(posisi);
    int row = pos.first;
    int col = pos.second;
    ladang->setItem(row, col, tanaman);
}

void Petani::saveMemento(Memento* m){
    ActionHistory* act_his = this->getActionHistory();
    act_his->pushMemento(m);
}