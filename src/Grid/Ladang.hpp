#ifndef LADANG_HPP
#define LADANG_HPP

#include "Lahan.hpp"
#include "../Item/Tanaman.hpp"
#include "../utils/pcolor.hpp"

class Ladang : public Lahan<Tanaman>
{
private:
    /* data */
public:
    /**
     * Konstruktor kelas Ladang
     *
     * @param row jumlah baris dari ladang
     * @param col jumlah kolom dari ladang
     */
    Ladang(int row, int col);

    /**
     * Destruktor kelas Ladang
     */
    virtual ~Ladang();

    /**
     * Mencetak ladang
     */
    void printLadangWithHeader();

    /**
     * Mencetak header ladang
     */
    void printGridHeader();
};

#endif