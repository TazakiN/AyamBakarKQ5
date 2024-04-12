#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Proletar.hpp"
#include "../Grid/Peternakan.hpp"
#include "../utils/pcolor.hpp"

class Peternak : public Proletar
{
private:
    Peternakan *peternakan;

public:
    /**
     * @brief Konstruktor peternak dengan nama tertentu.
     *
     * @param petak pointer ke grid petak
     * @param name nama peternak
     * @param row banyak baris Inventory peternak
     * @param col banyak kolom Inventory peternak
     */
    Peternak(string name, int row, int col);

    /**
     * Destruktor peternak
     */
    ~Peternak();

    /**
     * Memberi makan ternak
     *
     * @param row lokasi ternak yang ingin diberi makan
     * @param col lokasi ternak yang ingin diberi makan
     */
    void kasih_makan(int row, int col);

    /**
     * Menambahkan ternak ke ladang
     */
    void ternak();

    /**
     * Menampilkan peternakan milik peternak
     */
    void CetakPetak();

    /**
     * Melakukan panen pada peternakan milik peternak
     */
    void Panen();

    /**
     * Mengembalikan jumlah pajak yang dimiliki peternak
     *
     * @return jumlah pajak peternak
     */
    float HitungPajak();

    /**
     * Mengembalikan jumlah aset yang dimiliki peternak
     *
     * @return jumlah kekayaan peternak
     */
    float hitungKekayaan();

    /**
     * Menambahkan makhluk ke lahan
     *
     * @param makhluk makhluk yang ingin dimasukkan ke peternakan
     * @param posisi posisi makhluk yang ingin dimasukkan
     */
    void masukanHewanKePeternakan(Hewan *hewan, string position);
};

#endif