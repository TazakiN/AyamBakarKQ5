#ifndef LAHAN_HPP
#define LAHAN_HPP

#include "Grid.hpp"
#include "../Item/Makhluk.hpp"

class Lahan : public Grid<Makhluk>
{
private:
    /* data */
public:
    /**
     * Konstruktor kelas Lahan
     *
     * @param row jumlah baris dari Lahan
     * @param col jumlah kolom dari Lahan
     */
    Lahan(int row, int col);

    /**
     * Destruktor kelas Lahan
     */
    virtual ~Lahan();

    /**
     * Mencetak Lahan
     */
    void printLahan();

    /**
     * Mencetak header Lahan
     */
    void printGridHeader() = 0;
};

#endif