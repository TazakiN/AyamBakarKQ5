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
    int harga;

public:
    /**
     * @brief Konstruktor item
     *
     * @param nama nama pemain
     * @param kode_huruf
     */
    Item(string name, string kode_huruf, int harga);

    /**
     * Destruktor item
     */
    virtual ~Item();

    /**
     * Mengembalikan nama item
     *
     * @return nama item
     */
    std::string getName() const;


    /**
     * Mengembalikan kode huruf item
     *
     * @return kode huruf item
     */
    std::string getKode() const;

    /**
     * Mengembalikan harga item
     */
    int getHarga() const;
};

#endif