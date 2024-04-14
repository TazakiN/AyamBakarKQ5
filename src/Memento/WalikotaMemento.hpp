#ifndef WALIKOTAMEMENTO_HPP
#define WALIKOTAMEMENTO_HPP

#include "Memento.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class WalikotaMemento : public Memento{
    private:
        map<string, int>map_pemain_gulden;

    public:
        WalikotaMemento(Inventory& pemain_inventory, int pemain_bb, int pemain_gulden, Toko& toko);

        ~WalikotaMemento();

        /**
         * @brief Menambahkan keadaan pasangan pemain-gulden 
         * sebelum walikota melakukan suatu action ke map_pemain_gulden
         * 
         * @param pemain 
         * @param gulden 
         */
        void insertPemainGulden(string pemain, int gulden);
};

#endif