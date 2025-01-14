#include "Produk.hpp"
// #include <iostream>

// using namespace std;

// Produk::Produk(string nama, string kode_huruf, int id, string tipe, string origin, int pertambahan_berat, int harga) : Item(nama, kode_huruf, harga) {
//     this->id = id;
//     this->tipe = tipe;
//     this->origin = origin;
//     this->pertambahan_berat = pertambahan_berat;
// }

Produk::Produk(string nama, string kode_huruf, string tipe, string origin, int pertambahan_berat, int harga) : Item(nama, kode_huruf, harga) {
    this->tipe = tipe;
    this->origin = origin;
    this->pertambahan_berat = pertambahan_berat;
}

Produk::~Produk() {

}

string Produk::getTipe() {
    return this->tipe;
}

string Produk::getOrigin() {
    return this->origin;
}

int Produk::getPertambahanBerat() {
    return this->pertambahan_berat;
}

bool Produk::isMakanan() {
    return (this->tipe == "PRODUCT_FRUIT_PLANT" || this->tipe == "PRODUCT_ANIMAL");
}

// Produk& Produk::operator=(const Produk& other) {
//     this->id = other.id;
//     this->tipe = other.tipe;
//     this->origin = other.origin;
//     this->pertambahan_berat = other.pertambahan_berat;
//     return *this;
// }

Produk& Produk::operator=(const Produk& other) {
    this->tipe = other.tipe;
    this->origin = other.origin;
    this->pertambahan_berat = other.pertambahan_berat;
    return *this;
}

bool Produk::operator==(const Produk& other) {
    return this->tipe == other.tipe;
}