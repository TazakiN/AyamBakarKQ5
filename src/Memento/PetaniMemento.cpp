#include "PetaniMemento.hpp"

using namespace std;

PetaniMemento::PetaniMemento(Ladang& pemainLadang){
    this->ladang = new Ladang(pemainLadang);
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

