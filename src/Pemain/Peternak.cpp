#include "Peternak.hpp"
#include <vector>
#include <map>

Peternak::Peternak(string name, int row, int col) : Proletar(name, row, col)
{
    peternakan = new Peternakan(row, col);
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
    if (inv_row < 0 || inv_row >= getInventory()->getRow() || inv_col < 0 || inv_col >= getInventory()->getCol())
    {
        // cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
        // cout << "Silahkan masukkan slot yang berisi makanan." << endl;
        // mau output kayak gitu apa throw exception?
        // @denoseu throw exception aja kayanya oke
        return;
    }

    // Cek apakah ada makanan di slot yang dipilih
    Item *item = getInventory()->getItem(inv_row, inv_col);
    Produk *produk = dynamic_cast<Produk *>(item);

    if (produk)
    {
        if ((hewan->getTipe() == "CARNIVORE" && produk->getTipe() == "PRODUCT_MEAT") ||
            (hewan->getTipe() == "HERBIVORE" && produk->getTipe() == "PRODUCT_FRUIT_PLANT") ||
            (hewan->getTipe() == "OMNIVORE" && (produk->getTipe() == "PRODUCT_MEAT" || produk->getTipe() == "PRODUCT_FRUIT_PLANT")))
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
            cout << "Makanan yang dipilih tidak sesuai untuk jenis hewan yang dipilih." << endl;
        }
    }
    else
    {
        cout << "Item yang dipilih bukanlah makanan." << endl;
    }
}

void Peternak::Panen()
{
    Peternak::CetakPetak();

    // daftar petak yang siap panen
    for (int i = 1; i <= peternakan->getRow(); i++)
    {
        for (int j = 1; j <= peternakan->getCol(); j++)
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

    for (int i = 1; i <= peternakan->getRow(); i++)
    {
        for (int j = 1; j <= peternakan->getCol(); j++)
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
        cout << "Pilihan hewan tidak valid." << endl;
        return;
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

        if (row < 0 || row >= peternakan->getRow() || col < 0 || col >= peternakan->getCol())
        {
            cout << "Petak tidak valid." << endl;
            return;
        }

        Hewan *hewan = static_cast<Hewan *>(peternakan->getItem(row, col));
        if (hewan == nullptr || hewan->getKode() != jenis_hewan_dipanen || !hewan->Makhluk::siapPanen())
        {
            cout << "Petak tidak valid atau hewan belum siap dipanen." << endl;
            return;
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
    // BELUM
    Inventory *inventory = getInventory();
    for (const string &petak : petak_dipanen)
    {
        // row col petak
        // item dari peternakan
        // item -> produk
        // gimana dapetin hasilnya?
        // inventory->setItem(row, col, produk);

        // Bener ga begini? @denoseu --------------------
        // int row = stoi(petak.substr(1)) - 1;
        // int col = petak[0] - 'A';

        // Hewan* hewan = peternakan->getItem(row, col);
        // vector<Produk*> hasilPanen = hewan->konversiPanen();
        // for (Produk* produk : hasilPanen) {
        //     inventory->setItem(row, col, produk);
        // }
        // ----------------------------------------------
    }
}

void Peternak::CetakPetak()
{
    peternakan->printPeternakan();
}

void Peternak::ternak()
{
    Inventory *inventory = getInventory();

    // pilih hewan dari penyimpanan
    cout << "Pilih hewan dari penyimpanan: " << endl;
    inventory->printGridHeader();
    inventory->printGrid();

    string slot;
    cout << "\nSlot: ";
    cin >> slot;

    // cek slot yang dipilih
    int inv_row = slot[0] - 'A';
    int inv_col = stoi(slot.substr(1)) - 1;
    if (inv_row < 0 || inv_row >= inventory->getRow() || inv_col < 0 || inv_col >= inventory->getCol())
    {
        cout << "Slot yang dipilih tidak valid." << endl;
        return;
    }

    // cek apakah item di slot yang dipilih adalah hewan
    Item *item = peternakan->getItem(inv_row, inv_col);
    Hewan *hewan = dynamic_cast<Hewan *>(item);
    if (hewan == nullptr)
    {
        cout << "Item yang dipilih bukan hewan." << endl;
        return;
    }

    // pilih petak kandang di peternakan
    cout << "\nPilih petak tanah yang akan ditinggali: " << endl;
    peternakan->printPeternakan();

    string petak;
    cout << "\nPetak tanah: ";
    cin >> petak;

    // cek apakah petak yang dipilih valid
    int farm_row = petak[0] - 'A';
    int farm_col = stoi(petak.substr(1)) - 1;
    if (farm_row < 0 || farm_row >= peternakan->getRow() || farm_col < 0 || farm_col >= peternakan->getCol())
    {
        cout << "Petak yang dipilih tidak valid." << endl;
        return;
    }

    // cek apakah petak kandang kosong
    if (peternakan->getItem(farm_row, farm_col) != nullptr)
    {
        cout << "Petak kandang sudah terisi." << endl;
        return;
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

    return (hitungKekayaan() - ktkp) * tarif;
}

float Peternak::hitungKekayaan()
{
    int total_kekayaan = 0;

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
    int row = position[0] - 65;
    int col1 = position[1] - '0';
    int col2 = position[2] - '0';
    int col = col1 * 10 + col2;

    peternakan->setItem(row, col, hewan);
}