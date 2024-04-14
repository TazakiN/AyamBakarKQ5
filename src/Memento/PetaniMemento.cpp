#include "PetaniMemento.hpp"

using namespace std;

PetaniMemento::PetaniMemento(Inventory& pemain_inventory, int pemain_bb, int pemain_gulden, Toko& toko, Ladang& pemainLadang) : Memento(pemain_inventory, pemain_bb, pemain_gulden, toko){
    // CCTOR LADANG
    // this->ladang = new Ladang(pemainLadang);
};

PetaniMemento::~PetaniMemento(){
    delete ladang;
};

void PetaniMemento::undoLadang(Ladang* pemainLadang){
    int i;
    int j;
    for(i=0;i<this->ladang->getRow();i++){
        for(j=0;j<this->ladang->getCol();j++){
            pemainLadang->setItem(i,j,this->ladang->getItem(i,j));
        }
    }
};

