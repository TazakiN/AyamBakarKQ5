#include "ActionHistory.hpp"
#include "Memento.hpp"

using namespace std;

ActionHistory::ActionHistory(){

};

ActionHistory::~ActionHistory(){
    while(!this->stack_memento.empty()){
        this->stack_memento.pop();
    } 
};

void ActionHistory::pushMemento(Memento* pm){
    this->stack_memento.push(pm);
};

Memento* ActionHistory::popMemento(){
    Memento* temp = this->stack_memento.top();
    this->stack_memento.pop();
    return temp;
};