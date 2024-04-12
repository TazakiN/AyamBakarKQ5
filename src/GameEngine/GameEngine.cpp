#include "GameEngine.hpp"

using namespace std;

GameEngine::GameEngine()
{
    readConfig();
}

GameEngine::~GameEngine()
{
}

void GameEngine::readConfig()
{
    // ********** BACA CONFIG MISC ********** //
    string filename = "config/misc.txt";
    stringstream masukan = bacaFile(filename);
    string line;

    // masukin guldenMenang
    getline(masukan, line);
    guldenMenang = stoi(line);

    // masukin beratBadanMenang
    getline(masukan, line);
    beratBadanMenang = stoi(line);

    // masukin ukuran inventory
    getline(masukan, line);
    stringstream ss(line);
    string token;
    getline(ss, token, ' ');
    ukuranInventory.first = stoi(token);
    getline(ss, token, ' ');
    ukuranInventory.second = stoi(token);

    // masukin ukuran ladang
    getline(masukan, line);
    stringstream ss2(line);
    getline(ss2, token, ' ');
    ukuranLadang.first = stoi(token);
    getline(ss2, token, ' ');
    ukuranLadang.second = stoi(token);

    // masukin ukuran peternakan
    getline(masukan, line);
    stringstream ss3(line);
    getline(ss3, token, ' ');
    ukuranPeternakan.first = stoi(token);
    getline(ss3, token, ' ');
    ukuranPeternakan.second = stoi(token);

    // ********** BACA CONFIG RECIPE ********** //
    listOfResepBangunan = ekstrakConfig("config/recipe.txt");

    // ********** BACA CONFIG ANIMAL ********** //
    dataOfHewan = ekstrakConfig("config/animal.txt");

    // ********** BACA CONFIG PLANT ********** //
    dataOfTanaman = ekstrakConfig("config/plant.txt");

    // ********** BACA CONFIG PRODUCT ********** //
    dataOfProduct = ekstrakConfig("config/product.txt");
}

