#ifndef LADANG_HPP
#define LADANG_HPP

#include "Grid.hpp"
#include "../Item/Tanaman.hpp"
#include "../utils/pcolor.hpp"

class Ladang : public Grid<Tanaman>
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
    void printLadang();

    /**
     * Mencetak header ladang
     */
    void printGridHeader();
};


#endif