#include "Walikota.hpp"

Walikota::Walikota(string name, int row, int col) : Pemain(name, row, col)
{
}

Walikota::~Walikota()
{
}

void Walikota::bangun()
{
    // Validasi inventory
    if (!this->getInventory()->isEmpty(1))
    {
        InventoryPenuh e;
        throw e;
    }

    string jenis_bangunan;
    bool isSuccess = false;
    while (!isSuccess)
    {
        this->printResep();
        bool isValid = false;
        while (!isValid)
        {
            cout << "Bangunan yang ingin dibangun: ";
            cin >> jenis_bangunan;
            if (jenis_bangunan == "SMALL_HOUSE" || jenis_bangunan == "MEDIUM_HOUSE" || jenis_bangunan == "LARGE_HOUSE" || jenis_bangunan == "HOTEL")
            {
                isValid = true;
            }
            else
            {
                cout << "Resep tidak ditemukan untuk bangunan tersebut." << endl;
                continue;
            }
        }

        // Cari resep
        vector<string> recipe;
        int isFound = 0;
        for (size_t i = 0; i < listofResepBangunan.size() && isFound == 0; ++i)
        {
            recipe = listofResepBangunan[i];
            if (recipe[2] == jenis_bangunan)
            {
                isFound = 1;
            }
        }

        // Cari kekurangan bahan
        bool isBahanEnough = true;
        std::map<std::string, int> mapKekuranganBahan;
        for (size_t i = 4; i <= recipe.size() - 1; i += 2)
        {
            if (getListIdxBahanBangunan(recipe[i]).size() / 2 < stoi(recipe[i + 1]))
            {
                mapKekuranganBahan[recipe[i]] = stoi(recipe[i + 1]) - (getListIdxBahanBangunan(recipe[i]).size() / 2);
                isBahanEnough = false;
            }
        }

        // Validasi gulden cukup
        int kekuranganGulden = stoi(recipe[3]) - this->getGulden();

        // Print kekurangan bahan
        if (!isBahanEnough)
        {
            cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";

            if (kekuranganGulden > 0)
            {
                cout << kekuranganGulden << " gulden, ";
            }

            for (auto it = mapKekuranganBahan.begin(); it != mapKekuranganBahan.end(); ++it)
            {
                std::cout << it->second << " " << it->first;
                if (std::next(it) != mapKekuranganBahan.end())
                {
                    std::cout << ", ";
                }
            }
            cout << "!" << endl;
            continue;
        }
        else if (kekuranganGulden > 0)
        {
            cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan " << kekuranganGulden << " gulden!";
        }

        // Process bikin bangunan
        for (size_t i = 4; i < recipe.size() - 1; i += 2)
        {
            list<int> idx = getListIdxBahanBangunan(recipe[i]);
            int banyakBahan = stoi(recipe[i + 1]);
            while (banyakBahan > 0)
            {
                if (!idx.empty())
                {
                    int col = idx.back();
                    idx.pop_back();
                    int row = idx.back();
                    idx.pop_back();
                    this->Pemain::keluarkanItem(row, col);
                    --banyakBahan;
                }
            }
        }

        Bangunan *b = new Bangunan(jenis_bangunan, recipe[1], stoi(recipe[3]));
        this->Pemain::masukanItem(b);
        cout << jenis_bangunan << " berhasil dibangun dan telah menjadi hak milik walikota" << endl;
        isSuccess = true;
    }
}

