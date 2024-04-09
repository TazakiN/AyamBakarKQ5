#ifndef PETANIMEMENTO_HPP
#define PETANIMEMENTO_HPP

#include "../Grid/Ladang.hpp"

using namespace std;

class PetaniMemento{
    private:
        Ladang* ladang;

    public:
        /**
         * @brief Konstruktor
         * 
         * @param pemainLadang  Keadaan ladang petani sebelum melakukan suatu action
         */
        PetaniMemento(Ladang& pemainLadang);


        /**
         * @brief Destruktor
         * 
         */
        ~PetaniMemento();
        
        /**
         * @brief Mengembalikan keadaan ladang pemain menjadi keadaan ladang pada memento
         * 
         * @param pemainLadang  Ladang pemain saat ini
         */
        void undoLadang(Ladang* pemainLadang);
};

#endif