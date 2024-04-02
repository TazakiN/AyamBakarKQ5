#include "Proletar.hpp"
// #include "../Item/Tanaman.hpp"

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
     * Menanam tanaman
     *
     * @param objek tanaman
     * @param nama tanaman
     * @param row 
     * @param col
     */
    // void tanam(Tanaman& nama_tanaman, int row, int col);

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
};
