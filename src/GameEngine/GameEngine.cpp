#include "GameEngine.hpp"
#include <cstring>
#include <iostream>

using namespace std;

GameEngine::GameEngine()
{
    readConfig();

    Walikota *walikota = new Walikota("Bondowoso", ukuranInventory.first, ukuranInventory.second);
    walikota->tambahkanGulden(50);
    walikota->tambahBeratBadan(40);
    copyRecipeToWalikota(*walikota);

    pushPemain(walikota);

    this->toko = new Toko();
    copyDataToToko(*toko);
}

GameEngine::~GameEngine()
{
    // mapNamaPemain.clear();
    while (!daftarPemainKeseluruhan.empty())
    {
        delete daftarPemainKeseluruhan.at(daftarPemainKeseluruhan.size() - 1);
        daftarPemainKeseluruhan.pop_back();
    }
    while (toko->getListItemToko()->size() > 0)
    {
        while (toko->getListItemToko()->back().size() > 0)
        {
            delete toko->getListItemToko()->back().back();
            toko->getListItemToko()->back().pop_back();
        }
        toko->getListItemToko()->pop_back();
    }
    delete toko;
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

    // toko->initializedToko(dataOfHewan, dataOfTanaman);
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
    stringstream masukan = bacaFile(*filename);
    string line;

    // kosongkan pemainList, pemainListNextTurn, dan daftarPemainKeseluruhan
    while (!pemainList.empty())
    {
        pemainList.pop();
    }

    while (!pemainListNextTurn.empty())
    {
        pemainListNextTurn.pop();
    }

    daftarPemainKeseluruhan.clear();

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
            pemain = new Petani(namaPemain, ukuranInventory.first, ukuranInventory.second, ukuranLadang.first, ukuranLadang.second);
        }
        else if (jenisPemain == "Peternak")
        {
            // buat pemain proletar
            pemain = new Peternak(namaPemain, ukuranInventory.first, ukuranInventory.second, ukuranPeternakan.first, ukuranPeternakan.second);
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
            // printResep();
        }
        pushPemain(pemain);
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

Pemain *GameEngine::getPemainByName(string namaPemain)
{
    return mapNamaPemain[namaPemain];
}

void GameEngine::pushPemain(Pemain *p)
{
    pemainList.push(p->getName());
    daftarPemainKeseluruhan.push_back(p);
    mapNamaPemain[p->getName()] = p;
}

