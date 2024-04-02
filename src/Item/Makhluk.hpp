#include "Item.hpp"

class Makhluk : public Item 
{
protected:
    int pertambahanBerat;
    int harga;

public:
    /**
     * @brief Konstruktor makhluk
     *
     * @param nama nama makhluk
     * @param kode_huruf
     * @param pertambahanBerat
     */
    Makhluk(string nama, string kode_huruf, int pertambahanBerat, int harga);

    /**
     * Destruktor makhluk
     */
    virtual ~Makhluk();

    /**
     * @return boolean apakah makhluk siap dipanen (true) atau belum (false)
     */
    virtual bool siapPanen() = 0;
    

    // /**
    //  * @return kebutuhan makhluk
    // */
    // int getNeeds();

    /**
     * @return harga makhluk
    */
    int getHarga();

    /**
     * @return pertambahan berat makhluk
     */
    int getPertambahanBerat();
};