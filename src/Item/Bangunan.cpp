#include "Bangunan.hpp"

Bangunan::Bangunan(string nama, string kode_huruf, int harga) : Item(nama, kode_huruf, harga)
{
}

Bangunan::~Bangunan()
{
}

void Bangunan::tambahResep(string material, int kuantitas) {
    this->resep[material] = kuantitas;
}

map<string, int> Bangunan::getResep() {
    return this->resep;
}

void Bangunan::printResep() {
    cout << "Resep " << this->getName() << ":" << endl;
    for (const auto& pasangan : this->resep) {
        cout << pasangan.first << " " << pasangan.second << endl;
    }
    // for (auto it = this->resep.begin(); it != this->resep.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }
}