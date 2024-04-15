#include "Memento.hpp"

Memento::Memento(Inventory &pemain_inventory, int pemain_bb, int pemain_gulden, Toko *tokoAwal)
{
    this->inventory = new Inventory(pemain_inventory.getRow(), pemain_inventory.getCol());
    int i;
    int j;
    for (i = 0; i < this->inventory->getRow(); i++)
    {
        for (j = 0; j < this->inventory->getCol(); j++)
        {
            this->inventory->setItem(i, j, pemain_inventory.getItem(i, j));
        }
    }
    this->berat_badan = pemain_bb;
    this->gulden = pemain_gulden;
    this->toko = new Toko();
    this->toko->copyToko(tokoAwal);
};

Memento::~Memento()
{
    delete this->inventory;
    delete this->toko;
};

void Memento::insertCreatedItem(Item *item)
{
    created_items.push_back(item);
}

void Memento::undoInventory(Inventory *pemain_inventory)
{
    int i;
    int j;
    for (i = 0; i < this->inventory->getRow(); i++)
    {
        for (j = 0; j < this->inventory->getCol(); j++)
        {
            pemain_inventory->setItem(i, j, this->inventory->getItem(i, j));
        }
    }
}

int Memento::getBeratBadanMemento()
{
    return this->berat_badan;
}

int Memento::getGuldenMemento()
{
    return this->gulden;
}

void undoToko(Toko *tokoGame, Memento *m)
{
    tokoGame->copyToko(m->toko);
}

void Memento::deleteCreatedItems()
{
    while (!this->created_items.empty())
    {
        delete this->created_items.at(this->created_items.size() - 1);
        this->created_items.pop_back();
    }
}

void Memento::deleteDeletedItems(){
    while(!this->deleted_items.empty()){
        delete this->deleted_items.at(this->created_items.size() - 1);
        this->deleted_items.pop_back();
    }
}