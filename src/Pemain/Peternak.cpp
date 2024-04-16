#include "Peternak.hpp"
#include "../Memento/PeternakMemento.hpp"
#include <vector>
#include <map>

Peternak::Peternak(string name, int row_inv, int col_inv, int row_peternakan, int col_peternakan) : Proletar(name, row_inv, col_inv)
{
    peternakan = new Peternakan(row_peternakan, col_peternakan);
}

Peternak::~Peternak()
{
    delete peternakan;
}

void Peternak::kasih_makan(int row, int col)
{
    Hewan *hewan = static_cast<Hewan *>(peternakan->getItem(row, col));

    if (hewan == nullptr)
    {
        BukanHewan e;
        throw e;
    }

    cout << "Kamu memilih " << hewan->getName() << " untuk diberi makan." << endl;

    // menampilkan isi penyimpanan
    cout << "Pilih pangan yang akan diberikan: " << endl;
    getInventory()->printGridHeader();
    getInventory()->printGrid();

    // meemilih makanan
    string slot;
    cout << "\nSlot: ";
    cin >> slot;

    // cek apakah slot yang dipilih valid
    int inv_row = stoi(slot.substr(1)) - 1;
    int inv_col = slot[0] - 'A';
    if (inv_row < 0 || inv_row >= getInventory()->getRow() || inv_col < 0 || inv_col >= getInventory()->getCol())
    {
        PetakTidakValid e;
        throw e;
    }

    // test print inv_row dan inv_col
    cout << "inv_row: " << inv_row << endl;
    cout << "inv_col: " << inv_col << endl;
    // Cek apakah slot kosong
    Item *item = getInventory()->getItem(inv_row, inv_col);
    if (item == nullptr)
    {
        SlotKosong e;
        throw e;
    }
    // test print getname item
    // cout << "item yang dipilih: " << item->getName() << endl;

    // cek apakah item bukan merupakan produk, throw exception jika bukan
    Produk *produk = dynamic_cast<Produk *>(item);
    if (produk == nullptr)
    {   
        BukanMakanan e;
        throw e;
    }

    // test print getname produk
    cout << "produk yang dipilih: " << produk->getName() << endl;
    // test print gettipe produk
    cout << "tipe produk yang dipilih: " << produk->getTipe() << endl;
    if (produk)
    {   
        // test print gettipe hewan
        cout << "tipe hewan: " << hewan->getTipe() << endl;
        // test print gettipe produk
        cout << "tipe produk: " << produk->getTipe() << endl;
        
        if ((hewan->getTipe() == "CARNIVORE" && produk->getTipe() == "PRODUCT_ANIMAL") ||
            (hewan->getTipe() == "HERBIVORE" && produk->getTipe() == "PRODUCT_FRUIT_PLANT") ||
            (hewan->getTipe() == "OMNIVORE" && (produk->getTipe() == "PRODUCT_ANIMAL" || produk->getTipe() == "PRODUCT_FRUIT_PLANT")))
        {
            // makan makanan
            hewan->makan(*produk);
            // menghapus makanan dari penyimpanan
            getInventory()->removeItem(inv_row, inv_col);
            cout << "\n"
                 << hewan->getName() << " sudah diberi makan dan beratnya menjadi " << hewan->getBerat() << endl;
        }
        else
        {
            WrongFood e;
            throw e;
        }
    }
    else
    {
        BukanMakanan e;
        throw e;
    }
}

