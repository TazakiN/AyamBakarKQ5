#include "Proletar.hpp"

class Peternak : public Proletar
{
private:
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
     * Memberi makan ternak
     *
     * @param row lokasi ternak yang ingin diberi makan
     * @param col lokasi ternak yang ingin diberi makan
     */
    void kasih_makan(int row, int col);

    /**
     * Menambahkan ternak ke ladang
     *
     * @param row lokasi ternak yang ingin ditambahkan
     * @param col lokasi ternak yang ingin ditambahkan
     */
    void ternak(int row, int col);

};