void GameEngine::tambahPemain(Pemain &pemain, WalikotaMemento *wm)
{
    Walikota *walikota = dynamic_cast<Walikota *>(currentPemain);
    string jenis, nama;
    if (walikota != nullptr)
    {
        try
        {
            cout << "Masukkan jenis pemain: ";
            cin >> jenis;
            cout << "Masukkan nama pemain: ";
            cin >> nama;
            if (walikota->getGulden() < 50)
            {
                GuldenTidakCukup e;
                throw e;
            }
            if (walikota->isNamaSudahAda(daftarPemainKeseluruhan, nama))
            {
                NamaPlayerTerpakai e;
                throw e;
            }
            if (jenis != "petani")
            {
                if (jenis != "peternak")
                {
                    PeranInvalid e;
                    throw e;
                }
            }
        }
        catch (GuldenTidakCukup e)
        {
            delete wm;
            cout << e.what() << endl;
            return;
        }
        catch (NamaPlayerTerpakai e)
        {
            delete wm;
            cout << e.what() << endl;
            return;
        }
        catch (PeranInvalid e)
        {
            delete wm;
            cout << e.what() << endl;
            return;
        }
        if (jenis == "petani")
        {
            Petani *p = new Petani(nama, ukuranInventory.first, ukuranInventory.second, ukuranLadang.first, ukuranLadang.second);
            p->tambahkanGulden(50);
            walikota->kurangiGulden(50);
            pushPemain(p);
            wm->insertCreatedPemain(p);
            cout << "Pemain baru ditambahkan!" << endl;
            cout << "Selamat datang \"" << nama << "\" di kota ini!" << endl;
        }
        else
        {
            Peternak *p = new Peternak(nama, ukuranInventory.first, ukuranInventory.second, ukuranPeternakan.first, ukuranPeternakan.second);
            p->tambahkanGulden(50);
            walikota->kurangiGulden(50);
            pushPemain(p);
            wm->insertCreatedPemain(p);
            daftarPemainKeseluruhan.push_back(p);
            cout << "Pemain baru ditambahkan!" << endl;
            cout << "Selamat datang \"" << nama << "\" di kota ini!" << endl;
        }
        walikota->saveMemento(wm);
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

    listSemuaPemain.push_back(currentPemain);

    vector<Pemain *> pemainListCopy;
    // copy isi pemainList ke pemainListCopy
    while (!pemainList.empty())
    {
        Pemain *pemain = getPemainByName(pemainList.top());
        pemainList.pop();
        pemainListCopy.push_back(pemain);
    }

    vector<Pemain *> pemainListNextTurnCopy;
    // copy isi pemainListNextTurn ke pemainListNextTurnCopy
    while (!pemainListNextTurn.empty())
    {
        Pemain *pemain = getPemainByName(pemainListNextTurn.top());
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
        pemainList.push(pemain->getName());
    }

    for (auto &pemain : pemainListNextTurnCopy)
    {
        pemainListNextTurn.push(pemain->getName());
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
    PeternakMemento* pm = new PeternakMemento(*(peternak.getInventory()),peternak.getBeratBadan(),peternak.getGulden(),*toko,*(peternak.getPeternakan()));
    cout << "Pilih petak kandang yang akan ditinggali" << endl;

    peternak.CetakPetak();

    cout << "Petak kandang: ";
    string petak;
    cin >> petak;

    // ubah petak jadi koordinat
    pair<int, int> pos = positionStringToPair(petak);

    try
    {
        // // test print pos.first dan pos.second
        // cout << pos.first << " " << pos.second << endl;

        peternak.kasih_makan(pos.first, pos.second,pm);
    }
    catch (BukanHewan e)
    {
        delete pm;
        cout << e.what() << endl;
    }
    catch (SlotKosong e)
    {
        delete pm;
        cout << e.what() << endl;
    }
    catch (WrongFood e)
    {
        delete pm;
        cout << e.what() << endl;
    }
    catch (BukanMakanan e)
    {
        delete pm;
        cout << e.what() << endl;
    }
    catch (PetakTidakValid e)
    {
        delete pm;
        cout << e.what() << endl;
    }
}

void GameEngine::beli_driver(Pemain &pemain, Memento* m)
{
    std::cout << "Selamat datang di toko!!" << std::endl;
    std::cout << "Berikut merupakan hal yang dapat Anda beli: " << std::endl;

    int tipePemain = 0;
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

    int idxItem, kuantitas;
    try
    {
        std::cout << "Barang yang ingin dibeli: ";
        if (!(std::cin >> idxItem))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Tipe data invalid!");
        }

        std::cout << "Kuantitas: ";
        if (!(std::cin >> kuantitas))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Tipe data invalid!");
        }
    }
    catch (const std::runtime_error &e)
    {
        delete m;
        std::cout << e.what() << std::endl;
        return;
    }

    int kuantitasToko = toko->getTotalItemKeN(idxItem - 1);

    try
    {
        // if (typeid(idxItem) != typeid(int) || typeid(kuantitas) != typeid(int))
        // {
        //     InvalidDataType e;
        //     throw e;
        // }
        if (kuantitas < 1)
        {
            throw KuantitasTidakValid();
        }
        if (kuantitas > kuantitasToko)
        {
            if (idxItem > 15)
            {
                throw KuantitasTidakValid();
            }
        }
        if (tipePemain == 1 && (idxItem <= 0 || idxItem > toko->getTotalItem() + 15 - toko->getTotalBangunan()))
        {
            throw IndexOutOfRange();
        }
        if (tipePemain != 1 && (idxItem <= 0 || idxItem > toko->getTotalItem() + 15))
        {
            throw IndexOutOfRange();
        }
    }
    // catch (InvalidDataType &e)
    // {
    //     cout << e.what() << endl;
    //     return;
    // }
    catch (KuantitasTidakValid &e)
    {
        delete m;
        cout << e.what() << endl;
        return;
    }
    catch (IndexOutOfRange &e)
    {
        delete m;
        cout << e.what() << endl;
        return;
    }

    // cout << "debug 1" << endl;

    string namaItem = toko->itemKeN(idxItem - 1)->getName();

    // cout << "debug 2" << endl;

    int totalHarga = toko->itemKeN(idxItem - 1)->getHarga() * kuantitas;

    // cout << "debug 3" << endl;

    try
    {
        if (kuantitas > slotTersedia)
        {
            throw PenyimpananTidakCukup();
        }

        if (pemain.getGulden() < totalHarga)
        {
            throw UangTidakCukup();
        }
    }
    catch (PenyimpananTidakCukup &e)
    {
        delete m;
        cout << e.what() << endl;
        return;
    }
    catch (UangTidakCukup &e)
    {
        delete m;
        cout << e.what() << endl;
        return;
    }

    // cout << "debug 4" << endl;

    std::list<Item *> listBarangDibeli;
    listBarangDibeli = toko->removeItem(idxItem, kuantitas, pemain.getGulden(), slotTersedia);

    for (auto it = listBarangDibeli.begin(); it != listBarangDibeli.end(); ++it)
    {
        pemain.masukanItem(*it);
    }

    // cout << "debug 5" << endl;

    pemain.kurangiGulden(totalHarga);

    // cout << "debug 6" << endl;

    std::cout << "Selamat Anda berhasil membeli " << kuantitas << " " << namaItem << ". Uang Anda tersisa " << pemain.getGulden() << " gulden." << std::endl;
    pemain.saveMemento(m);
}

