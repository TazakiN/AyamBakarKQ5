#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "../Pemain/Pemain.hpp"
#include "Petani.hpp"
#include "Peternak.hpp"
#include "../Exception/Exception.hpp"
#include "../Item/Bangunan.hpp"
#include <map>
#include <string>

class Walikota : public Pemain
{
private:
    map<string, int> bahanBangunan;
    vector<vector<string>> listResepBangunan;

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
    void bangun(string jenis_bangunan, vector<vector<string>> listOfResepBangunan);

    /**
     * Memungut pajak dari tiap proletar
     */
    void pungutPajak(vector<Pemain *> listPemain, int currPemain);

    float HitungPajak() override;

    void addResep(std::vector<string>& resep);

    void addBahanBangunan(string bahan, int jumlah);

    int countBahanBangunan (const Item& item);
};

#endif