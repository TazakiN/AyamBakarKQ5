#include "WalikotaMemento.hpp"

using namespace std;

WalikotaMemento::WalikotaMemento(Inventory& pemain_inventory, int pemain_bb, int pemain_gulden, Toko& toko) : Memento(pemain_inventory, pemain_bb, pemain_gulden, toko){

};

WalikotaMemento::~WalikotaMemento(){
    // this->map_pemain_gulden.clear();
};

void WalikotaMemento::insertPemainGulden(string pemain, int gulden){
    this->map_pemain_gulden.insert(pair<string,int>(pemain,gulden));
};

void WalikotaMemento::insertCreatedPemain(Pemain* p){
    this->created_pemain.push_back(p);
}

void WalikotaMemento::deleteCreatedPemain(){
    while (!this->created_pemain.empty())
    {
        delete this->created_pemain.at(this->created_pemain.size()-1);
        this->created_pemain.pop_back();
    }
}

void WalikotaMemento::undoGuldenPemain(Pemain* p){
    p->tambahkanGulden(this->map_pemain_gulden[p->getName()]-p->getGulden());
}