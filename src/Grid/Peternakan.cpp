#include "Peternakan.hpp"

Peternakan::Peternakan(int row, int col) : Lahan(row, col)
{
}

Peternakan::~Peternakan()
{
}

void Peternakan::printPeternakan()
{
    Peternakan::printGridHeader();
    Lahan::printLahan();
}

void Peternakan::printGridHeader()
{
    cout << "    ==================[ Peternakan ]==================" << endl;
}