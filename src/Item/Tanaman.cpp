#include "Tanaman.hpp"
#include "../GameEngine/GameEngine.hpp"

Tanaman::Tanaman(string nama, string kode_huruf, string tipe, int umur, int harga, int durasiUntukPanen) : Makhluk(nama, kode_huruf, tipe, harga)
{
    this->durasiUntukPanen = durasiUntukPanen;
    this->umur = umur;
    cout << endl;
    cout << p_yellow() << "Test: Tanaman " << getName() << " dengan detail: " << endl;
    cout << "Kode Huruf: " << kode_huruf << endl;
    cout << "Tipe: " << tipe << endl;
    cout << "Umur: " << umur << endl;
    cout << "Harga: " << harga << endl;
    cout << "Durasi Untuk Panen: " << durasiUntukPanen << endl << reset();
}

Tanaman::~Tanaman()
{
}

void Tanaman::setUmur(int umur)
{
    this->umur = umur;
}

bool Tanaman::siapPanen()
{
    return this->umur >= this->durasiUntukPanen;
}

int Tanaman::getUmur()
{
    return this->umur;
}

// void Tanaman::setDataOfTanaman(const vector<vector<string>> &dataOfTanaman)
// {
//     this->dataOfTanaman = dataOfTanaman;
//     //test
//     // size newData
//     cout << "size newData: " << dataOfTanaman.size() << endl;
//     cout << "size newData[0]: " << dataOfTanaman[0].size() << endl;
//     //size dataOfHewan
//     cout << "size dataOfTanaman: " << this->dataOfTanaman.size() << endl;
//     cout << "size dataOfTanaman[0]: " << this->dataOfTanaman[0].size() << endl;
//     for (size_t i = 0; i < this->dataOfTanaman.size() / 2; ++i)
//     {
//         for (size_t j = 0; j < this->dataOfTanaman[i].size(); ++j)
//         {
//             cout << "isi dataOfTanaman[" << i << "][" << j << "]: " << this->dataOfTanaman[i][j] << endl;
//         }
//         cout << endl;
//     }
// }

vector<Produk*> Tanaman::konversiPanen() {
    GameEngine ge;
    // ge.readConfig();

    string nama = this->getName();
    string namaProduk = ge.getProductAttributeByAny("NAME", "ORIGIN", nama);
    string kodeProduk = ge.getProductAttributeByAny("KODE_HURUF", "ORIGIN", nama);
    int idProduk = stoi(ge.getProductAttributeByAny("ID", "ORIGIN", nama));
    string tipeProduk = ge.getProductAttributeByAny("TYPE", "ORIGIN", nama);
    string originProduk = nama;
    int pertambahanBeratProduk = stoi(ge.getProductAttributeByAny("ADDED_WEIGHT", "ORIGIN", nama));
    int hargaProduk = stoi(ge.getProductAttributeByAny("PRICE", "ORIGIN", nama));

    return {new Produk(namaProduk, kodeProduk, idProduk, tipeProduk, originProduk, pertambahanBeratProduk, hargaProduk)};
}