void Peternak::Panen()
{
    Peternak::CetakPetak();

    // daftar petak yang siap panen
    for (int i = 0; i < peternakan->getRow(); i++)
    {
        for (int j = 0; j < peternakan->getCol(); j++)
        {
            Hewan *hewan = static_cast<Hewan *>(peternakan->getItem(i, j));
            if (hewan != nullptr && hewan->Makhluk::siapPanen())
            {
                // Menyesuaikan lebar kolom untuk nomor baris
                string nomor_baris = to_string(i + 1);
                if (nomor_baris.length() == 1)
                {
                    nomor_baris = "0" + nomor_baris;
                }
                cout << " - " << (char)('A' + j) << nomor_baris << ": " << hewan->getName() << endl;
            }
        }
    }

    // daftar hewan yg siap panen pke vector??
    vector<string> hewan_siap_panen;
    // key = nama hewan siap panen, value = brp byk petak dia
    map<string, int> petak_hewan_siap_panen;

    for (int i = 0; i < peternakan->getRow(); i++)
    {
        for (int j = 0; j < peternakan->getCol(); j++)
        {
            Hewan *hewan = static_cast<Hewan *>(peternakan->getItem(i, j));
            if (hewan != nullptr && hewan->Makhluk::siapPanen())
            {
                string jenis_hewan = hewan->getKode();
                if (petak_hewan_siap_panen.find(jenis_hewan) == petak_hewan_siap_panen.end())
                {
                    hewan_siap_panen.push_back(jenis_hewan);
                    petak_hewan_siap_panen[jenis_hewan] = 1;
                }
                else
                {
                    petak_hewan_siap_panen[jenis_hewan]++;
                }
            }
        }
    }

    if (hewan_siap_panen.size() == 0)
    {
        cout << "Tidak ada hewan yang siap dipanen." << endl;
        return;
    } 
    else
    {
        // display hewan siap panen
        cout << "\nPilih hewan siap panen yang kamu miliki: \n";
        for (int i = 0; i < hewan_siap_panen.size(); ++i)
        {
            cout << i + 1 << ". " << hewan_siap_panen[i] << " (" << petak_hewan_siap_panen[hewan_siap_panen[i]] << " petak siap panen)" << endl;
        }

        // pilih jenis hewan yang mau dipanen
        int pilihan;
        cout << "\nNomor hewan yang ingin dipanen: ";
        cin >> pilihan;
        pilihan--;

        // validasi hewannya
        if (pilihan < 0 || pilihan >= hewan_siap_panen.size())
        {
            PilihanHewanInvalid e;
            throw e;
        }

        string jenis_hewan_dipanen = hewan_siap_panen[pilihan];
        int jumlah_petak_siap_panen = petak_hewan_siap_panen[jenis_hewan_dipanen];

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

            if (row < 0 || row >= peternakan->getRow() || col < 0 || col >= peternakan->getCol())
            {
                PetakTidakValid e;
                throw e;
            }

            Hewan *hewan = static_cast<Hewan *>(peternakan->getItem(row, col));
            if (hewan == nullptr || hewan->getKode() != jenis_hewan_dipanen)
            {
                PetakTidakValid e;
                throw e;
            }

            if (hewan == nullptr || !hewan->Makhluk::siapPanen())
            {
                BelumSiapPanen e;
                throw e;
            }

            petak_dipanen.push_back(petak);
        }

        // menampilkan hasil panen
        cout << endl
            << jumlah_petak_dipanen << " petak hewan " << jenis_hewan_dipanen << " pada ";
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

            Hewan *hewan = peternakan->getItem(row, col);
            vector<Produk *> hasilPanen = hewan->konversiPanen();
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
            peternakan->removeItem(row, col);
            // ----------------------------------------------
        }
    }
}

void Peternak::CetakPetak()
{
    peternakan->printPeternakan();

    cout << endl;

    map<string, string> list_hewan;

    for (int i = 0; i < peternakan->getRow(); i++) {
        for (int j = 0; j < peternakan->getCol(); j++) {
            Hewan* hewan = static_cast<Hewan*>(peternakan->getItem(i, j));
            if (peternakan->getItem(i, j) != nullptr) {
                string jenis_hewan = hewan->getKode();
                string nama_hewan = hewan->getName();
                if (list_hewan.find(jenis_hewan) == list_hewan.end()) {
                    list_hewan[jenis_hewan] = nama_hewan;
                }
            } else {
                continue;
            }
        }
    }

    for (const auto& pair : list_hewan) {
        cout << " - " << pair.first << ": " << pair.second << endl;
    }
}

