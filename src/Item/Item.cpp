#include "Item.hpp"

Item::Item(string name, string symbol) : name(name), symbol(symbol)
{
}
Item::~Item()
{
}

string Item::getName()
{
    return this->name;
}

string Item::getSymbol()
{
    return this->symbol;
}