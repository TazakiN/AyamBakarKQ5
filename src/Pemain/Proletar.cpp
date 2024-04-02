#include "Proletar.hpp"

Proletar::Proletar(Grid<Inventory> *petak, string name, int row, int col) : Pemain(name, row, col)
{
    this->ladang = ladang;
}

Proletar::~Proletar()
{
    // delete petak; <-- kayanya error karena double deconstruct
}

float Proletar::hitungKekayaan()
{
    // nanti
}