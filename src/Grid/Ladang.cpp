#include "Ladang.hpp"

Ladang::Ladang(int row, int col) : Lahan(row, col)
{
}

Ladang::~Ladang()
{
}

void Ladang::printLadangWithHeader()
{
    Ladang::printGridHeader();
    Lahan::printLahan();
}

void Ladang::printGridHeader()
{
    cout << "    ==================[ Ladang ]==================" << endl;
}