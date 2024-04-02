#include "Proletar.hpp"
#include "Tanaman.hpp"

class Petani : public Proletar
{
private:
    Grid<Inventory> *ladang;
    /**
     * Mengembalikan jumlah aset yang dimiliki proletar
     *
     * @return jumlah kekayaan proletar
     */
    virtual float hitungKekayaan() = 0;

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
     * Menanam tanaman
     *
     * @param objek tanaman
     * @param nama tanaman
     * @param row 
     * @param col
     */
    void tanam(Tanaman& nama_tanaman, int row, int col);
};
