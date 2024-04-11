#include "WalikotaMemento.hpp"

using namespace std;

WalikotaMemento::WalikotaMemento(){

};

WalikotaMemento::~WalikotaMemento(){
    // this->map_pemain_gulden.clear();
};

void WalikotaMemento::insertPemainGulden(string pemain, int gulden){
    this->map_pemain_gulden.insert(pair<string,int>(pemain,gulden));
};

