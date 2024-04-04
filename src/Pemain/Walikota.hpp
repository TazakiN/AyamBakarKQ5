#include "../Pemain/Pemain.hpp"
#include <map>
#include <string>

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
    map<string, int> bahanBangunan;

public:
    /**
     * @brief Konstruktor walikota dengan nama tertentu.
     *
     * @param name nama pemain
     * @param row banyak baris Inventory pemain
     * @param col banyak kolom Inventory pemain
     */
    Walikota(string name, int row, int col);

    /**
     * Destruktor walikota
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
    // void tambahPemain(string nama_pemain, string peran_pemain);
};
