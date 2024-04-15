#ifndef ACTIONHISTORY_HPP
#define ACTIONHISTORY_HPP

#include "Memento.hpp"
#include <stack>
using namespace std;

class ActionHistory{
    private:
        stack<Memento*> stack_memento;

    public:
        /**
         * @brief Konstruktor
         * 
         */
        ActionHistory();

        /**
         * @brief Destruktor
         * 
         */
        ~ActionHistory();

        /**
         * @brief Push memento ke stack paling atas
         * 
         * @param pm pointer to memento yang ingin di push
         */
        void pushMemento(Memento* pm);

        void popMemento();

        /**
         * @brief Mengembalikan memento paling atas
         * 
         * @return Memento* 
         */
        Memento* topMemento();

        void cleanHistory();

        bool isHistoryEmpty();
};

#endif