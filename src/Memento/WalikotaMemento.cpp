#include "WalikotaMemento.hpp"

using namespace std;

WalikotaMemento::WalikotaMemento(Inventory &pemain_inventory, int pemain_bb, int pemain_gulden, Toko &toko) : Memento(pemain_inventory, pemain_bb, pemain_gulden, &toko){

};

WalikotaMemento::~WalikotaMemento(){
    // this->map_pemain_gulden.clear();
};

Pemain* WalikotaMemento::getCreatedPemain()const{
    return this->created_pemain;
}

void WalikotaMemento::insertPemainGulden(vector<Pemain*>daftarPemain)
{
    int i;
    for(i=0;i<daftarPemain.size();i++){
        this->map_pemain_gulden.insert(pair<string, int>(daftarPemain.at(i)->getName(), daftarPemain.at(i)->getGulden()));
    }
};

void WalikotaMemento::insertCreatedPemain(Pemain *p)
{
    this->created_pemain = p;
}

void WalikotaMemento::deleteCreatedPemain()
{
    delete this->created_pemain;
}

void WalikotaMemento::undoGuldenPemain(Pemain *p)
{
    p->tambahkanGulden(this->map_pemain_gulden[p->getName()] - p->getGulden());
}