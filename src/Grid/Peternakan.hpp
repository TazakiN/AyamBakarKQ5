#ifndef PETERNAKAN_HPP
#define PETERNAKAN_HPP

#include "Lahan.hpp"
#include "../Item/Hewan.hpp"
#include "../utils/pcolor.hpp"

class Peternakan : public Lahan<Hewan>
{
private:
    /* data */
public:
    /**
     * Konstruktor kelas Peternakan
     *
     * @param row jumlah baris dari Peternakan
     * @param col jumlah kolom dari Peternakan
     */
    Peternakan(int row, int col);

    /**
     * Destruktor kelas Peternakan
     */
    virtual ~Peternakan();

    /**
     * Mencetak peternakan
     */
    void printPeternakan();
};

#endif