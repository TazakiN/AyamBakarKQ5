#include "Inventory.hpp"

Inventory::Inventory(int row, int col) : Grid<Item>(row, col)
{
}

Inventory::~Inventory()
{
}

void Inventory::printInventory()
{
    Grid::printGridHeader("Penyimpanan");
    printGrid();
}

stringstream Inventory::getStringStreamOfInventory()
{
    stringstream output;

    for (int i = 0; i < getRow(); i++)
    {
        for (int j = 0; j < getCol(); j++)
        {
            Item *item = getItem(i, j);
            if (item != nullptr)
            {
                output << item->getName() << endl;
            }
        }
    }

    return output;
}
