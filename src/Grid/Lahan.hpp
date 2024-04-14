#ifndef LAHAN_HPP
#define LAHAN_HPP

#include "Grid.hpp"
#include "../Item/Makhluk.hpp"

template <typename T>
class Lahan : public Grid<T>
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

    /**
     * Mengembalikan stringstream dari Lahan sesuai format file state
     * @return stringstream dari Lahan yang berisi informasi Lahan
     */
    stringstream getStringStreamOfLahan();
};
;

#endif