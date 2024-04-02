#include "../Pemain/Pemain.hpp"

class Proletar : public Pemain
{
private:
    Grid<Inventory> *ladang;

protected:
    /**
     * Mengembalikan jumlah aset yang dimiliki proletar
     *
     * @return jumlah kekayaan proletar
     */
    float hitungKekayaan();
    
public:
    /**
     * @brief Konstruktor pemain dengan nama tertentu.
     *
     * @param petak pointer ke grid petak
     * @param name nama pemain
     * @param row banyak baris Inventory pemain
     * @param col banyak kolom Inventory pemain
     */
    Proletar(Grid<Inventory> *petak, string name, int row, int col);

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
};
