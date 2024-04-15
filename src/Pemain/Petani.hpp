#ifndef PETANI_HPP
#define PETANI_HPP

#include "Proletar.hpp"
#include "../Grid/Ladang.hpp"

class Petani : public Proletar
{
private:
    Ladang *ladang;

public:
    /**
     * @brief Konstruktor petani dengan nama tertentu.
     *
     * @param name nama petani
     * @param row_inv jumlah baris inventory
     * @param col_inv jumlah kolom inventory
     * @param row_lad jumlah baris ladang
     * @param col_lad jumlah kolom ladang
     */
    Petani(string name, int row_inv, int col_inv, int row_lad, int col_lad);

    /**
     * Destruktor petani
     */
    ~Petani();

    /**
     * Menanam tanaman
     */
    void tanam();

    /**
     * Menambah durasi tanaman
     */
    void tambahDurasiTanamanDiLadang();

    /**
     * Menampilkan ladang milik petani
     */
    void CetakPetak();

    /**
     * Melakukan panen pada ladang milik petani
     */
    void Panen();

    /**
     * Mengembalikan jumlah pajak yang dimiliki petani
     *
     * @return jumlah pajak petani
     */
    float HitungPajak();

    /**
     * Mengembalikan jumlah aset yang dimiliki petani
     *
     * @return jumlah kekayaan petani
     */
    float hitungKekayaan();

    /**
     * Mengembalikan pointer ke ladang milik petani
     *
     * @return pointer ke ladang milik petani
     */
    Ladang *getLadang();

    /**
     * Memasukkan tanaman ke ladang
     *
     * @param tanaman tanaman yang ingin dimasukkan
     * @param posisi posisi tanaman di ladang
     */
    void masukanTanamanKeLadang(Tanaman *tanaman, string posisi);

    string getTipePemain() override;

    void undo(Toko* toko, vector<Pemain*>daftarPemain);
};

#endif