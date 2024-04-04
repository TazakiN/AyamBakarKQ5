#include "productConfig.hpp"

ProdukSatuan::ProdukSatuan(int _id, const string& _code, const string& _name, const string& _type, const string& _origin, int _addedWeight, int _price) : id(_id), code(_code), name(_name), type(_type), origin(_origin), addedWeight(_addedWeight), price(_price) {}

ProductConfig::ProductConfig(stringstream& fileStream) {
    string line;
    while (getline(fileStream, line)) {
        stringstream ss(line);
        int id, addedWeight, price;
        string code, name, type, origin;
        ss >> id >> code >> name >> type >> origin >> addedWeight >> price;
        ProdukSatuan product(id, code, name, type, origin, addedWeight, price);
        products.push_back(product);
    }
}

ProdukSatuan ProductConfig::getProductByKodeHuruf(string kodeHuruf) {
    for (const auto& product : products) {
        if (product.code == kodeHuruf) {
            return product;
        }
    }
    cerr << "Product dengan kode " << kodeHuruf << " tidak ditemukan!" << endl;
    // Mengembalikan objek default jika tidak ditemukan
    return ProdukSatuan(0, "", "", "", "", 0, 0); // Objek default ceritanya
}