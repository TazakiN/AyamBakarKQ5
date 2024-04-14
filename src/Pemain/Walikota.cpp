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

    bool isSuccess = false;
    while (!isSuccess)
    {
        printResep();
        bool isValid = false;
        string jenis_bangunan;
        vector<string> recipe;
        size_t i = 0;
        while (!isValid)
        {
            cout << "Bangunan yang ingin dibangun: ";
            cin >> jenis_bangunan;
            if (jenis_bangunan == "SMALL_HOUSE" || jenis_bangunan == "MEDIU,_HOUSE" || jenis_bangunan == "BIG_HOUSE" || jenis_bangunan == "HOTEL")
            {
                isValid = true;
            }
        }
        int isFound = 0;
        bool isBahanEnough = true;
        std::map<std::string, int> mapKekuranganBahan;

        // Cari resep
        while (i < listofResepBangunan.size() && isFound == 0)
        {
            recipe = listofResepBangunan[i];
            if (recipe[2] == jenis_bangunan)
            {
                isFound = 1;
            }
            ++i;
        }

        // Validasi gulden cukup
        int kekuranganGulden = 0;
        if (this->getGulden() < stoi(recipe[3]))
        {
            kekuranganGulden = stoi(recipe[3]) - this->getGulden();
        }

        // Cari kekurangan bahan
        i = 4;
        while (i < recipe.size() - 1)
        {
            if (getListIdxBahanBangunan(recipe[i]).size() < stoi(recipe[i + 1]))
            {
                mapKekuranganBahan[recipe[i]] = stoi(recipe[i + 1]) - (getListIdxBahanBangunan(recipe[i]).size() / 2);
                isBahanEnough = false;
            }
            i += 2;
        }

        // print kekurangan bahan
        if (kekuranganGulden > 0 || !isBahanEnough)
        {
            cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
            if (kekuranganGulden > 0 && !isBahanEnough)
            {
                cout << kekuranganGulden << "gulden, ";
            }
            else if (isBahanEnough)
            {
                cout << kekuranganGulden << "gulden!" << endl;
            }
            else
            {
                for (auto it = mapKekuranganBahan.begin(); it != mapKekuranganBahan.end(); ++it)
                {
                    std::cout << it->second << " " << it->first;
                    if (std::next(it) != mapKekuranganBahan.end())
                    {
                        std::cout << ", ";
                    }
                }
                cout << "!" << endl;
            }
        }
        else
        {
            isSuccess = true;
        }

        // proses bikin bangunan
        i = 4;
        int row, col;
        while (i < recipe.size() - 1)
        {
            list<int> idx = getListIdxBahanBangunan(recipe[i]);
            int banyakBahan = stoi(recipe[i + 1]);
            while (banyakBahan > 0)
            {
                row = idx.back();
                idx.pop_back();
                col = idx.back();
                idx.pop_back();
                this->Pemain::keluarkanItem(row, col);
                banyakBahan--;
            }
            i += 2;
        }
        Bangunan *b = new Bangunan(jenis_bangunan, recipe[1], stoi(recipe[3]));
        this->Pemain::masukanItem(b);
        cout << jenis_bangunan << "berhasil dibangun dan telah menjadi hak milik walikota" << endl;
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
            if (i + 1 < resep.size()) {
                cout << resep[i + 1] << " " << resep[i];
                if (i+2 < resep.size())
                {
                    cout << ", ";
                }
            }
        }
        cout << ")" << endl;
    }
}

