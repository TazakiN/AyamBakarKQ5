#include "Makhluk.hpp"

class Hewan : public Makhluk
{
private:
    int berat;

public:
    /**
     * @brief Konstruktor item 
     *
     * @param nama nama pemain
     * @param kode_huruf
     */
    Hewan(string nama, string kode_huruf);

    /**
     * Destruktor item
     */
    virtual ~Hewan();

    /**
     * Mengembalikan nama item
     *
     * @return nama item
     */
    string getBerat();

    /**
     * Mengembalikan nilai apakah 
     *
     * @return kode huruf item
     */
    bool siapPanen();

    /**
     * Hewan makan
     *
     * @return kode huruf item
     */
    virtual void makan() = 0;
};