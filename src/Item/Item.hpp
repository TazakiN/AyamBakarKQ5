#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item
{
private:
    string name;
    string symbol;

public:
    /**
     * @brief Konstruktor item 
     *
     * @param nama nama pemain
     * @param symbol
     */
    Item(string name, string symbol);

    /**
     * Destruktor item
     */
    virtual ~Item();

    /**
     * Mengembalikan nama item
     *
     * @return nama item
     */
    string getName();

    /**
     * Mengembalikan kode huruf item
     *
     * @return kode huruf item
     */
    string getSymbol();
};

#endif