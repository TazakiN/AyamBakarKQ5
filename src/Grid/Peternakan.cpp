#include "Peternakan.hpp"

Peternakan::Peternakan(int row, int col) : Lahan<Hewan>(row, col)
{
}

Peternakan::~Peternakan()
{
}

void Peternakan::printPeternakan()
{
    Peternakan::printGridHeader();
    Lahan<Hewan>::printLahan();
}

void Peternakan::printGridHeader()
{
    cout << "    ==================[ Peternakan ]==================" << endl;
}