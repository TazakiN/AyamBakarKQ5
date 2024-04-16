#include "PeternakMemento.hpp"

using namespace std;

PeternakMemento::PeternakMemento(Inventory &pemain_inventory, int pemain_bb, int pemain_gulden, Toko &toko, Peternakan &pemainPeternakan) : Memento(pemain_inventory, pemain_bb, pemain_gulden, &toko)
{
    int i;
    int j;
    this->peternakan = new Peternakan(pemainPeternakan.getRow(), pemainPeternakan.getRow());
    for (i = 0; i < this->peternakan->getRow(); i++)
    {
        for (j = 0; j < this->peternakan->getCol(); j++)
        {
            this->peternakan->setItem(i, j, pemainPeternakan.getItem(i, j));
            if (pemainPeternakan.getItem(i, j) != nullptr){
                mapHewanProgresPanen[pemainPeternakan.getItem(i, j)] = pemainPeternakan.getItem(i, j)->getProgressPanen();
            }

        }
    }
};

PeternakMemento::~PeternakMemento()
{
    mapHewanProgresPanen.clear();
    delete peternakan;
};

void PeternakMemento::undoPeternakan(Peternakan *pemainPeternakan)
{
    int i;
    int j;
    for (i = 0; i < this->peternakan->getRow(); i++)
    {
        for (j = 0; j < this->peternakan->getCol(); j++)
        {
            if (this->peternakan->getItem(i, j) != nullptr){
                this->peternakan->getItem(i, j)->setProgressPanen(mapHewanProgresPanen[this->peternakan->getItem(i, j)]);
            }
            pemainPeternakan->setItem(i, j, this->peternakan->getItem(i, j));
        }
    }
};

void PeternakMemento::insertHewanProgresPanen(Hewan* h, int progresPanen){
    mapHewanProgresPanen[h] = progresPanen; 
};