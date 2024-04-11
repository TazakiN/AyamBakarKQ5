#include "Memento.hpp"

Memento::Memento(Inventory& pemain_inventory, int pemain_bb, int pemain_gulden, Toko& toko){
    // CCTOR INVENTORY
    this->inventory = new Inventory(pemain_inventory);
    this->berat_badan = pemain_bb;
    this->gulden = pemain_gulden;
    // CCTOR TOKO
    // this->toko = new Toko(toko);
};

Memento::~Memento(){
    delete this->inventory;
    delete this->toko;
};

void Memento::insertCreatedItem(Item* item){
    created_items.push_back(item);
}

void Memento::undoInventory(Inventory* pemain_inventory){
    int i;
    int j;
    for(i=0;i<this->inventory->getRow();i++){
        for(j=0;j<this->inventory->getCol();j++){
            pemain_inventory->setItem(i,j,this->inventory->getItem(i,j));
        }
    }
}

int Memento::getBeratBadanMemento(){
    return this->berat_badan;
}

int Memento::getGuldenMemento(){
    return this->gulden;
}

// TO DO:
// void Memento::undoToko(Toko* toko){
    
// }

void Memento::deleteCreatedItems(){
    while(!this->created_items.empty()){
        delete this->created_items.at(this->created_items.size()-1);
        this->created_items.pop_back();
    }
}
