#include "Makhluk.hpp"

class Tanaman : public Makhluk
{
private:
    int umur;

public:
    /**
     * @brief Konstruktor tanaman
     *
     * @param nama nama tanaman
     * @param kode_huruf tanaman 
     */
    Tanaman(string nama, string kode_huruf);

    /**
     * Destruktor makhluk
     */
    virtual ~Tanaman();
    bool siapPanen();
    int getUmur();
};