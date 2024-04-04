#include "GameEngine.hpp"

using namespace std;

GameEngine::GameEngine()
{
    // populate data dari file config
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
    // Membaca data per baris
    masukan = bacaFile("config/recipe.txt");
    while (getline(masukan, line))
    {
        // Memecah baris per spasi
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        listOfResepBangunan.push_back(tokens);
    }

    // ********** BACA CONFIG ANIMAL ********** //
    // Membaca data per baris
    masukan = bacaFile("config/animal.txt");
    while (getline(masukan, line))
    {
        // Memecah baris per spasi
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        dataOfHewan.push_back(tokens);
    }

    // ********** BACA CONFIG PLANT ********** //
    // Membaca data per baris
    masukan = bacaFile("config/plant.txt");
    while (getline(masukan, line))
    {
        // Memecah baris per spasi
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        dataOfTanaman.push_back(tokens);
    }

    // ********** BACA CONFIG PRODUCT ********** //
    // Membaca data per baris
    masukan = bacaFile("config/product.txt");
    while (getline(masukan, line))
    {
        // Memecah baris per spasi
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        dataOfProduct.push_back(tokens);
    }
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
                    // TODO : bikin si hewannya
                }

                // TODO : masukin mahluk ke ladang pemain
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

void GameEngine::initialize()
{
    // TODO : implementasi initialize
}

void GameEngine::simpan()
{
    // TODO : implementasi simpan
}

void GameEngine::muat()
{
    // TODO : implementasi muat
    readState();
}