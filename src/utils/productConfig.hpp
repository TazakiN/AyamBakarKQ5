#ifndef PRODUCTCONFIG_HPP
#define PRODUCTCONFIG_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "readFile.h"

using namespace std;

class ProdukSatuan {
public:
    int id;
    string code;
    string name;
    string type;
    string origin;
    int addedWeight;
    int price;

    // Constructor untuk menginisialisasi objek ProdukSatuan
    ProdukSatuan(int _id, const string& _code, const string& _name, const string& _type, const string& _origin, int _addedWeight, int _price);
};

class ProductConfig {
private:
    vector<ProdukSatuan> products;

public:
    // Constructor untuk membaca data dari stringstream
    ProductConfig(stringstream& fileStream);

    // Method untuk mendapatkan objek berdasarkan Kode_Huruf
    ProdukSatuan getProductByKodeHuruf(string kodeHuruf);
};

// // Penggunaan
// int main() {
//     // Membaca file dan mendapatkan stringstream
//     stringstream fileStream = bacaFile("product.txt");

//     // Membuat objek ProductConfig dan membaca data dari stringstream
//     ProductConfig config(fileStream);

//     // Menggunakan method getProductByKodeHuruf untuk mendapatkan objek dengan Kode_Huruf tertentu
//     ProdukSatuan product = config.getProductByKodeHuruf("ALW");

//     // Contoh penggunaan atribut objek yang didapatkan
//     cout << "Product Name: " << product.name << endl;
//     cout << "Product Type: " << product.type << endl;
//     cout << "Product Price: " << product.price << endl;

//     return 0;
// }


#endif 