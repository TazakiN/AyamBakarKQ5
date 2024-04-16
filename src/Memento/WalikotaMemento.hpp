#ifndef WALIKOTAMEMENTO_HPP
#define WALIKOTAMEMENTO_HPP

#include "Memento.hpp"
#include "../Pemain/Pemain.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class WalikotaMemento : public Memento{
    private:
        map<string, int> map_pemain_gulden;
        Pemain* created_pemain;

    public:
        WalikotaMemento(Inventory& pemain_inventory, int pemain_bb, int pemain_gulden, Toko& toko);

        virtual ~WalikotaMemento();

        Pemain* getCreatedPemain() const;

        bool isMapPemainGuldenEmpty();

        /**
         * @brief Menambahkan keadaan pasangan pemain-gulden 
         * sebelum walikota melakukan suatu action ke map_pemain_gulden
         * 
         * @param pemain 
         * @param gulden 
         */
        void insertPemainGulden(vector<Pemain*>daftarPemain);

        /**
         * @brief Menambahkan pemain yang dibuat jika walikota melakukan aksi tambah pemain
         * 
         * @param p     pointer of pemain yang baru dibuat
         */
        void insertCreatedPemain(Pemain* p);

        void deleteCreatedPemain();

        void undoGuldenPemain(Pemain* p);
};

#endif