void Peternak::ternak()
{
    if (this->peternakan->hitungKosong() == 0)
    {
        KandangPenuh e;
        throw e;
    }
    Inventory *inventory = getInventory();

    // pilih hewan dari penyimpanan
    cout << "Pilih hewan dari penyimpanan: " << endl;
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

    // cek apakah petak kosong
    Item *item = inventory->getItem(inv_row, inv_col);
    if (item == nullptr)
    {
        PetakKosong e;
        throw e;
    }

    // cek apakah item di slot yang dipilih adalah hewan
    Hewan *hewan = dynamic_cast<Hewan *>(item);
    if (hewan == nullptr)
    {
        BukanHewan e;
        throw e;
    }

    cout << "Kamu memilih " << hewan->getName() << endl;

    // pilih petak kandang di peternakan
    cout << "\nPilih petak tanah yang akan ditinggali: " << endl;
    peternakan->printPeternakan();

    string petak;
    cout << "\nPetak tanah: ";
    cin >> petak;

    // cek apakah petak yang dipilih valid
    int farm_col = petak[0] - 'A';
    int farm_row = stoi(petak.substr(1)) - 1;
    if (farm_col < 0 || farm_col >= peternakan->getCol() || farm_row < 0 || farm_row >= peternakan->getRow())
    {
        PetakTidakValid e;
        throw e;
    }

    // cek apakah petak kandang kosong
    if (peternakan->getItem(farm_row, farm_col) != nullptr)
    {
        PetakKandangSudahTerisi e;
        throw e;
    }

    // pindahin hewan ke petak kandang
    peternakan->setItem(farm_row, farm_col, hewan);
    inventory->removeItem(inv_row, inv_col);

    cout << "\nDengan hati-hati, kamu meletakkan seekor " << hewan->getName() << " di kandang." << endl;
    cout << hewan->getName() << " telah menjadi peliharaanmu sekarang!" << endl;
}

float Peternak::HitungPajak()
{
    float ktkp = 11;
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

    // cout << "gulden pemain: " << getName()<< " : " << getGulden() << endl;
    // cout << "pajak: " << (hitungKekayaan() - ktkp) * tarif << endl;
    
    if ((hitungKekayaan() - ktkp) * tarif < 0)
    {
        return 0;
    }
    else if ((hitungKekayaan() - ktkp) * tarif > getGulden()) 
    {
        return getGulden();
    }
    else 
    {
        return (hitungKekayaan() - ktkp) * tarif;
    }
}

float Peternak::hitungKekayaan()
{
    float total_kekayaan = 0;

    // hitung total kekayaan dari barang-barang di peternakan
    for (int i = 0; i < peternakan->getRow(); i++)
    {
        for (int j = 0; j < peternakan->getCol(); j++)
        {
            Item *item = peternakan->getItem(i, j);
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

void Peternak::masukanHewanKePeternakan(Hewan *hewan, string position)
{
    pair<int, int> koordinat = positionStringToPair(position);

    peternakan->setItem(koordinat.first, koordinat.second, hewan);
}

Peternakan *Peternak::getPeternakan()
{
    return peternakan;
}

string Peternak::getTipePemain()
{
    return "Peternak";
}

void Peternak::undo(Toko* toko, vector<Pemain*>daftarPemain){
    Memento* m = this->getActionHistory()->topMemento();
    this->tambahBeratBadan(m->getBeratBadanMemento()-this->getBeratBadan());
    cout << "Berat badan " << this->getName() << " berhasil dikembalikan: " << this->getBeratBadan() << endl;
    this->tambahkanGulden(m->getGuldenMemento()-this->getGulden());
    cout << "Gulden " << this->getName() << " berhasil dikembalikan:" << this->getGulden() << endl;
    undoToko(toko,m);
    cout << "Toko berhasil dikembalikan" << endl;
    m->deleteCreatedItems();
    m->undoInventory(this->getInventory());
    cout << "Inventory " << this->getName() << " berhasil dikembalikan" << endl;
    if (dynamic_cast<PeternakMemento*>(m) != nullptr){
        PeternakMemento* pm = dynamic_cast<PeternakMemento*>(m);
        pm->undoPeternakan(this->getPeternakan());
    }
    this->getActionHistory()->popMemento();
    cout << "Undo selesai" << endl;
}