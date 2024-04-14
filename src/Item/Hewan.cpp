#include "Hewan.hpp"
#include "../GameEngine/GameEngine.hpp"

Hewan::Hewan(string nama, string kode_huruf, string tipe, int harga, int berat, int beratUntukPanen) : Makhluk(nama, kode_huruf, tipe, harga, berat, beratUntukPanen)
{
}

Hewan::Hewan(const Hewan &other) : Makhluk(other.getName(), other.getKode(), other.getTipe(), other.getHarga(), other.getProgressPanen(), other.getTargetPanen())
{
}

Hewan::~Hewan()
{
}

int Hewan::getBerat()
{
    return getProgressPanen();
}

void Hewan::setBerat(int berat)
{
    setProgressPanen(berat);
}

vector<Produk *> Hewan::konversiPanen()
{
    // kode_huruf sebelum konversi -> setelah konversi -- nama produk setelah konversi:
    // COW -> COM -- COW_MEAT
    // SHP -> SHM -- SHEEP_MEAT
    // HRS -> HRM -- HORSE_MEAT
    // RBT -> RBM -- RABBIT_MEAT
    // SNK -> SNM -- SNAKE_MEAT
    // CHK -> CHM & CHE -- CHICKEN_MEAT & CHICKEN_EGG
    // DCK -> DCM & DCE -- DUCK_MEAT & DUCK_EGG

    // hasil produk:
    // Produk(string nama, string kode_huruf, int id, string tipe, string origin, int pertambahan_berat, int harga)

    GameEngine ge;

    string nama = this->getName();
    string namaProduk = ge.getProductAttributeByAny("NAME", "ORIGIN", nama);
    string kodeProduk = ge.getProductAttributeByAny("KODE_HURUF", "ORIGIN", nama);
    int idProduk = stoi(ge.getProductAttributeByAny("ID", "ORIGIN", nama));
    string tipeProduk = ge.getProductAttributeByAny("TYPE", "ORIGIN", nama);
    string originProduk = nama;
    int pertambahanBeratProduk = stoi(ge.getProductAttributeByAny("ADDED_WEIGHT", "ORIGIN", nama));
    int hargaProduk = stoi(ge.getProductAttributeByAny("PRICE", "ORIGIN", nama));

    // Pengecualian untuk CHICKEN dan DUCK karena menghasilkan dua produk
    if (nama == "CHICKEN")
    {
        vector<Produk *> produkHasil;

        // CHICKEN_MEAT
        produkHasil.push_back(new Produk(namaProduk, kodeProduk, idProduk, tipeProduk, originProduk, pertambahanBeratProduk, hargaProduk));

        // CHICKEN_EGG
        string kodeProduk = "CHE";
        string namaProduk = ge.getProductAttributeByAny("NAME", "KODE_HURUF", kodeProduk);
        int idProduk = stoi(ge.getProductAttributeByAny("ID", "KODE_HURUF", kodeProduk));
        string tipeProduk = ge.getProductAttributeByAny("TYPE", "KODE_HURUF", kodeProduk);
        int pertambahanBeratProduk = stoi(ge.getProductAttributeByAny("ADDED_WEIGHT", "KODE_HURUF", kodeProduk));
        int hargaProduk = stoi(ge.getProductAttributeByAny("PRICE", "KODE_HURUF", kodeProduk));

        produkHasil.push_back(new Produk(namaProduk, kodeProduk, idProduk, tipeProduk, originProduk, pertambahanBeratProduk, hargaProduk));

        return produkHasil;
    }
    else if (nama == "DUCK")
    {
        vector<Produk *> produkHasil;

        // DUCK_MEAT
        produkHasil.push_back(new Produk(namaProduk, kodeProduk, idProduk, tipeProduk, originProduk, pertambahanBeratProduk, hargaProduk));

        // DUCK_EGG
        string kodeProduk = "DCE";
        string namaProduk = ge.getProductAttributeByAny("NAME", "KODE_HURUF", kodeProduk);
        int idProduk = stoi(ge.getProductAttributeByAny("ID", "KODE_HURUF", kodeProduk));
        string tipeProduk = ge.getProductAttributeByAny("TYPE", "KODE_HURUF", kodeProduk);
        int pertambahanBeratProduk = stoi(ge.getProductAttributeByAny("ADDED_WEIGHT", "KODE_HURUF", kodeProduk));
        int hargaProduk = stoi(ge.getProductAttributeByAny("PRICE", "KODE_HURUF", kodeProduk));

        produkHasil.push_back(new Produk(namaProduk, kodeProduk, idProduk, tipeProduk, originProduk, pertambahanBeratProduk, hargaProduk));

        return produkHasil;
    }
    else
    {
        return {new Produk(namaProduk, kodeProduk, idProduk, tipeProduk, originProduk, pertambahanBeratProduk, hargaProduk)};
    }
}