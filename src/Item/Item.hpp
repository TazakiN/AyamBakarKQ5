#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

#include "../utils/pcolor.hpp"

using namespace std;

class Item
{
private:
    string name;
    string kode_huruf;

public:
    /**
     * @brief Konstruktor item 
     *
     * @param nama nama pemain
     * @param kode_huruf
     */
    Item(string name, string kode_huruf);

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
    string getKode();
};

#endif