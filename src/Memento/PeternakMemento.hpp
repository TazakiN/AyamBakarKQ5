#ifndef PETERNAKMEMENTO_HPP
#define PETERNAKMEMENTO_HPP

#include "../Grid/Peternakan.hpp"

using namespace std;

class PeternakMemento{
    private:
        Peternakan* peternakan;

    public:
        /**
         * @brief Konstruktor
         * 
         * @param pemainPeternakan  keadaan peternakan pemain sebelum suatu action
         */
        PeternakMemento(Peternakan& pemainPeternakan);

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