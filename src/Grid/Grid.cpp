#include "Grid.hpp"

using namespace std;

template <typename T>
Grid<T>::Grid(int row, int col)
{
    this->row = row;
    this->col = col;
    this->grid = new T **[row];
    for (int i = 0; i < row; i++)
    {
        this->grid[i] = new T *[col];
        for (int j = 0; j < col; j++)
        {
            this->grid[i][j] = nullptr;
        }
    }
}

template <typename T>
Grid<T>::~Grid()
{
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            if (this->grid[i][j] != nullptr)
            {
                delete this->grid[i][j];
            }
        }
        delete[] this->grid[i];
    }
    delete[] this->grid;
}

template <typename T>
int Grid<T>::getRow()
{
    return this->row;
}

template <typename T>
int Grid<T>::getCol()
{
    return this->col;
}

template <typename T>
T *Grid<T>::getItem(int row, int col)
{
    return this->grid[row][col];
}

template <typename T>
T *Grid<T>::getItem(string position)
{
    int row = position[0] - 65;
    int col1 = position[1] - '0';
    int col2 = position[2] - '0';
    int col = col1 * 10 + col2;
    return getItem(row, col);
}

template <typename T>
void Grid<T>::setItem(int row, int col, T *item)
{
    if (this->grid[row][col] != nullptr)
    {
        delete this->grid[row][col];
    }
    this->grid[row][col] = item;
}

template <typename T>
void Grid<T>::removeItem(int row, int col)
{
    if (this->grid[row][col] != nullptr)
    {
        delete this->grid[row][col];
        this->grid[row][col] = nullptr;
    }
}

template <typename T>
void Grid<T>::printGrid()
{
    int startChar = 65;
    // Nampilin nama nama kolom
    cout << "    ";
    for (int i = 1; i <= col; i++)
    {
        cout << "   " << char(startChar) << "  ";
        startChar++;
    }
    cout << endl;

    // Menampilkan papan
    for (int i = 1; i <= row; i++)
    {
        // Nampilin garis horizontal
        cout << "    ";
        for (int j = 1; j <= col; j++)
        {
            cout << "+-----";
        }
        cout << "+" << endl;

        // Nampilin nomor baris
        if (i < 10)
        {
            cout << "0";
        }
        cout << i << "  |";
        // Nampilin isi papan
        for (int j = 1; j <= col; j++)
        {
            if (this->grid[i - 1][j - 1] == nullptr)
            {
                cout << "     |";
            }
            else
            {
                cout << " ";
                cout << this->grid[i - 1][j - 1]->getSymbol();
                cout << " |";
            }
        }
        cout << endl;
    }
    // Nampilin garis horizontal terakhir
    cout << "    ";
    for (int j = 1; j <= col; j++)
    {
        cout << "+-----";
    }
    cout << "+" << endl;
}

template <typename T>
bool Grid<T>::isEmpty(int num)
{
    // TODO : Implementasi isEmpty
    // kode dibawah biar ga error pas makefile di linux
    if (num)
        return true;
    return false;
}

template <typename T>
void Grid<T>::printGridHeader()
{
    // * kosongin aja soalnya virtual
}

template class Grid<Item>;