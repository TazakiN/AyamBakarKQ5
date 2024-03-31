#include "Proletar.hpp"

class Peternak : public Proletar
{
public:
    /**
     * @brief Konstruktor peternak dengan nama tertentu.
     *
     * @param petak pointer ke grid petak
     * @param name nama peternak
     * @param row banyak baris Inventory peternak
     * @param col banyak kolom Inventory peternak
     */
    Peternak(Grid<Inventory> *petak, string name, int row, int col);

    /**
     * Destruktor peternak
     */
    ~Peternak();

    /**
     * Menampilkan peternakan milik peternak
     */
    virtual void CetakPetak() override;

    /**
     * Mengembalikan jumlah pajak yang dimiliki peternak
     *
     * @return jumlah pajak peternak
     */
    virtual float hitungPajak() override;

    /**
     * Melakukan panen pada peternakan milik peternak
     */
    virtual void Panen() override;
};