string GameEngine::getHewanAttributeByAny(const string &getSomething, const string &bySomething, const string &keyword) const
{
    for (const auto &row : dataOfHewan)
    {
        if (bySomething == "ID" && row[0] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
        else if (bySomething == "KODE_HURUF" && row[1] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
        else if (bySomething == "NAME" && row[2] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
        else if (bySomething == "TYPE" && row[3] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
        else if (bySomething == "WEIGHT_TO_HARVEST" && row[4] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
    }
    return "Data tidak ditemukan!";
}

string GameEngine::getTanamanAttributeByAny(const string &getSomething, const string &bySomething, const string &keyword) const
{
    for (const auto &row : dataOfTanaman)
    {
        if (bySomething == "ID" && row[0] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
        else if (bySomething == "KODE_HURUF" && row[1] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
        else if (bySomething == "NAME" && row[2] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
        else if (bySomething == "TYPE" && row[3] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
        else if (bySomething == "WEIGHT_TO_HARVEST" && row[4] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
        else if (bySomething == "PRICE" && row[5] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "WEIGHT_TO_HARVEST")
                return row[4];
            else if (getSomething == "PRICE")
                return row[5];
        }
    }
    return "Data not found!";
}

string GameEngine::getProductAttributeByAny(const string &getSomething, const string &bySomething, const string &keyword) const
{
    for (const auto &row : dataOfProduct)
    {
        if (bySomething == "ID" && row[0] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "ORIGIN")
                return row[4];
            else if (getSomething == "ADDED_WEIGHT")
                return row[5];
            else if (getSomething == "PRICE")
                return row[6];
        }
        else if (bySomething == "KODE_HURUF" && row[1] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "ORIGIN")
                return row[4];
            else if (getSomething == "ADDED_WEIGHT")
                return row[5];
            else if (getSomething == "PRICE")
                return row[6];
        }
        else if (bySomething == "NAME" && row[2] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "ORIGIN")
                return row[4];
            else if (getSomething == "ADDED_WEIGHT")
                return row[5];
            else if (getSomething == "PRICE")
                return row[6];
        }
        else if (bySomething == "TYPE" && row[3] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "ORIGIN")
                return row[4];
            else if (getSomething == "ADDED_WEIGHT")
                return row[5];
            else if (getSomething == "PRICE")
                return row[6];
        }
        else if (bySomething == "ORIGIN" && row[4] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "ORIGIN")
                return row[4];
            else if (getSomething == "ADDED_WEIGHT")
                return row[5];
            else if (getSomething == "PRICE")
                return row[6];
        }
        else if (bySomething == "ADDED_WEIGHT" && row[5] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "ORIGIN")
                return row[4];
            else if (getSomething == "ADDED_WEIGHT")
                return row[5];
            else if (getSomething == "PRICE")
                return row[6];
        }
        else if (bySomething == "PRICE" && row[6] == keyword)
        {
            if (getSomething == "ID")
                return row[0];
            else if (getSomething == "KODE_HURUF")
                return row[1];
            else if (getSomething == "NAME")
                return row[2];
            else if (getSomething == "TYPE")
                return row[3];
            else if (getSomething == "ORIGIN")
                return row[4];
            else if (getSomething == "ADDED_WEIGHT")
                return row[5];
            else if (getSomething == "PRICE")
                return row[6];
        }
    }
    return "Data tidak ditemukan!";
}

vector<pair<string, int>> GameEngine::getMaterialsByRecipeCode(const string &recipeCode) const
{
    vector<pair<string, int>> materials; // Vektor pasangan untuk menyimpan material dan quantity-nya

    // Mencari resep berdasarkan kode huruf
    for (const auto &recipe : listOfResepBangunan)
    {
        if (recipe[1] == recipeCode)
        { // Kolom kedua untuk kode huruf resep
            // Mengambil material dan quantity-nya
            for (size_t i = 4; i < recipe.size(); i += 2)
            { // Mulai dari kolom ke-4, karena kolom pertama setelah harga adalah material
                materials.push_back(make_pair(recipe[i], stoi(recipe[i + 1])));
            }
            break;
        }
    }

    return materials;
}

void GameEngine::readState()
{
    stringstream masukan = bacaFile("config/state.txt");
    string line;

    // masukin banyak pemain
    getline(masukan, line);
    int banyakPemain = stoi(line);

    // masukin data pemain
    for (int i = 0; i < banyakPemain; i++)
    {
        // masukin data dari baris pertama
        getline(masukan, line);
        stringstream ss(line);
        string token;
        getline(ss, token, ' ');
        string namaPemain = token;
        getline(ss, token, ' ');
        string jenisPemain = token;
        getline(ss, token, ' ');
        int beratBadanPemain = stoi(token);
        getline(ss, token, ' ');
        int guldenPemain = stoi(token);
        Pemain *pemain;

        // buat pemain berdasarkan tipe
        if (jenisPemain == "Walikota")
        {
            // buat pemain walikota
            pemain = new Walikota(namaPemain, ukuranInventory.first, ukuranInventory.second);
        }
        else if (jenisPemain == "Petani")
        {
            // buat pemain petani
            pemain = new Petani(namaPemain, ukuranInventory.first, ukuranInventory.second);
        }
        else if (jenisPemain == "Peternak")
        {
            // buat pemain proletar
            pemain = new Peternak(namaPemain, ukuranInventory.first, ukuranInventory.second);
        }
        // masukin data pemain
        pemain->tambahBeratBadan(beratBadanPemain);
        pemain->tambahkanGulden(guldenPemain);

        // masukin data inventory pemain
        getline(masukan, line);
        int banyakItem = stoi(line);

        for (int j = 0; j < banyakItem; j++)
        {
            getline(masukan, line);
            stringstream ss2(line);
            string token;
            getline(ss2, token, ' ');
            string namaItem = token;
            bool inserted = false;

            // cari item berdasarkan namaItem di listOfResepBangunan, dataOfHewan, dataOfTanaman, dataOfProduct
            for (int k = 0; k < listOfResepBangunan.size() && !inserted; k++)
            {
                if (listOfResepBangunan[k][2] == namaItem)
                {
                    Bangunan *bangunan = new Bangunan(namaItem, listOfResepBangunan[k][1], stoi(listOfResepBangunan[k][3]));
                    pemain->masukanItem(bangunan);
                    inserted = true;
                }
            }

            for (int k = 0; k < dataOfHewan.size() && !inserted; k++)
            {
                if (dataOfHewan[k][2] == namaItem)
                {
                    string tipe = dataOfHewan[k][3];
                    if (tipe == "CARNIVORE")
                    {
                        Karnivora *karnivor = new Karnivora(namaItem, dataOfHewan[k][1], dataOfHewan[k][3], stoi(dataOfHewan[k][5]), 0, stoi(dataOfHewan[k][4]));
                        pemain->masukanItem(karnivor);
                    }
                    else if (tipe == "HERBIVORE")
                    {
                        Herbivora *herbivora = new Herbivora(namaItem, dataOfHewan[k][1], dataOfHewan[k][3], stoi(dataOfHewan[k][5]), 0, stoi(dataOfHewan[k][4]));
                        pemain->masukanItem(herbivora);
                    }
                    else // tipe == "OMNIVORE"
                    {
                        Omnivora *omnivora = new Omnivora(namaItem, dataOfHewan[k][1], dataOfHewan[k][3], stoi(dataOfHewan[k][5]), 0, stoi(dataOfHewan[k][4]));
                        pemain->masukanItem(omnivora);
                    }
                    inserted = true;
                }
            }

            for (int k = 0; k < dataOfTanaman.size() && !inserted; k++)
            {
                if (dataOfTanaman[k][2] == namaItem)
                {
                    // TODO : isi inventory berdasarkan jenis tanaman
                    // Tanaman *tanaman = new Tanaman(namaItem, dataOfTanaman[k][1], stoi(dataOfTanaman[k][3]), stoi(dataOfTanaman[k][4]), stoi(dataOfTanaman[k][5]), stoi(dataOfTanaman[k][6]));
                }
            }

            for (int k = 0; k < dataOfProduct.size() && !inserted; k++)
            {
                if (dataOfProduct[k][2] == namaItem)
                {
                    Produk *produk = new Produk(namaItem, dataOfProduct[k][1], stoi(dataOfProduct[k][0]), dataOfProduct[k][3], dataOfProduct[k][4], stoi(dataOfProduct[k][5]), stoi(dataOfProduct[k][6]));
                    pemain->masukanItem(produk);
                    inserted = true;
                }
            }
        }

        if (jenisPemain != "Walikota")
        {
            // masukin data ladang pemain
            getline(masukan, line);
            int banyakMahluk = stoi(line);

            for (int j = 0; j < banyakMahluk; j++)
            {
                getline(masukan, line);
                stringstream ss2(line);
                string token;
                getline(ss2, token, ' ');
                string posisi = token;
                getline(ss2, token, ' ');
                string namaMahluk = token;

                Makhluk *mahluk;

                if (jenisPemain == "Petani")
                {
                    // TODO : bikin si tanamannya
                }
                else if (jenisPemain == "Peternak")
                {
                    string tipeHewan = getHewanAttributeByAny("TYPE", "NAME", namaMahluk);
                    if (tipeHewan == "CARNIVORE")
                    {
                        mahluk = new Karnivora(namaMahluk, getHewanAttributeByAny("KODE_HURUF", "NAME", namaMahluk), tipeHewan, stoi(getHewanAttributeByAny("PRICE", "NAME", namaMahluk)), 0, stoi(getHewanAttributeByAny("WEIGHT_TO_HARVEST", "NAME", namaMahluk)));
                    }
                    else if (tipeHewan == "HERBIVORE")
                    {
                        mahluk = new Herbivora(namaMahluk, getHewanAttributeByAny("KODE_HURUF", "NAME", namaMahluk), tipeHewan, stoi(getHewanAttributeByAny("PRICE", "NAME", namaMahluk)), 0, stoi(getHewanAttributeByAny("WEIGHT_TO_HARVEST", "NAME", namaMahluk)));
                    }
                    else // tipeHewan == "OMNIVORE"
                    {
                        mahluk = new Omnivora(namaMahluk, getHewanAttributeByAny("KODE_HURUF", "NAME", namaMahluk), tipeHewan, stoi(getHewanAttributeByAny("PRICE", "NAME", namaMahluk)), 0, stoi(getHewanAttributeByAny("WEIGHT_TO_HARVEST", "NAME", namaMahluk)));
                    }
                    // masukin hewan ke peternakan
                    Peternak *pemain = static_cast<Peternak *>(pemain);
                    Hewan *hewan = static_cast<Hewan *>(mahluk);
                    pemain->masukanHewanKePeternakan(hewan, posisi);
                }
            }
        }
        pemainList.push(pemain);
    }

    // masukin data Toko
    getline(masukan, line);
    int banyakItemDiToko = stoi(line);
    list<Item> items;

    for (int i = 0; i < banyakItemDiToko; i++)
    {
        getline(masukan, line);
        stringstream ss(line);
        string token;
        getline(ss, token, ' ');
        string namaItem = token;
        getline(ss, token, ' ');
        int banyakItem = stoi(token);

        // TODO : isi data di toko
    }
}

void GameEngine::tambahPemain(string nama_pemain, int peran_pemain, int row, int col)
{
    size_t i = 0;
    int isFound = 0;
    Pemain *walikota = nullptr;
    Walikota *w;
    while (i < pemainList.size() && isFound == 0)
    {
        w = dynamic_cast<Walikota *>(pemainList.top());
        if (w != nullptr)
        {
            isFound = 1;
            walikota = w;

            if (peran_pemain == 1)
            {
                WalikotaHanya1 e;
                throw e;
            }
            else if (peran_pemain == 2)
            {
                if (w->getGulden() >= 50)
                {
                    Petani *p = new Petani(nama_pemain, row, col);
                    p->tambahkanGulden(50);
                    w->kurangiGulden(50);
                    pemainList.push(p);
                    cout << "yeay bisa nambahin" << endl; // nanti diganti coutnya hehe
                }
                else
                {
                    QuantityTokoTidakCukup e;
                    throw e;
                }
            }
            else if (peran_pemain == 3)
            {
                if (w->getGulden() >= 50)
                {
                    Peternak *p = new Peternak(nama_pemain, row, col);
                    p->tambahkanGulden(50);
                    w->kurangiGulden(50);
                    pemainList.push(p);
                    cout << "yeay bisa nambahin" << endl; // nanti diganti coutnya hehe
                }
                else
                {
                    QuantityTokoTidakCukup e;
                    throw e;
                }
            }
            else
            {
                PeranInvalid e;
                throw e;
            }
        }
        ++i;
    }
}

void GameEngine::copyRecipeToWalikota(Walikota &walikota)
{
    for (auto i = this->listOfResepBangunan.cbegin(); i != this->listOfResepBangunan.cend(); ++i)
    {
        vector<string> &recipe = const_cast<vector<string> &>(*i);
        walikota.addResep(recipe);
    }
}

void GameEngine::copyDataToToko(Toko &toko)

{
    toko.initializedToko(dataOfHewan, dataOfTanaman);
}

void GameEngine::simpan()
{
    // TODO : implementasi simpan
}

void GameEngine::initialize()
{
    string perintah;
    while (true)
    {
        // Menerima perintah dari pengguna
        cout << "\n> ";
        cin >> perintah;

        // Contoh: Jika perintah adalah "help", tampilkan pesan bantuan
        if (perintah == "NEXT")
        {
            Pemain *temp = pemainList.top();
            pemainList.pop();
            pemainList.push(temp);
            currentPemain = pemainList.top();
        }
        else if ("CETAK_PENYIMPANAN")
        {
            currentPemain->getInventory()->printGridHeader();
            currentPemain->getInventory()->printGrid();
        }
        else if ("PUNGUT_PAJAK")
        {
            Walikota *walikota = dynamic_cast<Walikota *>(currentPemain);

            if (walikota != nullptr)
            {
                walikota->pungutPajak(pemainList);
            }
            else
            {
                cout << "Kamu bukan walikota!" << endl;
            }
        }
        else if ("CETAK_LADANG")
        {
            Petani *petani = dynamic_cast<Petani *>(currentPemain);

            if (petani != nullptr)
            {
                petani->CetakPetak();
            }
            else
            {
                cout << "Kamu bukan petani!" << endl;
            }
        }
        else if ("CETAK_PETERNAKAN")
        {
            Peternak *peternak = dynamic_cast<Peternak *>(currentPemain);

            if (peternak != nullptr)
            {
                peternak->CetakPetak();
            }
            else
            {
                cout << "Kamu bukan peternak!" << endl;
            }
        }
        else if ("TANAM")
        {
            Petani *petani = dynamic_cast<Petani *>(currentPemain);

            if (petani != nullptr)
            {
                petani->tanam();
            }
            else
            {
                cout << "Kamu bukan petani!" << endl;
            }
        }
        else if ("TERNAK")
        {
            Peternak *peternak = dynamic_cast<Peternak *>(currentPemain);

            if (peternak != nullptr)
            {
                peternak->ternak();
            }
            else
            {
                cout << "Kamu bukan peternak!" << endl;
            }
        }
        else if ("BANGUN")
        {
            Walikota *walikota = dynamic_cast<Walikota *>(currentPemain);

            if (walikota != nullptr)
            {
                // TODO : implementasi bangun
            }
            else
            {
                cout << "Kamu bukan walikota!" << endl;
            }
        }
        else if ("MAKAN")
        {
            currentPemain->makan();
        }
        else if ("KASIH_MAKAN")
        {
            // TODO : implementasi kasih makan
        }
        else if ("BELI")
        {
            // TODO : implementasi beli
        }
        else if ("JUAL")
        {
            // TODO : implementasi jual
        }
        else if ("PANEN")
        {
            // TODO : implementasi panen
            // * bisa peternak, bisa petani
        }
        else if ("MUAT")
        {
            readState();
        }
        else if ("SIMPAN")
        {
            simpan();
        }
        else if ("TAMBAH_PEMAIN")
        {
            // TODO : implementasi tambah pemain
        }
        else
        {
            cout << "Perintah tidak dikenali!" << endl;
        }
    }
}