#include "Makhluk.hpp"

Makhluk::Makhluk(string nama, string kode_huruf, string tipe, int harga, int progressPanen, int targetPanen) : Item(nama, kode_huruf, harga)
{
    this->tipe = tipe;
    this->progressPanen = progressPanen;
    this->targetPanen = targetPanen;
}

Makhluk::~Makhluk()
{
}

string Makhluk::getTipe()
{
    return this->tipe;
}

int Makhluk::getProgressPanen()
{
    return this->progressPanen;
}

void Makhluk::setProgressPanen(int progressPanen)
{
    this->progressPanen = progressPanen;
}

int Makhluk::getTargetPanen()
{
    return this->targetPanen;
}
