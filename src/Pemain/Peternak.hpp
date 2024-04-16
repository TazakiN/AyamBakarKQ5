#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "Proletar.hpp"
#include "../Grid/Peternakan.hpp"
#include "../utils/pcolor.hpp"
#include "../Memento/PeternakMemento.hpp"

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
     * @param row_inv jumlah baris inventory
     * @param col_inv jumlah kolom inventory
     * @param row_peternakan jumlah baris peternakan
     * @param col_peternakan jumlah kolom peternakan
     */
    Peternak(string name, int row_inv, int col_inv, int row_peternakan, int col_peternakan);

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
    void kasih_makan(int row, int col, PeternakMemento* pm);

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
    void Panen(PeternakMemento* pm);

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

    /**
     * Mengembalikan pointer ke peternakan milik peternak
     *
     * @return pointer ke peternakan milik peternak
     */
    Peternakan *getPeternakan();

    string getTipePemain() override;

    void undo(Toko* toko, vector<Pemain*>&daftarPemain);
};

#endif