#include "Pemain.hpp"

Pemain::Pemain(string name, int row, int col) : berat_badan(0), gulden(0), nama(name)
{
    inventory = new Inventory(row, col);
}

Pemain::~Pemain()
{
    delete inventory;
}

float Pemain::getBeratBadan()
{
    return berat_badan;
}

void Pemain::tambahBeratBadan(float bb)
{
    this->berat_badan += bb;
}

float Pemain::getGulden()
{
    return gulden;
}

void Pemain::tambahkanGulden(float g)
{
    this->gulden += g;
}

void Pemain::kurangiGulden(float g)
{
    this->gulden -= g;
}

string Pemain::getName()
{
    return nama;
}

void Pemain::beli(string nama_item, int kuantitas, int idx_row, int idx_col) 
{
    // nanti
}

void Pemain::jual(string nama_item, int kuantitas, int idx_row, int idx_col)
{
    // nanti
}

void Pemain::makan(int bb) {
    // nanti
}