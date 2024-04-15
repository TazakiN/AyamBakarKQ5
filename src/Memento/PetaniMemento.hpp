#ifndef PETANIMEMENTO_HPP
#define PETANIMEMENTO_HPP

#include "../Grid/Ladang.hpp"
#include "Memento.hpp"

using namespace std;

class PetaniMemento : public Memento{
    private:
        Ladang* ladang;

    public:
        /**
         * @brief Konstruktor
         * 
         * @param pemainLadang  Keadaan ladang petani sebelum melakukan suatu action
         */
        PetaniMemento(Inventory& pemain_inventory, int pemain_bb, int pemain_gulden, Toko& toko, Ladang& pemainLadang);


        /**
         * @brief Destruktor
         * 
         */
        virtual ~PetaniMemento();
        
        /**
         * @brief Mengembalikan keadaan ladang pemain menjadi keadaan ladang pada memento
         * 
         * @param pemainLadang  Ladang pemain saat ini
         */
        void undoLadang(Ladang* pemainLadang);
};

#endif