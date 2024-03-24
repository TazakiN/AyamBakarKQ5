#include "../Item/Item.hpp"

template <typename T>
class Grid
{
private:
    int row;
    int col;
    T ***grid;

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
};