void GameEngine::jual_driver(Pemain &pemain)
{
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    pemain.getInventory()->printInventory();

    string petak_petak;
    cout << "Silahkan pilih petak yang ingin anda jual!\nPetak  : ";
    cin.ignore();
    getline(cin, petak_petak);

    // masukan semua petak ke dalam vector
    vector<string> petakTerpilih = stringSplitter(petak_petak, ',');
    // test print petak
    for (const std::string &petak : petakTerpilih)
    {
        std::cout << petak << std::endl;
    }

    for (auto &petak : petakTerpilih)
    {
        // Cek petak kosong
        if (pemain.getInventory()->getItem(petak) == nullptr)
        {
            PetakKosong e;
            throw e;
        }

        // Validasi jenis item
        Item *item = pemain.getInventory()->getItem(petak);
        if (dynamic_cast<Bangunan *>(item) != nullptr)
        {
            // Cek apakah pemain bukan Walikota
            if (!dynamic_cast<Walikota *>(&pemain))
            {
                JualBangunan e;
                throw e;
            }
        }
    }

    // hapus item yang dijual dari inventory pemain dan tambahkan gulden pemain serta item ke toko
    for (const string &petak : petakTerpilih)
    {
        Item *item = pemain.getInventory()->getItem(petak);
        if (item != nullptr)
        {
            // Tambahkan item ke toko
            toko->addItem(item);
        }
    }
    pemain.jual(petakTerpilih);
}

bool GameEngine::cekMenang(Pemain *pemain)
{
    if (pemain->getGulden() >= guldenMenang && pemain->getBeratBadan() >= beratBadanMenang)
    {
        return true;
    }
    return false;
}

void GameEngine::displayMenang(Pemain *pemain)
{
    cout << "Selamat " << pemain->getName() << " telah menang!" << endl;
    // * ini kalo ada yang mau memperbagus boleh aja yak
}

