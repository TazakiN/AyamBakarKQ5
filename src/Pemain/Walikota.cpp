#include "Walikota.hpp"

Walikota::Walikota(string name, int row, int col) : Pemain(name, row, col)
{
}

Walikota::~Walikota()
{
}

void Walikota::bangun()
{
    string jenis_bangunan;
    bool isSuccess = false;
    vector<string> recipe;
    this->printResep();
    bool isValid = false;
    while (!isValid)
    {
        std::cout << "Bangunan yang ingin dibangun: ";
        cin >> jenis_bangunan;
        if (jenis_bangunan == "SMALL_HOUSE" || jenis_bangunan == "MEDIUM_HOUSE" || jenis_bangunan == "LARGE_HOUSE" || jenis_bangunan == "HOTEL")
        {
            isValid = true;
        }
        else
        {
            std::cout << "Resep tidak ditemukan untuk bangunan tersebut." << endl;
            this->printResep();
            continue;
        }
    }

    // Cari resep
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

    // Print kekurangan bahan
    if (!isBahanEnough)
    {
        std::cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";

        for (auto it = mapKekuranganBahan.begin(); it != mapKekuranganBahan.end(); ++it)
        {
            std::cout << it->second << " " << it->first;
            if (std::next(it) != mapKekuranganBahan.end())
            {
                std::cout << ", ";
            }
        }
        std::cout << "!" << endl;
        return;
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
    std::cout << jenis_bangunan << " berhasil dibangun dan telah menjadi hak milik walikota" << endl;
    isSuccess = true;
}

void Walikota::bangun(WalikotaMemento *wm)
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
            std::cout << "Bangunan yang ingin dibangun: ";
            cin >> jenis_bangunan;
            if (jenis_bangunan == "SMALL_HOUSE" || jenis_bangunan == "MEDIUM_HOUSE" || jenis_bangunan == "LARGE_HOUSE" || jenis_bangunan == "HOTEL")
            {
                isValid = true;
            }
            else
            {
                std::cout << "Resep tidak ditemukan untuk bangunan tersebut." << endl;
                printResep();
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

        // Print kekurangan bahan
        if (!isBahanEnough)
        {
            std::cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";

            for (auto it = mapKekuranganBahan.begin(); it != mapKekuranganBahan.end(); ++it)
            {
                std::cout << it->second << " " << it->first;
                if (std::next(it) != mapKekuranganBahan.end())
                {
                    std::cout << ", ";
                }
            }
            std::cout << "!" << endl;
            return;
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
        std::cout << jenis_bangunan << " berhasil dibangun dan telah menjadi hak milik walikota" << endl;
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
    std::cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    int count = 1;
    for (const auto &resep : this->listofResepBangunan)
    {
        std::cout << "    " << count++ << ". " << resep[2] << " (";
        for (size_t i = 4; i < resep.size(); i += 2)
        {
            if (i + 1 < resep.size())
            {
                std::cout << resep[i + 1] << " " << resep[i];
                if (i + 2 < resep.size())
                {
                    std::cout << ", ";
                }
            }
        }
        std::cout << ")" << endl;
    }
}

void Walikota::pungutPajak(priority_queue<Pemain *> listPemain)
{
    std::cout << "Cring cring cring..." << endl;
    std::cout << "Pajak sudah dipungut!" << endl;
    std::cout << "Berikut adalah detil dari pemungutan pajak: " << endl;
    priority_queue<Pemain *> tempQueue = listPemain;
    int number = 1;
    while (!tempQueue.empty())
    {
        Pemain *player = tempQueue.top();
        int pajak = player->HitungPajak();
        player->kurangiGulden(pajak);
        this->tambahkanGulden(pajak);
        tempQueue.pop();
        if (player->getTipePemain() != "Walikota")
        {
            std::cout << "    " << number << ". " << player->getName() << " - " << player->getTipePemain() << ": " << pajak << " gulden" << endl;
            number++;
        }
    }
}

string Walikota::getTipePemain()
{
    return "Walikota";
}