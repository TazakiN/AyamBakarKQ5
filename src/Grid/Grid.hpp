#ifndef GRID_HPP
#define GRID_HPP

#include "../utils/readFile.h"
#include "../Item/Item.hpp"
#include "../Item/Hewan.hpp"
#include "../Item/Tanaman.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
class Grid
{
private:
    int row;
    int col;
    vector<vector<T *>> grid;

public:
    /**
     * Konstruktor kelas Grid
     *
     *
     * @param row jumlah baris dari grid
     * @param col jumlah kolom dari grid
     */
    Grid(int row, int col);

    /**
     * Destruktor kelas Grid
     *
     */
    ~Grid();

    /**
     * Mengembalikan jumlah baris dari grid
     */
    int getRow();

    /**
     * Mengembalikan jumlah kolom dari grid
     */
    int getCol();

    /**
     * Mengembalikan item pada posisi tertentu
     *
     * @param row baris dari item yang ingin diambil
     * @param col kolom dari item yang ingin diambil
     */
    T *getItem(int row, int col);

    /**
     * Mengembalikan item pada posisi tertentu
     *
     * @param position posisi dari item yang ingin diambil
     */
    T *getItem(string position);

    /**
     * Mengubah item pada posisi tertentu
     *
     * @param row baris dari item yang ingin diubah
     * @param col kolom dari item yang ingin diubah
     * @param item item yang ingin diubah
     */
    void setItem(int row, int col, T *item);

    /**
     * Menghapus item pada posisi tertentu
     *
     * @param row baris dari item yang ingin dihapus
     * @param col kolom dari item yang ingin dihapus
     */
    void removeItem(int row, int col);

    /**
     * Menampilkan header grid ke layar
     */
    virtual void printGridHeader() = 0;

    /**
     * Menampilkan grid ke layar
     */
    void printGrid();

    /**
     * Validator
     * Mengembalikan true jika terdapat num posisi yang kosong
     *
     * @param num minimal banyak posisi yang kosong
     */
    bool isEmpty(int num);

    /**
     * Menghitung jumlah posisi yang kosong
     */
    int hitungKosong();

    /**
     * Menampilkan grid ke layar dengna header
     */
    void printGridWithHeader();

    /**
     * Mengembalikan banyak elemen yang ada di grid
     *
     * @return banyak elemen yang ada di grid
     */
    int getBanyakElement();
};

#endif