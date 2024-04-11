#include "Lahan.hpp"

Lahan::Lahan(int row, int col) : Grid<Makhluk>(row, col)
{
}

Lahan::~Lahan()
{
}

void Lahan::printLahan()
{
    int startChar = 65;

    // menampilkan nama nama kolom
    cout << "    ";
    for (int i = 1; i <= getCol(); i++)
    {
        cout << "   " << char(startChar) << "  ";
        startChar++;
    }
    cout << endl;

    // menampilkan papan
    for (int i = 1; i <= getRow(); i++)
    {
        // menampilkan garis horizontal
        cout << "    ";
        for (int j = 1; j <= getCol(); j++)
        {
            cout << "+-----";
        }
        cout << "+" << endl;

        // menampilkan nomor baris
        if (i < 10)
        {
            cout << "0";
        }
        cout << i << "  |";

        // menampilkan isi papan
        for (int j = 1; j <= getCol(); j++)
        {
            Item *item = getItem(i, j);
            if (item == nullptr)
            {
                cout << "     |";
            }
            else
            {
                Makhluk *makhluk = dynamic_cast<Makhluk *>(item);
                if (makhluk && makhluk->siapPanen())
                {
                    cout << " " << p_green() << makhluk->getKode() << reset() << " |";
                }
                else if (makhluk)
                {
                    cout << " " << p_red() << makhluk->getKode() << reset() << " |";
                }
            }
        }
        cout << endl;
    }
    // buat garis horizontal terakhir
    cout << "    ";
    for (int j = 1; j <= getCol(); j++)
    {
        cout << "+-----";
    }
    cout << "+" << endl;
}