void GameEngine::initGame()
{
    string perintah;
    toko = new Toko();
    toko->initializedToko(dataOfHewan, dataOfTanaman);
    bool isInit = false;
    
    // Animasi awal
    printHomePage(homePage1, homePage2, 7, 500);
    cout << welcome << endl;

    cout << "Apakah anda ingin memuat state ? (y/n) ";
    string jawaban;
    cin >> jawaban;
    if (jawaban == "y")
    {
        while (!pemainList.empty())
        {
            pemainList.pop();
        }
        while (!pemainListNextTurn.empty())
        {
            pemainListNextTurn.pop();
        }
        cout << "Masukkan lokasi berkas state : ";
        string filename;
        cin >> filename;
        
        try {
            readState(&filename);
        }
        catch (TidakDapatBukaFile e) {
            cout << e.what() << endl;
        }

        currentPemain = getPemainByName(pemainList.top());
        pemainList.pop();
        printLoadingAnimation();
        isInit = true;

        // Animasi sesuai pemain
        if (dynamic_cast<Walikota *>(currentPemain) != nullptr)
        {
            printAnimation(walikota, walikota2, 5, 500, p_rgb(102,174,233));
        }
        else if (dynamic_cast<Petani *>(currentPemain) != nullptr)
        {
            printAnimation(petani, petani2, 5, 500, p_rgb(223,47,229));
        }
        else if (dynamic_cast<Peternak *>(currentPemain) != nullptr)
        {
            printAnimation(peternak, peternak2, 5, 500, p_rgb(144,105,232));
        }
    }
    else if (jawaban == "n")    
    {
        while (!pemainList.empty())
        {
            pemainList.pop();
        }
        while (!pemainListNextTurn.empty())
        {
            pemainListNextTurn.pop();
        }
        string filename = "config/defaultstate.txt";
        try {
            readState(&filename);
        }
        catch (TidakDapatBukaFile e) {
            cout << e.what() << endl;
        }

        currentPemain = getPemainByName(pemainList.top());
        pemainList.pop();
        printLoadingAnimation();
        isInit = true;

        // Animasi sesuai pemain
        if (dynamic_cast<Walikota *>(currentPemain) != nullptr)
        {
            printAnimation(walikota, walikota2, 5, 500, p_rgb(102,174,233));
        }
        else if (dynamic_cast<Petani *>(currentPemain) != nullptr)
        {
            printAnimation(petani, petani2, 5, 500, p_rgb(223,47,229));
        }
        else if (dynamic_cast<Peternak *>(currentPemain) != nullptr)
        {
            printAnimation(peternak, peternak2, 5, 500, p_rgb(144,105,232));
        }
    }
    else {
        cout << "Input tidak valid!" << endl;
    }

    while (true)
    {
        if (isInit)
        {
            cout << p_rgb(255, 255, 153) << "\nSaat ini giliran " << currentPemain->getName() << endl << reset();
        }

        // Menerima perintah dari pengguna
        cout
            << p_rgb(246,168,53) << "\n> " << reset();
        cin >> perintah;

        if (perintah == "NEXT")
        {
            // quq sementara untuk menyimpan pemain (UNTUK UMUR TANAMAN TIAP NEXT)
            std::queue<Pemain *> tempQueue;

            while (!pemainList.empty())
            {
                Pemain *temp = getPemainByName(pemainList.top());
                pemainList.pop();

                //  cek apakah pemain adalah petani
                if (dynamic_cast<Petani *>(temp) != nullptr)
                {
                    Petani *petani = dynamic_cast<Petani *>(temp);
                    petani->tambahDurasiTanamanDiLadang();
                }

                tempQueue.push(temp);
            }

            while (!tempQueue.empty())
            {
                pemainList.push(tempQueue.front()->getName());
                tempQueue.pop();
            }

            currentPemain->getActionHistory()->cleanHistory();
            pemainListNextTurn.push(currentPemain->getName());
            if (!pemainList.empty())
            {
                currentPemain = getPemainByName(pemainList.top());
                pemainList.pop();
            }
            else
            {
                while (!pemainListNextTurn.empty())
                {
                    pemainList.push(pemainListNextTurn.top());
                    pemainListNextTurn.pop();
                }
                currentPemain = getPemainByName(pemainList.top());
                pemainList.pop();
            }

            // Animasi sesuai pemain
            if (dynamic_cast<Walikota *>(currentPemain) != nullptr)
            {
                printAnimation(walikota, walikota2, 5, 500, p_rgb(102,174,233));
            }
            else if (dynamic_cast<Petani *>(currentPemain) != nullptr)
            {
                printAnimation(petani, petani2, 5, 500, p_rgb(223,47,229));
            }
            else if (dynamic_cast<Peternak *>(currentPemain) != nullptr)
            {
                printAnimation(peternak, peternak2, 5, 500, p_rgb(144,105,232));
            }

            // // quq sementara untuk menyimpan pemain
            // std::queue<Pemain *> tempQueue;

            // while (!pemainList.empty())
            // {
            //     Pemain *temp = getPemainByName(pemainList.top());
            //     pemainList.pop();

            //     //  cek apakah pemain adalah petani
            //     if (dynamic_cast<Petani *>(temp) != nullptr)
            //     {
            //         Petani *petani = dynamic_cast<Petani *>(temp);
            //         petani->tambahDurasiTanamanDiLadang();
            //     }

            //     tempQueue.push(temp);
            // }

            // while (!tempQueue.empty())
            // {
            //     pemainList.push(tempQueue.front()->getName());
            //     tempQueue.pop();
            // }

            // Pemain *temp = getPemainByName(pemainList.top());
            // pemainList.pop();
            // pemainListNextTurn.push(temp->getName());
            // if (pemainList.empty())
            // {
            //     while (!pemainListNextTurn.empty())
            //     {
            //         pemainList.push(pemainListNextTurn.top());
            //         pemainListNextTurn.pop();
            //     }
            // }
            // currentPemain = getPemainByName(pemainList.top());
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
                WalikotaMemento *wm = new WalikotaMemento(*(walikota->getInventory()), walikota->getBeratBadan(), walikota->getGulden(), *toko);
                int i;
                wm->insertPemainGulden(daftarPemainKeseluruhan);
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
                PetaniMemento *pm = new PetaniMemento(*(petani->getInventory()), petani->getBeratBadan(), petani->getGulden(), *toko, *(petani->getLadang()));
                try
                {
                    petani->tanam();
                    petani->saveMemento(pm);
                }
                catch (LadangPenuh e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
                catch (InvalidGridSlot e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
                catch (PetakKosong e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
                catch (BukanTanaman e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
                catch (PetakTidakValid e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
                catch (PetakSudahTerisi e)
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
                // Izin komen dulu lagi yah cia -@evelynnn04
                PeternakMemento *pm = new PeternakMemento(*(peternak->getInventory()), peternak->getBeratBadan(), peternak->getGulden(), *toko, *(peternak->getPeternakan()));

                try
                {
                    peternak->ternak();
                    peternak->saveMemento(pm);
                }
                catch (KandangPenuh e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
                catch (InvalidGridSlot e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
                catch (PetakKosong e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
                catch (BukanHewan e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
                catch (PetakTidakValid e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
                catch (PetakKandangSudahTerisi e)
                {
                    delete pm;
                    cout << e.what() << endl;
                }
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
                WalikotaMemento *wm = new WalikotaMemento(*(walikota->getInventory()), walikota->getBeratBadan(), walikota->getGulden(), *toko);
                try{
                    walikota->bangun(wm);
                }catch (InventoryPenuh e){
                    delete wm;
                    cout << e.what() << endl; 
                }
            }
            else
            {
                cout << "Kamu bukan walikota!" << endl;
            }
        }
        else if (perintah == "MAKAN")
        {
            Memento* m = new Memento(*(currentPemain->getInventory()),currentPemain->getBeratBadan(),currentPemain->getGulden(),toko);
            try
            {
                currentPemain->makan(m);
            }
            catch (TidakAdaMakananDiInventory e)
            {
                delete m;
                cout << e.what() << endl;
            }
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
            Memento *m = new Memento(*(currentPemain->getInventory()), currentPemain->getBeratBadan(), currentPemain->getGulden(), toko);
            beli_driver(*currentPemain, m);
        }
        else if (perintah == "JUAL")
        {
            try
            {
                Memento *m = new Memento(*(currentPemain->getInventory()), currentPemain->getBeratBadan(), currentPemain->getGulden(), toko);
                jual_driver(*currentPemain);
                currentPemain->saveMemento(m);
            }
            catch (PetakTidakValid e)
            {
                cout << e.what() << endl;
            }
            catch (PetakKosong e)
            {
                cout << e.what() << endl;
            }
            catch (JualBangunan e)
            {
                cout << e.what() << endl;
            }
        }
        else if (perintah == "PANEN")
        {
            if (dynamic_cast<Walikota *>(currentPemain) != nullptr)
            {
                cout << "Kamu bukan Proletar!" << endl;
            }
            else if (dynamic_cast<Petani *>(currentPemain) != nullptr)
            {
                try
                {
                    Petani *petani = dynamic_cast<Petani *>(currentPemain);
                    petani->Panen();
                }
                catch (PilihanTanamanInvalid e)
                {
                    cout << e.what() << endl;
                }
                catch (PetakPanenInvalid e)
                {
                    cout << e.what() << endl;
                }
                catch (PetakTidakValid e)
                {
                    cout << e.what() << endl;
                }
                catch (BelumSiapPanen e)
                {
                    cout << e.what() << endl;
                }
            }
            else if (dynamic_cast<Peternak *>(currentPemain) != nullptr)
            {
                try
                {
                    Peternak *peternak = dynamic_cast<Peternak *>(currentPemain);
                    peternak->Panen();
                }
                catch (PilihanHewanInvalid e)
                {
                    cout << e.what() << endl;
                }
                catch (PetakPanenInvalid e)
                {
                    cout << e.what() << endl;
                }
                catch (PetakTidakValid e)
                {
                    cout << e.what() << endl;
                }
                catch (BelumSiapPanen e)
                {
                    cout << e.what() << endl;
                }
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
            if (dynamic_cast<Walikota *>(currentPemain) != nullptr)
            {
                WalikotaMemento *wm = new WalikotaMemento(*(currentPemain->getInventory()), currentPemain->getBeratBadan(), currentPemain->getGulden(), *toko);
                tambahPemain(*currentPemain, wm);
            }
            else
            {
                cout << "Hanya Walikota yang dapat menambahkan pemain!" << endl;
            }
        }
        else if (perintah == "UNDO")
        {
            if (!currentPemain->getActionHistory()->isHistoryEmpty())
            {
                if (dynamic_cast<Walikota *>(currentPemain) != nullptr)
                {
                    Walikota *walikota = dynamic_cast<Walikota *>(currentPemain);
                    if (dynamic_cast<WalikotaMemento *>(walikota->getActionHistory()->topMemento()) != nullptr)
                    {
                        WalikotaMemento *wm = dynamic_cast<WalikotaMemento *>(walikota->getActionHistory()->topMemento());
                        walikota->undoDaftarPemain(&daftarPemainKeseluruhan, &pemainList, wm, &mapNamaPemain);
                    }
                    walikota->undo(toko, daftarPemainKeseluruhan);
                }
                else if (dynamic_cast<Petani *>(currentPemain) != nullptr)
                {
                    Petani *petani = dynamic_cast<Petani *>(currentPemain);
                    petani->undo(toko, daftarPemainKeseluruhan);
                }
                else if (dynamic_cast<Peternak *>(currentPemain) != nullptr)
                {
                    Peternak *peternak = dynamic_cast<Peternak *>(currentPemain);
                    peternak->undo(toko, daftarPemainKeseluruhan);
                }
            }
            else
            {
                cout << "Tidak bisa undo, belum melakukan aksi apapun" << endl;
            }
        }
        else if (perintah == "EXIT")
        {
            break;
        }
        else
        {
            cout << "Perintah tidak dikenali!" << endl;
        }

        if (cekMenang(currentPemain))
        {
            displayMenang(currentPemain);
            cout << "Permainan berakhir" << endl;
            break;
        }
    }
    // TODO : delete"in pointer to objek
}

// Buat coba2
void GameEngine::printDataOfTanaman()
{
    for (const auto &innerVector : dataOfTanaman)
    {
        for (const auto &str : innerVector)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
}

void GameEngine::printDataOfHewan()
{
    for (const auto &innerVector : dataOfHewan)
    {
        for (const auto &str : innerVector)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
}

void GameEngine::printResep()
{
    for (const auto &innerVector : listOfResepBangunan)
    {
        for (const auto &str : innerVector)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
}