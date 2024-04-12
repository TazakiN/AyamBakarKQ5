#include "Ladang.hpp"

Ladang::Ladang(int row, int col) : Lahan<Tanaman>(row, col)
{
}

Ladang::~Ladang()
{
}

void Ladang::printLadangWithHeader()
{
    Ladang::printGridHeader();
    Lahan<Tanaman>::printLahan();
}

void Ladang::printGridHeader()
{
    cout << "    ==================[ Ladang ]==================" << endl;
}