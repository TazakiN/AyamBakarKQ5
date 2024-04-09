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
         * @param pm 
         */
        void pushMemento(Memento* pm);


        /**
         * @brief Mengembalikan memento paling atas dan pop dari stack
         * 
         * @return Memento* 
         */
        Memento* popMemento();
};

#endif