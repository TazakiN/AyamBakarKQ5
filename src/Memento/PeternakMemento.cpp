#include "PeternakMemento.hpp"

using namespace std;

PeternakMemento::PeternakMemento(Peternakan& pemainPeternakan){
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