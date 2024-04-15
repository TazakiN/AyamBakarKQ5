#include "GameEngine.hpp"
#include <cstring>
#include <iostream>

using namespace std;

GameEngine::GameEngine()
{
    readConfig();
    this->toko = new Toko();
    copyDataToToko(*toko);
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

    // // print semua data
    // for (const auto &row : dataOfHewan)
    // {
    //     for (const auto &col : row)
    //     {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }

    // for (const auto &row : dataOfTanaman)
    // {
    //     for (const auto &col : row)
    //     {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }

    // for (const auto &row : dataOfProduct)
    // {
    //     for (const auto &col : row)
    //     {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }

    // for (const auto &row : listOfResepBangunan)
    // {
    //     for (const auto &col : row)
    //     {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }
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

Item *GameEngine::makeItem(string itemName)
{
    // Mencari item berdasarkan nama
    // cari di dataOfHewan
    for (const auto &row : dataOfHewan)
    {
        if (trim(row[2]) == trim(itemName))
        {
            string tipe = row[3];
            if (trim(tipe) == trim("CARNIVORE"))
            {
                return new Karnivora(row[2], row[1], row[3], stoi(row[5]), 0, stoi(row[4]));
            }
            else if (trim(tipe) == trim("HERBIVORE"))
            {
                return new Herbivora(row[2], row[1], row[3], stoi(row[5]), 0, stoi(row[4]));
            }
            else // tipe == "OMNIVORE"
            {
                return new Omnivora(row[2], row[1], row[3], stoi(row[5]), 0, stoi(row[4]));
            }
        }
    }
    // cari di dataOfTanaman
    for (const auto &row : dataOfTanaman)
    {
        if (trim(row[2]) == trim(itemName))
        {
            string tipe = row[3];
            if (trim(tipe) == trim("MATERIAL_PLANT"))
            {
                return new MaterialPlant(row[2], row[1], row[3], stoi(row[5]), 0, stoi(row[4]));
            }
            else // tipe == "FRUIT_PLANT"
            {
                return new FruitPlant(row[2], row[1], row[3], stoi(row[5]), 0, stoi(row[4]));
            }
        }
    }

    // cari di dataOfProduct
    for (const auto &row : dataOfProduct)
    {
        if (trim(row[2]) == trim(itemName))
        {
            // return new Produk(row[2], row[1], stoi(row[0]), row[3], row[4], stoi(row[5]), stoi(row[6]));
            return new Produk(row[2], row[1], row[3], row[4], stoi(row[5]), stoi(row[6]));
        }
    }

    // cari di listOfResepBangunan
    for (const auto &recipe : listOfResepBangunan)
    {
        if (trim(recipe[2]) == trim(itemName))
        {
            return new Bangunan(itemName, recipe[1], stoi(recipe[3]));
        }
    }
    return nullptr;
}

void GameEngine::readState(string *filename)
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

            Item *item = makeItem(namaItem);
            pemain->masukanItem(item);
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
                getline(ss2, token, ' ');
                int progressPanenMakhluk = stoi(token);

                if (jenisPemain == "Petani")
                {
                    string tipeTanaman = getTanamanAttributeByAny("TYPE", "NAME", namaMahluk);
                    Petani *petani = dynamic_cast<Petani *>(pemain);

                    if (tipeTanaman == "MATERIAL_PLANT")
                    {
                        MaterialPlant *materialPlant = new MaterialPlant(namaMahluk, getTanamanAttributeByAny("KODE_HURUF", "NAME", namaMahluk), tipeTanaman, stoi(getTanamanAttributeByAny("PRICE", "NAME", namaMahluk)), progressPanenMakhluk, stoi(getTanamanAttributeByAny("WEIGHT_TO_HARVEST", "NAME", namaMahluk)));
                        petani->masukanTanamanKeLadang(materialPlant, posisi);
                    }
                    else if (tipeTanaman == "FRUIT_PLANT")
                    {
                        FruitPlant *fruitPlant = new FruitPlant(namaMahluk, getTanamanAttributeByAny("KODE_HURUF", "NAME", namaMahluk), tipeTanaman, stoi(getTanamanAttributeByAny("PRICE", "NAME", namaMahluk)), progressPanenMakhluk, stoi(getTanamanAttributeByAny("WEIGHT_TO_HARVEST", "NAME", namaMahluk)));
                        petani->masukanTanamanKeLadang(fruitPlant, posisi);
                    }
                }
                else if (jenisPemain == "Peternak")
                {
                    string tipeHewan = getHewanAttributeByAny("TYPE", "NAME", namaMahluk);
                    Peternak *peternak = dynamic_cast<Peternak *>(pemain);

                    if (tipeHewan == "CARNIVORE")
                    {
                        Karnivora *karnivora = new Karnivora(namaMahluk, getHewanAttributeByAny("KODE_HURUF", "NAME", namaMahluk), tipeHewan, stoi(getHewanAttributeByAny("PRICE", "NAME", namaMahluk)), progressPanenMakhluk, stoi(getHewanAttributeByAny("WEIGHT_TO_HARVEST", "NAME", namaMahluk)));
                        peternak->masukanHewanKePeternakan(karnivora, posisi);
                    }
                    else if (tipeHewan == "HERBIVORE")
                    {
                        Herbivora *herbivora = new Herbivora(namaMahluk, getHewanAttributeByAny("KODE_HURUF", "NAME", namaMahluk), tipeHewan, stoi(getHewanAttributeByAny("PRICE", "NAME", namaMahluk)), progressPanenMakhluk, stoi(getHewanAttributeByAny("WEIGHT_TO_HARVEST", "NAME", namaMahluk)));
                        peternak->masukanHewanKePeternakan(herbivora, posisi);
                    }
                    else // tipeHewan == "OMNIVORE"
                    {
                        Omnivora *omnivora = new Omnivora(namaMahluk, getHewanAttributeByAny("KODE_HURUF", "NAME", namaMahluk), tipeHewan, stoi(getHewanAttributeByAny("PRICE", "NAME", namaMahluk)), progressPanenMakhluk, stoi(getHewanAttributeByAny("WEIGHT_TO_HARVEST", "NAME", namaMahluk)));
                        peternak->masukanHewanKePeternakan(omnivora, posisi);
                    }
                }
            }
        }
        else
        {
            Walikota *walikota = dynamic_cast<Walikota *>(pemain);
            copyRecipeToWalikota(*walikota);
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

        for (int j = 0; j < banyakItem; j++)
        {
            Item *item = makeItem(namaItem);
            toko->addItem(item);
        }
    }
    // cout << "display toko ke walikota (1)" << endl;
    // toko->displayToko(1);
    // cout << "display toko ke peternak (2)" << endl;
    // toko->displayToko(2);
    // cout << "display toko ke petani (3)" << endl;
    // toko->displayToko(3);
}

