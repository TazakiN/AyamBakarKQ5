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
     * Menambah besar berat badan pemain
     *
     * @param bb pertambahan berat badan pemain
     */
    void tambahBeratBadan(float bb);

    /**
     * Mengembalikan jumlah gulden pemain
     *
     * @return jumlah gulden pemain
     */
    float getGulden();

    /**
     * Menambah jumlah gulden pemain
     *
     * @param g jumlah gulden yang ditambah
     */
    void tambahGulden(float g);

    /**
     * Mengurangi jumlah gulden pemain
     *
     * @param g jumlah gulden yang dikurang
     */
    void kurangGulden(float g);

    /**
     * Mengembalikan nama pemain
     *
     * @return nama pemain
     */
    string getName();
};
