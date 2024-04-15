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
     * @brief Konstruktor walikota dengan nama tertentu
     *
     * @param nama pemain
     * @param banyak baris Inventory pemain
     * @param banyak kolom Inventory pemain
     */
    Walikota(std::string name, int row, int col);

    /**
     * @brief Destruktor walikota
     */
    ~Walikota();

    /**
     * @brief Membangun bangunan dengan syarat bahan bangunan mencukupi dan masih ada inventory kosong, jika berhasil bangunan akan disimpan dalam inventory
     *
     * @param jenis bangunan yang ingin dibangun
     */
    void bangun();

    /**
     * @brief Memungut pajak dari tiap proletar, hasil pemungutan pajak akan diterima oleh walikota
     * 
     * @param list pemain
     */
    void pungutPajak(priority_queue<Pemain *> listPemain);

    /**
     * @brief Mengembalikan nilai nol
     * 
     * @return 0
     */
    float HitungPajak() override;

    /**
     * @brief Menambahkan resep
     * 
     * @param resep berupa vector of string
     */
    void addResep(std::vector<string> &resep);

    /**
     * @brief Mengembalikan indeks bahan bangunan yang dicari
     * 
     * @param item yang dicari
     * 
     * @return list indeks bahan bangunan dalam inentory dengan format row-1, col-1, row-2, col-2, ... ,row-n, col-n
     */
    list<int> getListIdxBahanBangunan(std::string item);

    void printResep();

    string getTipePemain() override;
};

#endif