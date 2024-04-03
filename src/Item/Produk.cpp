#include "Produk.hpp"
// #include <iostream>

// using namespace std;

Produk::Produk(string nama, string kode_huruf, int id, string tipe, string origin, int pertambahan_berat, float harga) : Item(nama, kode_huruf) {
    this->id = id;
    this->tipe = tipe;
    this->origin = origin;
    this->pertambahan_berat = pertambahan_berat;
    this->harga = harga;
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

float Produk::getHarga() {
    return this->harga;
}

bool Produk::isMakanan() {
    return (this->tipe == "PRODUCT_FRUIT_PLANT" || this->tipe == "PRODUCT_MEAT");
}

Produk& Produk::operator=(const Produk& other) {
    this->id = other.id;
    this->tipe = other.tipe;
    this->origin = other.origin;
    this->pertambahan_berat = other.pertambahan_berat;
    this->harga = other.harga;
    return *this;
}

bool Produk::operator==(const Produk& other) {
    return this->tipe == other.tipe;
}