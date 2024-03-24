#include "../Grid/Inventory.hpp"

class Pemain
{
private:
    Inventory *inventory;
    float beratBadan;
    float gulden;
    string name;

public:
    /**
     * @brief Konstruktor pemain dengan nama tertentu.
     *
     * @param name nama pemain
     * @param row banyak baris Inventory pemain
     * @param col banyak kolom Inventory pemain
     */
    Pemain(string name, int row, int col);

    /**
     * Destruktor pemain
     */
    ~Pemain();

    /**
     * Mengembalikan besar berat badan pemain
     *
     * @return berat badan pemain
     */
    float getBeratBadan();

    /**
     * Mengembalikan jumlah gulden pemain
     *
     * @return jumlah gulden pemain
     */
    float getGulden();

    /**
     * Mengembalikan nama pemain
     *
     * @return nama pemain
     */
    string getName();
};
