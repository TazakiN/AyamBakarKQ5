#include "../Pemain/Pemain.hpp"
#include "../Grid/Inventory.hpp"
#include "../Grid/Grid.hpp"

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
    static int listOfResepBangunan[4][4];
    int bahanBangunan[4][4];

public:
    // Konstruktor
    Walikota(string nama, Grid<Inventory> *inventory, int col, int row);

    // Destruktor
    ~Walikota();

    /*
        Membangun bangunan
        Jenis bangunan: 1. SMALL_HOUSE
                        2. MEDIUM_HOUSE
                        3. LARGE_HOUSE
                        4. HOTEL 
        Hanya dapat membangun bangunan jika bahan bangunan mencukupi DAN inventory masih ada yang kosong 
    */
    void bangunBangunan(int jenisBangunan);

    // Menagih pajak kepada proletar
    void tagihPajak();

    // Menambah 1 pemain (petani atau peternak) dengan uang bawaan 50 gulden
    // Uang walikota berkurang 50 gulden 
    void tambahProletar(string namaPemain, int jenisPemain);
};
