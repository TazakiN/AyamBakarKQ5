#include "Pemain.hpp"

Pemain::Pemain(string name, int row, int col) : beratBadan(0), gulden(0), name(name)
{
    inventory = new Inventory(row, col);
}

Pemain::~Pemain()
{
    delete inventory;
}

float Pemain::getBeratBadan()
{
    return beratBadan;
}

void Pemain::tambahBeratBadan(float bb)
{
    this->beratBadan += bb;
}

float Pemain::getGulden()
{
    return gulden;
}

void Pemain::tambahGulden(float g)
{
    this->gulden += g;
}

void Pemain::kurangGulden(float g)
{
    this->gulden -= g;
}

string Pemain::getName()
{
    return name;
}