void Walikota::bangun(WalikotaMemento* wm)
{
    // Validasi inventory
    if (!this->getInventory()->isEmpty(1))
    {
        InventoryPenuh e;
        throw e;
    }

    string jenis_bangunan;
    bool isSuccess = false;
    while (!isSuccess)
    {
        this->printResep();
        bool isValid = false;
        while (!isValid)
        {
            cout << "Bangunan yang ingin dibangun: ";
            cin >> jenis_bangunan;
            if (jenis_bangunan == "SMALL_HOUSE" || jenis_bangunan == "MEDIUM_HOUSE" || jenis_bangunan == "LARGE_HOUSE" || jenis_bangunan == "HOTEL")
            {
                isValid = true;
            }
            else
            {
                cout << "Resep tidak ditemukan untuk bangunan tersebut." << endl;
                continue;
            }
        }

        // Cari resep
        vector<string> recipe;
        int isFound = 0;
        for (size_t i = 0; i < listofResepBangunan.size() && isFound == 0; ++i)
        {
            recipe = listofResepBangunan[i];
            if (recipe[2] == jenis_bangunan)
            {
                isFound = 1;
            }
        }

        // Cari kekurangan bahan
        bool isBahanEnough = true;
        std::map<std::string, int> mapKekuranganBahan;
        for (size_t i = 4; i <= recipe.size() - 1; i += 2)
        {
            if (getListIdxBahanBangunan(recipe[i]).size() / 2 < stoi(recipe[i + 1]))
            {
                mapKekuranganBahan[recipe[i]] = stoi(recipe[i + 1]) - (getListIdxBahanBangunan(recipe[i]).size() / 2);
                isBahanEnough = false;
            }
        }

        // Validasi gulden cukup
        int kekuranganGulden = stoi(recipe[3]) - this->getGulden();

        // Print kekurangan bahan
        if (!isBahanEnough)
        {
            cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";

            if (kekuranganGulden > 0)
            {
                cout << kekuranganGulden << " gulden, ";
            }

            for (auto it = mapKekuranganBahan.begin(); it != mapKekuranganBahan.end(); ++it)
            {
                std::cout << it->second << " " << it->first;
                if (std::next(it) != mapKekuranganBahan.end())
                {
                    std::cout << ", ";
                }
            }
            cout << "!" << endl;
            continue;
        }
        else if (kekuranganGulden > 0)
        {
            cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan " << kekuranganGulden << " gulden!";
        }

        // Process bikin bangunan
        for (size_t i = 4; i < recipe.size() - 1; i += 2)
        {
            list<int> idx = getListIdxBahanBangunan(recipe[i]);
            int banyakBahan = stoi(recipe[i + 1]);
            while (banyakBahan > 0)
            {
                if (!idx.empty())
                {
                    int col = idx.back();
                    idx.pop_back();
                    int row = idx.back();
                    idx.pop_back();
                    this->Pemain::keluarkanItem(row, col);
                    --banyakBahan;
                }
            }
        }

        Bangunan *b = new Bangunan(jenis_bangunan, recipe[1], stoi(recipe[3]));
        this->Pemain::masukanItem(b);
        cout << jenis_bangunan << " berhasil dibangun dan telah menjadi hak milik walikota" << endl;
        isSuccess = true;
        wm->insertCreatedItem(b);
    }
}

float Walikota::HitungPajak()
{
    return 0;
}

void Walikota::addResep(std::vector<string> &resep)
{
    this->listofResepBangunan.push_back(resep);
}

std::list<int> Walikota::getListIdxBahanBangunan(std::string item)
{
    std::list<int> itemPosition;
    Inventory *inventory = this->getInventory();
    if (inventory)
    {
        int numRows = inventory->getRow();
        int numCols = inventory->getCol();
        for (int row = 0; row < numRows; ++row)
        {
            for (int col = 0; col < numCols; ++col)
            {
                Item *currentItem = inventory->getItem(row, col);
                if (currentItem && currentItem->getName() == item)
                {
                    itemPosition.push_back(row);
                    itemPosition.push_back(col);
                }
            }
        }
    }
    return itemPosition;
}

void Walikota::printResep()
{
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    int count = 1;
    for (const auto &resep : this->listofResepBangunan)
    {
        cout << "    " << count++ << ". " << resep[2] << " (" << resep[3] << " gulden, ";
        for (size_t i = 4; i < resep.size(); i += 2)
        {
            if (i + 1 < resep.size())
            {
                cout << resep[i + 1] << " " << resep[i];
                if (i + 2 < resep.size())
                {
                    cout << ", ";
                }
            }
        }
        cout << ")" << endl;
    }
}

void Walikota::pungutPajak(priority_queue<Pemain *> listPemain)
{
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << "Berikut adalah detil dari pemungutan pajak: " << endl;
    priority_queue<Pemain *> tempQueue = listPemain;
    int number = 1;
    while (!tempQueue.empty())
    {
        Pemain *player = tempQueue.top();
        int pajak = player->HitungPajak();
        player->kurangiGulden(pajak);
        this->tambahkanGulden(pajak);
        tempQueue.pop();
        if (player->getTipePemain() != "Walikota"){
            cout << "    " << number << ". " << player->getName() << " - " << player->getTipePemain() << ": " << pajak << " gulden" << endl;
            number++;
        }    
    } 
}

string Walikota::getTipePemain(){
    return "Walikota";
}