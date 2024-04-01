#include "Proletar.hpp"

Proletar::Proletar(Grid<Inventory> *petak, string name, int row, int col) : Pemain(name, row, col)
{
    this->petak = petak;
}

Proletar::~Proletar()
{
    // delete petak; <-- kayanya error karena double deconstruct
}