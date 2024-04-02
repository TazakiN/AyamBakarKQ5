#include "GameEngine.hpp"

using namespace std;

GameEngine::GameEngine(/* args */)
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
        // int beratBadanPemain = stoi(token); <-- ini ntar diuncomment, ini supaya ga error unused variable aja
        getline(ss, token, ' ');
        // int guldenPemain = stoi(token); <-- ini juga
        // Pemain *pemain; <-- ini juga

        // buat pemain berdasarkan tipe
        if (jenisPemain == "Walikota")
        {
            // buat pemain walikota
            // Pemain *pemain = new Walikota(namaPemain, ukurangInventory.first, ukuranInventory.second );
            // pemainList.push_back(pemain);
        }
        else if (jenisPemain == "Petani")
        {
            // buat pemain petani
            // Pemain *pemain = new Petani(namaPemain, ukurangInventory.first, ukuranInventory.second);
            // pemainList.push_back(pemain);
        }
        else if (jenisPemain == "Proletar")
        {
            // buat pemain proletar
            // Pemain *pemain = new Proletar(namaPemain, ukurangInventory.first, ukuranInventory.second);
            // pemainList.push_back(pemain);
        }

        // pemain->tambahBeratBadan(beratBadanPemain);
        // pemain->tambahGulden(guldenPemain);

        // masukin data inventory pemain
        getline(masukan, line);
        int banyakItem = stoi(line);

        for (int j = 0; j < banyakItem; j++)
        {
            getline(masukan, line);
            stringstream ss2(line);
            string token;
            getline(ss2, token, ' ');
            string namaItem = token; // ? ini gatau nanti nama item ato kode itemnya

            // pemain->tambahItem(namaItem); <-- nanti bikin methodnya
        }

        if (jenisPemain != "Walikota")
        {
            // masukin data ladang pemain
            getline(masukan, line);
            int banyakMahluk = stoi(line);

            for (int j = 0; j < banyakMahluk; j++)
            {
                // TODO : isi ladang berdasarkan jenis mahluk
            }
        }
    }

    // masukin data Toko
    // TODO : isi toko
}
