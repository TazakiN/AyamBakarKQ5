#ifndef ACTIONHISTORY_HPP
#define ACTIONHISTORY_HPP

#include "Memento.hpp"
#include <stack>
using namespace std;

class ActionHistory{
    private:
        stack<Memento*> stack_memento;
};

#endif