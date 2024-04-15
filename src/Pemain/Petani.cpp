#include "Petani.hpp"
#include "../Memento/PetaniMemento.hpp"
#include <vector>
#include <map>

Petani::Petani(string name, int row_inv, int col_inv, int row_lad, int col_lad) : Proletar(name, row_inv, col_inv)
{
    ladang = new Ladang(row_lad, col_lad);
}

Petani::~Petani()
{
    delete ladang;
}

void Petani::tanam()
{
    if (this->ladang->hitungKosong() == 0)
    {
        LadangPenuh e;
        throw e;
    }
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
        InvalidGridSlot e;
        throw e;
    }

    // cek apakah item di slot yang dipilih adalah tanaman
    Item *item = inventory->getItem(inv_row, inv_col);
    Tanaman *tanaman = dynamic_cast<Tanaman *>(item);
    if (tanaman == nullptr)
    {
        BukanTanaman e;
        throw e;
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
        PetakTidakValid e;
        throw e;
    }

    // cek apakah petak ladang kosong
    if (ladang->getItem(farm_row, farm_col) != nullptr)
    {
        PetakSudahTerisi e;
        throw e;
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

    cout << endl;

    map<string, string> list_tanaman;

    for (int i = 0; i < ladang->getRow(); i++) {
        for (int j = 0; j < ladang->getCol(); j++) {
            Tanaman* tanaman = static_cast<Tanaman*>(ladang->getItem(i, j));
            if (ladang->getItem(i, j) != nullptr) {
                string jenis_tanaman = tanaman->getKode();
                string nama_tanaman = tanaman->getName();
                if (list_tanaman.find(jenis_tanaman) == list_tanaman.end()) {
                    list_tanaman[jenis_tanaman] = nama_tanaman;
                }
            } else {
                continue;
            }
        }
    }

    for (const auto& pair : list_tanaman) {
        cout << " - " << pair.first << ": " << pair.second << endl;
    }
}

void Petani::Panen()
{
    Petani::CetakPetak();

    // daftar petak yang siap panen
    for (int i = 0; i < ladang->getRow(); i++)
    {
        for (int j = 0; j < ladang->getCol(); j++)
        {
            Tanaman *tanaman = ladang->getItem(i, j);
            if (tanaman != nullptr && tanaman->Makhluk::siapPanen())
            {
                // Menyesuaikan lebar kolom untuk nomor baris
                string nomor_baris = to_string(i + 1);
                if (nomor_baris.length() == 1)
                {
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

    for (int i = 0; i < ladang->getRow(); i++)
    {
        for (int j = 0; j < ladang->getCol(); j++)
        {
            Tanaman *tanaman = static_cast<Tanaman *>(ladang->getItem(i, j));
            if (tanaman != nullptr) {
                // test print umur tanaman
                cout << "Umur tanaman: " << tanaman->getUmur() << endl;
            }
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


    if (tanaman_siap_panen.size() == 0)
    {
        cout << "Tidak ada tanaman yang siap dipanen." << endl;
        return;
    } else {
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
            PilihanTanamanInvalid e;
            throw e;
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
            PetakPanenInvalid e;
            throw e;
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
                PetakTidakValid e;
                throw e;
            }

            Tanaman *tanaman = static_cast<Tanaman *>(ladang->getItem(row, col));
            if (tanaman == nullptr || tanaman->getKode() != jenis_tanaman_dipanen)
            {
                PetakTidakValid e;
                throw e;

            }
            if (tanaman == nullptr || !tanaman->Makhluk::siapPanen())
            {
                BelumSiapPanen e;
                throw e;   
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

            Tanaman *tanaman = ladang->getItem(row, col);
            vector<Produk *> hasilPanen = tanaman->konversiPanen();
            for (Produk *produk : hasilPanen)
            {
                // cari slot kosong pada inventory
                bool found = false;
                for (int i = 0; i < inventory->getRow(); i++)
                {
                    for (int j = 0; j < inventory->getCol(); j++)
                    {
                        if (inventory->getItem(i, j) == nullptr)
                        {
                            inventory->setItem(i, j, produk);
                            found = true;
                            break;
                        }
                    }
                    if (found)
                    {
                        break;
                    }
                }
            }
            ladang->removeItem(row, col);
            // ----------------------------------------------
        }
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

string Petani::getTipePemain()
{
    return "Petani";
}

void Petani::undo(Toko* toko, vector<Pemain*>daftarPemain){
    Memento* m = this->getActionHistory()->topMemento();
    this->tambahBeratBadan(m->getBeratBadanMemento()-this->getBeratBadan());
    this->tambahkanGulden(m->getGuldenMemento()-this->getGulden());
    undoToko(toko,m);
    m->deleteCreatedItems();
    m->undoInventory(this->getInventory());
    if (dynamic_cast<PetaniMemento*>(m) != nullptr){
        PetaniMemento* pm = dynamic_cast<PetaniMemento*>(m);
        pm->undoLadang(this->getLadang());
    }
    this->getActionHistory()->popMemento();
}