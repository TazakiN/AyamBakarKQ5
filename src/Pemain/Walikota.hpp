#include "../Pemain/Pemain.hpp"

class Walikota : public Pemain
{
private:
    /*
    listOfResepBangunan dan bahanBangunan:
    Row:    1. SMALL_HOUSE
            2. MEDIUM_HOUSE
            3. LARGE_HOUSE
            4. HOTEL
    Column: 1. TEAK_WOOD
            2. ALOE_WOOD
            3. IRONWOOD_WOOD
            4. SANDAL_WOOD
    */
    static int listOfResepBangunan[4][4]; // <-- Dihapus karena ternyata keknya enakan bikin ini sekalian di gameEngine
    int bahanBangunan[4][4];

public:
    /**
     * @brief Konstruktor pemain dengan nama tertentu.
     *
     * @param name nama pemain
     * @param row banyak baris Inventory pemain
     * @param col banyak kolom Inventory pemain
     */
    Walikota(string name, int row, int col);

    /**
     * Destruktor pemain
     */
    ~Walikota();

    /**
     * Membangun bangunan
     *
     * @param jenis_bangunan yang ingin dibangun
     */
    void bangun(string jenis_bangunan);

    /**
     * Memungut pajak dari tiap proletar
     */
    void pungutPajak();

    /**
     * Membangun bangunan
     *
     * @param nama_pemain yang ingin ditambahkan
     * @param peran yang ingin ditambahkan
     */
    void tambahPemain(string nama_pemain, string peran_pemain);
};
