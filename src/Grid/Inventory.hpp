#include "Grid.hpp"

class Inventory : public Grid<Item>
{
private:
    /* data */
public:
    /**
     * Konstruktor kelas Inventory
     *
     * @param row jumlah baris dari Inventory
     * @param col jumlah kolom dari Inventory
     */
    Inventory(int row, int col);

    /**
     * Destruktor kelas Inventory
     */
    virtual ~Inventory();

    /**
     * Mencetak header Inventory
     */
    void printGridHeader();
};