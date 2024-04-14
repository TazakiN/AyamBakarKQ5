#include "Makhluk.hpp"

Makhluk::Makhluk(string nama, string kode_huruf, string tipe, int harga, int progressPanen, int targetPanen) : Item(nama, kode_huruf, harga)
{
    this->tipe = tipe;
    this->progressPanen = progressPanen;
    this->targetPanen = targetPanen;
}

Makhluk::Makhluk(const Makhluk &other) : Item(other.getName(), other.getKode(), other.getHarga())
{
    this->tipe = other.tipe;
    this->progressPanen = other.progressPanen;
    this->targetPanen = other.targetPanen;
}

Makhluk::~Makhluk()
{
}

string Makhluk::getTipe() const
{
    return this->tipe;
}

int Makhluk::getProgressPanen() const
{
    return this->progressPanen;
}

void Makhluk::setProgressPanen(int progressPanen)
{
    this->progressPanen = progressPanen;
}

int Makhluk::getTargetPanen() const
{
    return this->targetPanen;
}

bool Makhluk::siapPanen()
{
    return this->progressPanen >= this->targetPanen;
}
