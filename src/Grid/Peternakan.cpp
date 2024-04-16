#include "Peternakan.hpp"

Peternakan::Peternakan(int row, int col) : Lahan<Hewan>(row, col)
{
}

Peternakan::~Peternakan()
{
}

void Peternakan::printPeternakan()
{
    Grid::printGridHeader("Peternakan");
    Lahan<Hewan>::printLahan();
}