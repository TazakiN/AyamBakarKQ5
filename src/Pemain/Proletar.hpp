#ifndef PROLETAR_HPP
#define PROLETAR_HPP

#include "../Pemain/Pemain.hpp"

class Proletar : public Pemain
{
public:
    /**
     * @brief Konstruktor pemain dengan nama tertentu.
     *
     * @param petak pointer ke grid petak
     * @param name nama pemain
     * @param row banyak baris Inventory pemain
     * @param col banyak kolom Inventory pemain
     */
    Proletar(string name, int row, int col);

    /**
     * Destruktor pemain
     */
    virtual ~Proletar();

    /**
     * Menampilkan ladang dan peternakan milik proletar
     */
    virtual void CetakPetak() = 0;

    /**
     * Melakukan panen pada ladang dan peternakan milik proletar
     */
    virtual void Panen() = 0;

    /**
     * Mengembalikan jumlah pajak yang dimiliki proletar
     *
     * @return jumlah pajak proletar
     */
    virtual float HitungPajak() = 0;

    /**
     * Mengembalikan jumlah aset yang dimiliki proletar
     *
     * @return jumlah kekayaan proletar
     */
    virtual float hitungKekayaan() = 0;

    virtual string getTipePemain() = 0;
};

#endif