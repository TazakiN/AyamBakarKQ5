#include "Ladang.hpp"

Ladang::Ladang(int row, int col) : Lahan<Tanaman>(row, col)
{
}

Ladang::~Ladang()
{
}

void Ladang::printLadangWithHeader()
{
    Grid::printGridHeader("Ladang");
    Lahan<Tanaman>::printLahan();
}