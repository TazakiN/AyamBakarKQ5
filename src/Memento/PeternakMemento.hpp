#ifndef PETERNAKMEMENTO_HPP
#define PETERNAKMEMENTO_HPP

#include "../Grid/Peternakan.hpp"
#include "Memento.hpp"

using namespace std;

class PeternakMemento : public Memento{
    private:
        Peternakan* peternakan;

    public:
        /**
         * @brief Konstruktor
         * 
         * @param pemainPeternakan  keadaan peternakan pemain sebelum suatu action
         */
        PeternakMemento(Inventory& pemain_inventory, int pemain_bb, int pemain_gulden, Toko& toko, Peternakan& pemainPeternakan);

        /**
         * @brief Destruktor
         * 
         */
        ~PeternakMemento();

        /**
         * @brief Mengembalikan keadaan peternakan pemain saat ini menjadi keadaan peternakan di memento
         * 
         * @param pemainPeternakan  peternakan pemain saat ini
         */
        void undoPeternakan(Peternakan* pemainPeternakan);
};

#endif