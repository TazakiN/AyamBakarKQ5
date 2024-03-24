#include "Item.hpp"

Item::Item(string name)
{
    this->name = name;
}

Item::~Item()
{
}

string Item::getName()
{
    return this->name;
}