void GameEngine::tambahPemain(Pemain &pemain)
{
    Walikota *walikota = dynamic_cast<Walikota *>(currentPemain);
    if (walikota != nullptr)
    {
        if (walikota->getGulden() < 50)
        {
            GuldenTidakCukup e;
            throw e;
        }
        else
        {
            string jenis, nama;
            cout << "Masukkan jenis pemain: ";
            cin >> jenis;
            cout << "Masukkan nama pemain: ";
            cin >> nama;
            while (jenis != "peternak" && jenis != "petani")
            {
                cout << "Masukkan jenis pemain: ";
                cin >> jenis;
                cout << "Masukkan nama pemain: ";
                cin >> nama;
            }
            if (jenis == "petani")
            {
                Petani *p = new Petani(nama, ukuranInventory.first, ukuranInventory.second);
                p->tambahkanGulden(50);
                walikota->kurangiGulden(50);
                pemainList.push(p);
                cout << "Pemain baru ditambahkan!" << endl;
                cout << "Selamat datang \"" << nama << "\" di kota ini!" << endl;
            }
            else
            {
                Peternak *p = new Peternak(nama, ukuranInventory.first, ukuranInventory.second);
                p->tambahkanGulden(50);
                walikota->kurangiGulden(50);
                pemainList.push(p);
                cout << "Pemain baru ditambahkan!" << endl;
                cout << "Selamat datang \"" << nama << "\" di kota ini!" << endl;
            }
        }
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

// Buat coba2
void GameEngine::printListOfResepBangunan()
{
    std::cout << "List of Resep Bangunan:" << std::endl;
    for (const auto &recipe : this->listOfResepBangunan)
    {
        for (const auto &item : recipe)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}

void GameEngine::copyDataToToko(Toko &toko)

{
    toko.initializedToko(dataOfHewan, dataOfTanaman);
}

void GameEngine::simpan(string *filepath)
{
    ofstream file;
    file.open(*filepath);
    vector<Pemain *> listSemuaPemain;

    vector<Pemain *> pemainListCopy;
    // copy isi pemainList ke pemainListCopy
    while (!pemainList.empty())
    {
        Pemain *pemain = pemainList.top();
        pemainList.pop();
        pemainListCopy.push_back(pemain);
    }

    vector<Pemain *> pemainListNextTurnCopy;
    // copy isi pemainListNextTurn ke pemainListNextTurnCopy
    while (!pemainListNextTurn.empty())
    {
        Pemain *pemain = pemainListNextTurn.top();
        pemainListNextTurn.pop();
        pemainListNextTurnCopy.push_back(pemain);
    }

    // gabungin isi pemainListCopy dan pemainListNextTurnCopy
    for (auto &pemain : pemainListCopy)
    {
        listSemuaPemain.push_back(pemain);
    }

    for (auto &pemain : pemainListNextTurnCopy)
    {
        listSemuaPemain.push_back(pemain);
    }

    // kembalikan isi pemainList dan pemainListNextTurn ke semula
    for (auto &pemain : pemainListCopy)
    {
        pemainList.push(pemain);
    }

    for (auto &pemain : pemainListNextTurnCopy)
    {
        pemainListNextTurn.push(pemain);
    }

    // simpan banyak pemain
    file << listSemuaPemain.size() << endl;

    // simpan data pemain
    while (!listSemuaPemain.empty())
    {
        Pemain *pemain = listSemuaPemain.back();
        listSemuaPemain.pop_back();

        string tipePemain;

        // simpan data pemain
        file << pemain->getName() << " ";

        if (dynamic_cast<Walikota *>(pemain) != nullptr)
        {
            file << "Walikota";
            tipePemain = "Walikota";
        }
        else if (dynamic_cast<Petani *>(pemain) != nullptr)
        {
            file << "Petani";
            tipePemain = "Petani";
        }
        else if (dynamic_cast<Peternak *>(pemain) != nullptr)
        {
            file << "Peternak";
            tipePemain = "Peternak";
        }

        file << " " << pemain->getBeratBadan() << " " << pemain->getGulden() << endl;

        // simpan data inventory pemain
        file << pemain->getInventory()->getBanyakElement() << endl;
        stringstream isiInventory = pemain->getInventory()->getStringStreamOfInventory();
        string itemDiInventory;

        while (getline(isiInventory, itemDiInventory))
        {
            file << itemDiInventory << endl;
        }

        // simpan data ladang pemain
        if (tipePemain != "Walikota")
        {
            int banyakMakhluk;
            if (tipePemain == "Peternak")
            {
                Peternak *peternak = dynamic_cast<Peternak *>(pemain);
                banyakMakhluk = peternak->getPeternakan()->getBanyakElement();

                file << banyakMakhluk << endl;
                stringstream isiPeternakan = peternak->getPeternakan()->getStringStreamOfLahan();

                while (getline(isiPeternakan, tipePemain))
                {
                    file << tipePemain << endl;
                }
            }
            else if (tipePemain == "Petani")
            {
                Petani *petani = dynamic_cast<Petani *>(pemain);
                banyakMakhluk = petani->getLadang()->getBanyakElement();

                file << banyakMakhluk << endl;
                stringstream isiLadang = petani->getLadang()->getStringStreamOfLahan();

                while (getline(isiLadang, tipePemain))
                {
                    file << tipePemain << endl;
                }
            }
        }
    }

    // simpan data Toko
    int totalItem = this->toko->getTotalItem();
    file << totalItem << endl;
    for (int i = 0; i < totalItem; i++)
    {
        file << this->toko->getItemKeN(i + 15) << " " << this->toko->getTotalItemKeN(i + 15) << endl;
    }
    file.close();
}

void GameEngine::kasih_makan_driver(Peternak &peternak)
{
    cout << "Pilih petak kandang yang akan ditinggali" << endl;

    peternak.CetakPetak();

    cout << "Petak kandang: ";
    string petak;
    cin >> petak;

    // ubah petak jadi koordinat
    pair<int, int> pos = positionStringToPair(petak);

    peternak.kasih_makan(pos.first, pos.second);
}

void GameEngine::beli_driver(Pemain &pemain)
{
    std::cout << "Selamat datang di toko!!" << std::endl;
    std::cout << "Berikut merupakan hal yang dapat Anda beli: " << std::endl;
    int tipePemain;
    if (dynamic_cast<Walikota *>(&pemain) != nullptr)
    {
        tipePemain = 1;
    }
    else if (dynamic_cast<Petani *>(&pemain) != nullptr)
    {
        tipePemain = 2;
    }
    else if (dynamic_cast<Peternak *>(&pemain) != nullptr)
    {
        tipePemain = 3;
    }
    toko->displayToko(tipePemain);

    int slotTersedia = pemain.getInventory()->hitungKosong();
    std::cout << "Uang Anda: " << pemain.getGulden() << std::endl;
    std::cout << "Slot penyimpanan tersedia: " << slotTersedia << std::endl;

    // Input barang sama kuantitas + validasi
    int idxItem, kuantitas;
    bool isSuksesBeli = false;
    int totalHarga;
    while (!isSuksesBeli)
    {
        std::cout << "Barang yang ingin dibeli: ";
        std::cin >> idxItem;
        std::cout << "Kuantitas: ";
        std::cin >> kuantitas;
        totalHarga = toko->itemKeN(idxItem)->getHarga() * kuantitas;
        if (kuantitas < slotTersedia && pemain.getGulden() > totalHarga)
        {
            if (tipePemain == 1 && idxItem < toko->getTotalItem() - toko->getTotalBangunan()){
                isSuksesBeli = true;
            }
            else if (idxItem < toko->getTotalItem()){
                isSuksesBeli = true;
            }
            else{
                std::cout << "Barang yang dipilih tidak valid!" << std::endl;
            }
        }
        else
        {
            if (kuantitas > slotTersedia)
            {
                std::cout << "Slot inventory kosong kurang" << std::endl;
            }
            if (pemain.getGulden() < totalHarga)
            {
                std::cout << "Gulden kurang!" << std::endl;
            }
            bool isValidasiValid = false;
            while (!isValidasiValid)
            {
                std::cout << "Apakah ingin melanjutkan beli? (y/n)";
                char validasi;
                std::cin >> validasi;
                if (validasi == 'n')
                {
                    isValidasiValid = true;
                    return;
                }
                else if (validasi != 'y')
                {
                    std::cout << "Masukan tidak valid!" << std::endl;
                }
                else
                {
                    isValidasiValid = true;
                }
            }
        }
    }

    // Keluarin barang dari toko, masukin barang ke inventory pemain
    list<Item*> listBarangDibeli = toko->removeItem(idxItem, kuantitas, pemain.getGulden(), slotTersedia);
    for (auto it = listBarangDibeli.begin(); it != listBarangDibeli.end(); ++it) {
        pemain.masukanItem(*it);
    }

    // Kurangi gulden
    pemain.kurangiGulden(totalHarga);
    std::cout << "Selamat Anda berhasil membeli " << kuantitas << " " << toko->getItemKeN(idxItem) << ". Uang Anda tersisa " << pemain.getGulden() << " gulden." << std::endl;
}


void GameEngine::jual_driver(Pemain &pemain)
{
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    pemain.getInventory()->printInventory();

    cout << "Silahkan pilih petak yang ingin anda jual!" << endl;
    cout << "Petak  : ";
    string petak_petak;
    cin >> petak_petak;

    // masukan semua petak ke dalam vector
    vector<string> petakTerpilih = stringSplitter(petak_petak, ',');

    for (auto &petak : petakTerpilih)
    {
        // dapetin item yang mau dijual
        Item *item = pemain.getInventory()->getItem(petak);

        // tambah item ke toko
        if (item != nullptr)
        {
            toko->addItem(item);
        }
    }

    // hapus item yang dijual dari inventory pemain dan tambahkan gulden pemain
    pemain.jual(petakTerpilih);
}

void GameEngine::initGame()
{
    string perintah;
    Toko toko;
    while (true)
    {
        if (!pemainList.empty())
        {
            currentPemain = pemainList.top();
            cout << "Saat ini giliran " << currentPemain->getName() << endl;
        }

        // Menerima perintah dari pengguna
        cout << "\n> ";
        cin >> perintah;

        if (perintah == "NEXT")
        {
            // Izin comment dulu yah cia, gw mau ngetes gabisa soalnya ini error -@evelynnn04
            // currentPemain->resetActionHistory();
            if (dynamic_cast<Petani *>(currentPemain) != nullptr)
            {
                Petani *petani = dynamic_cast<Petani *>(currentPemain);
                petani->tambahDurasiTanamanDiLadang();
            }

            Pemain *temp = pemainList.top();
            pemainList.pop();
            pemainListNextTurn.push(temp);
            if (pemainList.empty())
            {
                while (!pemainListNextTurn.empty())
                {
                    pemainList.push(pemainListNextTurn.top());
                    pemainListNextTurn.pop();
                }
            }
            currentPemain = pemainList.top();
        }
        else if (perintah == "CETAK_PENYIMPANAN")
        {
            currentPemain->getInventory()->printGridHeader();
            currentPemain->getInventory()->printGrid();
        }
        else if (perintah == "PUNGUT_PAJAK")
        {
            Walikota *walikota = dynamic_cast<Walikota *>(currentPemain);

            if (walikota != nullptr)
            {
                // Bagian Memento
                WalikotaMemento *wm = new WalikotaMemento(*(walikota->getInventory()), walikota->getBeratBadan(), walikota->getGulden(), toko);
                int i;
                for (i = 0; i < daftarPemainKeseluruhan.size(); i++)
                {
                    // TODO : iterasi pemain di priority queue, cek yang tipe peternak dan petani
                    // Kalau petani atau peternak, do: wm->insertPemainGulden(pemain->getName(), pemain->getGulden())
                }
                walikota->saveMemento(wm);

                // Logic Utama
                walikota->pungutPajak(daftarPemainKeseluruhan);
            }
            else
            {
                cout << "Kamu bukan walikota!" << endl;
            }
        }
        else if (perintah == "CETAK_LADANG")
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
        else if (perintah == "CETAK_PETERNAKAN")
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
        else if (perintah == "TANAM")
        {
            Petani *petani = dynamic_cast<Petani *>(currentPemain);

            if (petani != nullptr)
            {
                PetaniMemento *pm = new PetaniMemento(*(petani->getInventory()), petani->getBeratBadan(), petani->getGulden(), toko, *(petani->getLadang()));
                try
                {
                    petani->tanam();
                    petani->saveMemento(pm);
                }
                catch (const exception &e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
            }
            else
            {
                cout << "Kamu bukan petani!" << endl;
            }
        }
        else if (perintah == "TERNAK")
        {
            Peternak *peternak = dynamic_cast<Peternak *>(currentPemain);

            if (peternak != nullptr)
            {
                PeternakMemento* pm = new PeternakMemento(*(peternak->getInventory),peternak->getBeratBadan(),peternak->getGulden(),toko,*(peternak->getPeternakan()));

                peternak->ternak();
                peternak->saveMemento(pm);
            }
            else
            {
                cout << "Kamu bukan peternak!" << endl;
            }
        }
        else if (perintah == "BANGUN")
        {
            Walikota *walikota = dynamic_cast<Walikota *>(currentPemain);

            if (walikota != nullptr)
            {
                walikota->bangun();
            }
            else
            {
                cout << "Kamu bukan walikota!" << endl;
            }
        }
        else if (perintah == "MAKAN")
        {
            currentPemain->makan();
        }
        else if (perintah == "KASIH_MAKAN")
        {
            Peternak *peternak = dynamic_cast<Peternak *>(currentPemain);

            if (peternak != nullptr)
            {
                kasih_makan_driver(*peternak);
            }
            else
            {
                cout << "Kamu bukan peternak!" << endl;
            }
        }
        else if (perintah == "BELI")
        {
            Memento* m = new Memento(*(currentPemain->getInventory()),currentPemain->getBeratBadan(),currentPemain->getGulden(),&toko);
            beli_driver(*currentPemain);
            currentPemain->saveMemento(m);
        }
        else if (perintah == "JUAL")
        {
            Memento* m = new Memento(*(currentPemain->getInventory()),currentPemain->getBeratBadan(),currentPemain->getGulden(),&toko);
            jual_driver(*currentPemain);
            currentPemain->saveMemento(m);
        }
        else if (perintah == "PANEN")
        {
            // TODO : implementasi panen
            // * bisa peternak, bisa petani
            if (dynamic_cast<Walikota *>(currentPemain) != nullptr)
            {
                cout << "Kamu bukan Proletar!" << endl;
            }
            else if (dynamic_cast<Petani *>(currentPemain) != nullptr)
            {
                Petani *petani = dynamic_cast<Petani *>(currentPemain);
                petani->Panen();
            }
            else if (dynamic_cast<Peternak *>(currentPemain) != nullptr)
            {
                Peternak *peternak = dynamic_cast<Peternak *>(currentPemain);
                peternak->Panen();
            }
        }
        else if (perintah == "MUAT")
        {
            cout << "Apakah anda ingin memuat state ? (y/n) ";
            string jawaban;
            cin >> jawaban;
            if (jawaban == "y")
            {
                cout << "Masukkan lokasi berkas state : ";
                string filename;
                cin >> filename;
                readState(&filename);
                cout << "State berhasil dimuat!" << endl;
            }
        }
        else if (perintah == "SIMPAN")
        {
            cout << "Masukkan lokasi berkas state : ";
            string filepath;
            cin >> filepath;

            ofstream file;

            file.open(filepath);
            if (!file.is_open())
            {
                cout << "Lokasi berkas tidak valid!" << endl;
                continue;
            }
            else
            {
                simpan(&filepath);
                cout << "State berhasil disimpan!" << endl;
            }
        }
        else if (perintah == "TAMBAH_PEMAIN")
        {
            tambahPemain(*currentPemain);
        }
        else if (perintah == "UNDO")
        {
            // TODO : implementasi undo (nnti sm gw(cia) aja)
            if (dynamic_cast<Walikota *>(currentPemain) != nullptr)
            {
            }
            else if (dynamic_cast<Petani *>(currentPemain) != nullptr)
            {
            }
            else if (dynamic_cast<Peternak *>(currentPemain) != nullptr)
            {
            }else
            {

            }
        }
        else
        {
            cout << "Perintah tidak dikenali!" << endl;
        }
    }
    // TODO : delete"in pointer to objek
}