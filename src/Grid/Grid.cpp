#include "Grid.hpp"
#include <iostream>

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
    // TODO : Implementasi printGrid
}

template <typename T>
bool Grid<T>::isEmpty(int num)
{
    // TODO : Implementasi isEmpty
    if (num)
        return true;
    return false;
}

template class Grid<Item>;