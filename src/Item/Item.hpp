// #include <iostream>
#include <string>

using namespace std;

class Item
{
private:
    string name;

public:
    Item(string name);
    ~Item();
    string getName();
};