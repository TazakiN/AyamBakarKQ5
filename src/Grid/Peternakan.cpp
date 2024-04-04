#include "Peternakan.hpp"

Peternakan::Peternakan(int row, int col) : Grid<Hewan>(row, col)
{
}

Peternakan::~Peternakan()
{
}

void Peternakan::printPeternakan()
{
    Peternakan::printGridHeader();

    int startChar = 65;
    
    // menampilkan nama nama kolom
    cout << "    ";
    for (int i = 1; i <= getCol(); i++) {
        cout << "   " << char(startChar) << "  ";
        startChar++;
    }
    cout << endl;

    // menampilkan papan
    for (int i = 1; i <= getRow(); i++) {
        // menampilkan garis horizontal
        cout << "    ";
        for (int j = 1; j <= getCol(); j++) {
            cout << "+-----";
        }
        cout << "+" << endl;

        // menampilkan nomor baris
        if (i < 10) {
            cout << "0";
        }
        cout << i << "  |";

        // menampilkan isi papan
        for (int j = 1; j <= getCol(); j++) {
            Item* item = getItem(i, j);
            if (item == nullptr) {
                cout << "     |";
            } else {
                Hewan* hewan = dynamic_cast<Hewan*>(item);
                if (hewan && hewan->siapPanen()) {
                    cout << " " << p_green() << hewan->getKode() << reset() << " |";
                } else if (hewan) {
                    cout << " " << p_red() << hewan->getKode() << reset() << " |";
                }
            }
        }
        cout << endl;
    }
    // buat garis horizontal terakhir
    cout << "    ";
    for (int j = 1; j <= getCol(); j++) {
        cout << "+-----";
    }
    cout << "+" << endl;
}

void Peternakan::printGridHeader()
{
    cout << "    ==================[ Peternakan ]==================" << endl;
}