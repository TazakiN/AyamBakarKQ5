// #include <iostream>
#include <string>

using namespace std;

class Item
{
private:
    string name;
    string symbol;

public:
    Item(string name, string symbol);
    ~Item();
    string getName();
    string getSymbol();
};