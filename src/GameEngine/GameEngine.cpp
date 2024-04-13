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
                    // TODO : isi inventory berdasarkan jenis tanaman (tunggu implementasi Tanaman)
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
                getline(ss2, token, ' ');
                int progressPanenMakhluk = stoi(token);

                if (jenisPemain == "Petani")
                {
                    // TODO : bikin si tanamannya (tunggu implementasi Tanaman)
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
    // TODO : implementasi simpan data Toko

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
    int col = petak[0] - 'A';
    int row1 = petak[1] - '0';
    int row2 = petak[2] - '0';
    int row = row1 * 10 + row2;

    peternak.kasih_makan(row, col);
}

void GameEngine::beli_driver(Pemain &pemain)
{
    // TODO : implementasi beli (aku masih gangerti toko tuh gimana)
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

    // TODO : tambah item yang dijual ke toko

    // hapus item yang dijual dari inventory pemain dan tambahkan gulden pemain
    pemain.jual(petakTerpilih);
}

void GameEngine::initGame()
{
    string perintah;
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
                // TODO : implementasi pungut pajak
                // walikota->pungutPajak(pemainList);
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
                petani->tanam();
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
                peternak->ternak();
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
                // TODO : implementasi bangun
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
            beli_driver(*currentPemain);
        }
        else if (perintah == "JUAL")
        {
            jual_driver(*currentPemain);
        }
        else if (perintah == "PANEN")
        {
            // TODO : implementasi panen
            // * bisa peternak, bisa petani
        }
        else if (perintah == "MUAT")
        {
            cout << "apakah anda ingin memuat state ? (y/n) ";
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
            cout << "Masukkan Masukkan lokasi berkas state : ";
            string filepath;
            cin >> filepath;
            simpan(&filepath);
            // validasi apakah foldernya ada
            string directory;
            const size_t last_slash_idx = filepath.rfind('\\');
            if (std::string::npos != last_slash_idx)
            {
                directory = filepath.substr(0, last_slash_idx);
            }
            if (validateDirectory(directory))
            {
                simpan(&filepath);
            }
            else
            {
                cout << "Lokasi berkas tidak valid!" << endl;
            }
            cout << "State berhasil disimpan!" << endl;
        }
        else if (perintah == "TAMBAH_PEMAIN")
        {
            // TODO : implementasi tambah pemain
        }
        else
        {
            cout << "Perintah tidak dikenali!" << endl;
        }
    }
}