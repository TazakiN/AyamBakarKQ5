#include "Proletar.hpp"

class Petani : public Proletar
{
public:
    /**
     * @brief Konstruktor petani dengan nama tertentu.
     *
     * @param petak pointer ke grid petak
     * @param name nama petani
     * @param row banyak baris Inventory petani
     * @param col banyak kolom Inventory petani
     */
    Petani(Grid<Inventory> *petak, string name, int row, int col);

    /**
     * Destruktor petani
     */
    ~Petani();

    /**
     * Menampilkan ladang milik petani
     */
    virtual void CetakPetak() override;

    /**
     * Mengembalikan jumlah pajak yang dimiliki petani
     *
     * @return jumlah pajak petani
     */
    virtual float hitungPajak() override;

    /**
     * Melakukan panen pada ladang milik petani
     */
    virtual void Panen() override;
};