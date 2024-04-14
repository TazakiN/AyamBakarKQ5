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

