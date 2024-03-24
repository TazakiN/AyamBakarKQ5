#include "Grid.hpp"

class Inventory : public Grid<Item>
{
private:
    /* data */
public:
    Inventory(int row, int col);
    ~Inventory();
};