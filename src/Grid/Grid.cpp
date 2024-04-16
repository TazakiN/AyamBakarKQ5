#include "Grid.hpp"

using namespace std;

template <typename T>
Grid<T>::Grid(int row, int col)
{
    this->row = row;
    this->col = col;
    this->grid = vector<vector<T *>>(row, vector<T *>(col, nullptr));
}

template <typename T>
Grid<T>::~Grid()
{
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
    // Jika posisi yang diambil di luar batas grid, throw exception
    if (row < 0 || row >= this->row || col < 0 || col >= this->col)
    {
        PetakTidakValid e;
        throw e;
    }

    return this->grid[row][col];
}

template <typename T>
T *Grid<T>::getItem(string position)
{
    int row = stoi(position.substr(1)) - 1;
    int col = position[0] - 'A';
    // test print row and col
    // cout << "row: " << row << " col: " << col << endl;
    return getItem(row, col);
}

template <typename T>
void Grid<T>::setItem(int row, int col, T *item)
{
    this->grid[row][col] = item;
}

template <typename T>
void Grid<T>::removeItem(int row, int col)
{
    if (this->grid[row][col] != nullptr)
    {
        // delete this->grid[row][col];
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
                cout << this->grid[i - 1][j - 1]->getKode();
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
    // kembalikan apakah banyak posisi kosong >= num
    int countEmpty = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == nullptr)
            {
                countEmpty++;
                if (countEmpty >= num)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

template <typename T>
int Grid<T>::hitungKosong()
{
    int countEmpty = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == nullptr)
            {
                countEmpty++;
            }
        }
    }
    return countEmpty;
}

template <typename T>
void Grid<T>::printGridHeader()
{
    // * kosongin aja soalnya virtual
}

template <typename T>
void Grid<T>::printGridWithHeader()
{
    printGridHeader();
    printGrid();
}

template <typename T>
int Grid<T>::getBanyakElement()
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] != nullptr)
            {
                count++;
            }
        }
    }
    return count;
}

template class Grid<Item>;
template class Grid<Makhluk>;
template class Grid<Hewan>;
template class Grid<Tanaman>;