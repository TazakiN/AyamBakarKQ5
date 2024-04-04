#include "Ladang.hpp"

Ladang::Ladang(int row, int col) : Grid<Tanaman>(row, col)
{
}

Ladang::~Ladang()
{
}

void Ladang::printLadang()
{
    Ladang::printGridHeader();

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
                Tanaman* tanaman = dynamic_cast<Tanaman*>(item);
                if (tanaman && tanaman->siapPanen()) {
                    cout << " " << p_green() << tanaman->getKode() << reset() << " |";
                } else if (tanaman) {
                    cout << " " << p_red() << tanaman->getKode() << reset() << " |";
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

void Ladang::printGridHeader()
{
    cout << "    ==================[ Ladang ]==================" << endl;
}