#include "../Grid/Inventory.hpp"
#include "../Pemain/Pemain.hpp"
#include "../Grid/Grid.hpp"

class Proletar : public Pemain
{
private:
    Grid<Inventory> *petak;

public:
    /**
     * @brief Konstruktor proletar dengan nama tertentu.
     *
     * @param name nama proletar
     * @param row banyak baris Inventory proletar
     * @param col banyak kolom Inventory proletar
     */
    Proletar(Grid<Inventory> *petak, string name, int row, int col);

    /**
     * Destruktor proletar
     */
    ~Proletar();

    /**
     * Menampilkan ladang dan peternakan milik proletar
     */
    virtual void CetakPetak() = 0;

    /**
     * Mengembalikan jumlah pajak yang dimiliki proletar
     *
     * @return jumlah pajak proletar
     */
    virtual float hitungPajak() = 0;

    /**
     * Melakukan panen pada ladang dan peternakan milik proletar
     */
    virtual void Panen() = 0;
};
