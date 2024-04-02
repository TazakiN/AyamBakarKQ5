// #include "Item.hpp"

class Makhluk : public Item 
{
private:

public:
    /**
     * @brief Konstruktor makhluk
     *
     * @param nama nama makhluk
     * @param kode_huruf
     */
    Makhluk(string nama, string kode_huruf);

    /**
     * Destruktor makhluk
     */
    virtual ~Makhluk();

    /**
     * @return boolean apakah makhluk siap dipanen (true) atau belum (false)
     */
    virtual bool siapPanen() = 0;
    
    int getNeeds();
    int getHarga();
};