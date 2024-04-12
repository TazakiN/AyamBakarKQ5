#include "Lahan.hpp"

template <typename T>
Lahan<T>::Lahan(int row, int col) : Grid<T>(row, col)
{
}

template <typename T>
Lahan<T>::~Lahan()
{
}

template <typename T>
void Lahan<T>::printLahan()
{
    int startChar = 65;

    // menampilkan nama nama kolom
    cout << "    ";
    for (int i = 1; i <= this->getCol(); i++)
    {
        cout << "   " << char(startChar) << "  ";
        startChar++;
    }
    cout << endl;

    // menampilkan papan
    for (int i = 1; i <= this->getRow(); i++)
    {
        // menampilkan garis horizontal
        cout << "    ";
        for (int j = 1; j <= this->getCol(); j++)
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
        for (int j = 1; j <= this->getCol(); j++)
        {
            Makhluk *makhluk = dynamic_cast<Makhluk *>(this->getItem(i - 1, j - 1));
            if (makhluk == nullptr)
            {
                cout << "     |";
            }
            else
            {
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
    for (int j = 1; j <= this->getCol(); j++)
    {
        cout << "+-----";
    }
    cout << "+" << endl;
}

template class Lahan<Tanaman>;
template class Lahan<Hewan>;