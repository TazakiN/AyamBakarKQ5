#include "PetaniMemento.hpp"

using namespace std;

PetaniMemento::PetaniMemento(Inventory &pemain_inventory, int pemain_bb, int pemain_gulden, Toko &toko, Ladang &pemainLadang) : Memento(pemain_inventory, pemain_bb, pemain_gulden, &toko)
{
    this->ladang = new Ladang(pemainLadang.getRow(), pemainLadang.getCol());
    int i;
    int j;
    for (i = 0; i < this->ladang->getRow(); i++)
    {
        for (j = 0; j < this->ladang->getCol(); j++)
        {
            this->ladang->setItem(i, j, pemainLadang.getItem(i, j));
        }
    }
};

PetaniMemento::~PetaniMemento()
{
    delete ladang;
};

void PetaniMemento::undoLadang(Ladang *pemainLadang)
{
    int i;
    int j;
    for (i = 0; i < this->ladang->getRow(); i++)
    {
        for (j = 0; j < this->ladang->getCol(); j++)
        {
            pemainLadang->setItem(i, j, this->ladang->getItem(i, j));
        }
    }
};
