#include "Hewan.hpp"

Hewan::Hewan(string nama, string kode_huruf, string tipe, int harga, int berat, int beratUntukPanen) : Makhluk(nama, kode_huruf, tipe, harga), berat(berat), beratUntukPanen(beratUntukPanen)
{
}

Hewan::~Hewan()
{
}

int Hewan::getBerat()
{
    return this->berat;
}

void Hewan::setBerat(int berat)
{
    this->berat = berat;
}

bool Hewan::siapPanen()
{
    return this->berat >= this->beratUntukPanen;
}

// void Hewan::setDataOfHewan(const vector<vector<string>>& newData) {
//     this->dataOfHewan = newData;
//     //test
//     // size newData
//     cout << "size newData: " << newData.size() << endl;
//     cout << "size newData[0]: " << newData[0].size() << endl;
//     //size dataOfHewan
//     cout << "size dataOfHewan: " << this->dataOfHewan.size() << endl;
//     cout << "size dataOfHewan[0]: " << this->dataOfHewan[0].size() << endl;
//     for (size_t i = 0; i < this->dataOfHewan.size()/2; ++i) {
//         for (size_t j = 0; j < this->dataOfHewan[i].size(); ++j) {
//             cout << "isi dataOfHewan[" << i << "][" << j << "]: " << this->dataOfHewan[i][j] << endl;
//         }
//         cout << endl;
//     }
// }