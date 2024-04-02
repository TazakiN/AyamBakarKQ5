#include "Inventory.hpp"

Inventory::Inventory(int row, int col) : Grid<Item>(row, col)
{
}

Inventory::~Inventory()
{
}

void Inventory::printGridHeader()
{
    cout << " ================[ Penyimpanan ]==================" << endl;
}
