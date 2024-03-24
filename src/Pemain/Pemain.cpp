#include "Pemain.hpp"

Pemain::Pemain(string name, int row, int col) : name(name), beratBadan(0), gulden(0)
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

float Pemain::getGulden()
{
    return gulden;
}

string Pemain::getName()
{
    return name;
}
