#include "PeternakMemento.hpp"

using namespace std;

PeternakMemento::PeternakMemento(Inventory& pemain_inventory, int pemain_bb, int pemain_gulden, Toko& toko, Peternakan& pemainPeternakan) : Memento(pemain_inventory, pemain_bb, pemain_gulden, toko){
    // CCTOR Peternakan
    // this->peternakan = new Peternakan(pemainPeternakan);
};

PeternakMemento::~PeternakMemento(){
    delete peternakan;
};

void PeternakMemento::undoPeternakan(Peternakan* pemainPeternakan){
    int i;
    int j;
    for(i=0;i<this->peternakan->getRow();i++){
        for(j=0;j<this->peternakan->getCol();j++){
            pemainPeternakan->setItem(i,j,this->peternakan->getItem(i,j));
        }
    }
};