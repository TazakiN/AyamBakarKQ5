#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "../Pemain/Pemain.hpp"
#include "Petani.hpp"
#include "Peternak.hpp"
#include "../Exception/Exception.hpp"
#include "../Item/Bangunan.hpp"
#include <list>
#include <string>
#include <queue>

class Walikota : public Pemain
{
private:
    vector<vector<string>> listofResepBangunan;

public:
    /**
     * @brief Konstruktor walikota dengan nama tertentu.
     *
     * @param name nama pemain
     * @param row banyak baris Inventory pemain
     * @param col banyak kolom Inventory pemain
     */
    Walikota(std::string name, int row, int col);

    /**
     * Destruktor walikota
     */
    ~Walikota();

    /**
     * Membangun bangunan
     *
     * @param jenis_bangunan yang ingin dibangun
     */
    void bangun(string jenis_bangunan);

    /**
     * Memungut pajak dari tiap proletar
     */
    void pungutPajak(priority_queue<Pemain *> listPemain);

    float HitungPajak() override;

    void addResep(std::vector<string> &resep);

    list<int> getListIdxBahanBangunan(std::string item);
};

#endif