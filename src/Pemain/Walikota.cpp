#include "Walikota.hpp"
#include "../Memento/WalikotaMemento.hpp"

Walikota::Walikota(string name, int row, int col) : Pemain(name, row, col)
{
}

Walikota::~Walikota()
{
}

void Walikota::bangun()
{
    string jenis_bangunan;
    vector<string> recipe;
    bool isValid = false;
    while (!isValid)
    {
        this->printResep();
        std::cout << "Bangunan yang ingin dibangun: ";
        cin >> jenis_bangunan;
        if (jenis_bangunan == "SMALL_HOUSE" || jenis_bangunan == "MEDIUM_HOUSE" || jenis_bangunan == "LARGE_HOUSE" || jenis_bangunan == "HOTEL")
        {
            isValid = true;
        }
        else
        {
            std::cout << "Resep tidak ditemukan untuk bangunan tersebut." << endl;
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
                string itemToPrint;
                if (it->first == "TEAK_WOOD")
                {
                    itemToPrint = "teak wood";
                }
                else if (it->first == "SANDALWOOD_WOOD")
                {
                    itemToPrint = "sandalwood wood";
                }
                else if (it->first == "ALOE_WOOD")
                {
                    itemToPrint = "aloe wood";
                }
                else if (it->first == "IRONWOOD_WOOD")
                {
                    itemToPrint = "ironwood wood";
                }
                std::cout << it->second << " " << itemToPrint;
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
    // cout << listofResepBangunan.size() << endl;
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

void Walikota::pungutPajak(vector<Pemain *> listPemain)
{   
    // test print listpemain
    cout << listPemain.size() << endl;
    for (size_t i = 0; i < listPemain.size(); i++)
    {
        cout << listPemain.at(i)->getName() << endl;
    }

    std::cout << "Cring cring cring..." << endl;
    std::cout << "Pajak sudah dipungut!" << endl;
    std::cout << "Berikut adalah detil dari pemungutan pajak: " << endl;

    int number = 1;
    for (auto it = listPemain.begin(); it != listPemain.end(); ++it)
    {
        Pemain *player = *it;

        if (player->getTipePemain() == "Walikota")
            continue;

        int pajak = 0;
        if (Petani *petani = dynamic_cast<Petani *>(player))
        {
            pajak = petani->HitungPajak();
        }
        else if (Peternak *peternak = dynamic_cast<Peternak *>(player))
        {
            pajak = peternak->HitungPajak();
        }

        if (pajak >= -99)
        {
            player->kurangiGulden(pajak);
            this->tambahkanGulden(pajak);

            std::cout << "    " << number << ". " << player->getName() << " - " << player->getTipePemain() << ": " << pajak << " gulden" << endl;
            number++;
        }
    }
}


string Walikota::getTipePemain()
{
    return "Walikota";
}

void Walikota::undo(Toko *toko, vector<Pemain *> daftarPemain)
{
    Memento *m = this->getActionHistory()->topMemento();
    this->tambahBeratBadan(m->getBeratBadanMemento() - this->getBeratBadan());
    cout << "Berat badan " << this->getName() << " berhasil dikembalikan: " << this->getBeratBadan() << endl;
    this->tambahkanGulden(m->getGuldenMemento() - this->getGulden());
    cout << "Gulden " << this->getName() << " berhasil dikembalikan:" << this->getGulden() << endl;
    undoToko(toko, m);
    cout << "Toko berhasil dikembalikan" << endl;
    m->deleteCreatedItems();
    m->undoInventory(this->getInventory());
    cout << "Inventory " << this->getName() << " berhasil dikembalikan" << endl;
    if (dynamic_cast<WalikotaMemento *>(m) != nullptr)
    {
        WalikotaMemento *wm = dynamic_cast<WalikotaMemento *>(m);
        int i;
        if (!wm->isMapPemainGuldenEmpty())
        {
            for (i = 0; i < daftarPemain.size(); i++)
            {
                if (dynamic_cast<Walikota *>(daftarPemain.at(i)) == nullptr)
                {
                    wm->undoGuldenPemain(daftarPemain.at(i));
                    cout << "Gulden " << daftarPemain.at(i)->getName() << " berhasil dikembalikan: " << daftarPemain.at(i)->getGulden() << endl;
                }
            }
        }
    }
    this->getActionHistory()->popMemento();
    cout << "Undo selesai" << endl;
}

void Walikota::undoDaftarPemain(vector<Pemain *> *daftarKeseluruhan, priority_queue<string, vector<string>, greater<string>> *prioQueue, WalikotaMemento *wm, map<string, Pemain *> *mapNamaPemain)
{
    priority_queue<string, vector<string>, greater<string>> temp;
    while (!prioQueue->empty())
    {
        temp.push(prioQueue->top());
        prioQueue->pop();
    }

    bool isDaftarPemainBerubah = false;
    while (!temp.empty())
    {
        if (temp.top() != wm->getCreatedPemain()->getName())
        {
            prioQueue->push(temp.top());
        }
        else
        {
            isDaftarPemainBerubah = true;
            cout << "Menghapus pemain " << wm->getCreatedPemain()->getName() << endl;
            // wm->deleteCreatedPemain();
        }
        temp.pop();
    }

    if (isDaftarPemainBerubah)
    {
        vector<Pemain *> tempDaftarPemain;
        while (!daftarKeseluruhan->empty())
        {
            tempDaftarPemain.push_back(daftarKeseluruhan->at(daftarKeseluruhan->size() - 1));
            daftarKeseluruhan->pop_back();
        }
        while (!tempDaftarPemain.empty())
        {
            if (tempDaftarPemain.at(tempDaftarPemain.size() - 1)->getName() != wm->getCreatedPemain()->getName())
            {
                daftarKeseluruhan->push_back(tempDaftarPemain.at(tempDaftarPemain.size() - 1));
            }
            tempDaftarPemain.pop_back();
        }
        mapNamaPemain->erase(wm->getCreatedPemain()->getName());
        wm->deleteCreatedPemain();
    }

    cout << "Daftar pemain berhasil dikembalikan" << endl;
}

bool Walikota::isNamaSudahAda(const std::vector<Pemain *> &daftarPemain, const std::string &nama)
{
    for (auto it = daftarPemain.begin(); it != daftarPemain.end(); ++it)
    {
        if ((*it)->getName() == nama)
        {
            return true;
        }
    }
    return false;
}
