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
    delete this->stack_memento.top();
    this->stack_memento.pop();
}

Memento* ActionHistory::topMemento(){
    return this->stack_memento.top();
};

void ActionHistory::cleanHistory(){
    while(!this->stack_memento.empty()){
        stack_memento.top()->deleteDeletedItems();
        delete this->stack_memento.top();
        this->stack_memento.pop();
    }
}

bool ActionHistory::isHistoryEmpty(){
    return this->stack_memento.empty();
}