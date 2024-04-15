#include "ActionHistory.hpp"
#include "Memento.hpp"

using namespace std;

ActionHistory::ActionHistory(){

};

ActionHistory::~ActionHistory(){
    while(!this->stack_memento.empty()){
        delete stack_memento.top();
        this->stack_memento.pop();
    } 
};

void ActionHistory::pushMemento(Memento* pm){
    this->stack_memento.push(pm);
};

void ActionHistory::popMemento(){
    this->stack_memento.pop();
}

Memento* ActionHistory::topMemento(){
    Memento* temp = this->stack_memento.top();
    return temp;
};

void ActionHistory::cleanHistory(){
    while(!this->stack_memento.empty()){
        delete this->stack_memento.top();
        this->stack_memento.pop();
    }
}

bool ActionHistory::isHistoryEmpty(){
    return this->stack_memento.empty();
}