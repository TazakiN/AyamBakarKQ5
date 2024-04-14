#ifndef MAKHLUK_HPP
#define MAKHLUK_HPP

#include "Item.hpp"
#include "Produk.hpp"
#include <vector>
// #include "../GameEngine/GameEngine.hpp"

class Makhluk : public Item
{
protected:
    string tipe;
    int progressPanen;
    int targetPanen;

public:
    /**
     * @brief Konstruktor makhluk
     *
     * @param nama nama makhluk
     * @param kode_huruf
     * @param tipe tipe makhluk
     * @param harga harga makhluk
     * @param progressPanen progress panen makhluk
     * @param targetPanen target panen makhluk
     */
    Makhluk(string nama, string kode_huruf, string tipe, int harga, int progressPanen, int targetPanen);

    /**
     * Copy-construktor makhluk
     */
    Makhluk(const Makhluk &other);

    /**
     * Destruktor makhluk
     */
    virtual ~Makhluk();

    // /**
    //  * @return kebutuhan makhluk
    // */
    // int getNeeds();

    /**
     * @return tipe makhluk
     */
    string getTipe() const;

    /**
     * @return progress panen makhluk
     */
    int getProgressPanen() const;

    /**
     * Set progress panen makhluk
     */
    void setProgressPanen(int progressPanen);

    /**
     * @return target panen makhluk
     */
    int getTargetPanen() const;

    /**
     *  Mengembalikan progress panen makhluk
     */
    bool siapPanen();

    /**
     * @return Produk yang dihasilkan makhluk dari panen
     */
    virtual vector<Produk *> konversiPanen() = 0;
};

#endif