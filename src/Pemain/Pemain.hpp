#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include "../Grid/Inventory.hpp"
#include "../Item/Produk.hpp"

class Pemain
{
private:
    Inventory *inventory;
    float berat_badan;
    float gulden;
    string nama;

public:
    /**
     * @brief Konstruktor pemain dengan nama tertentu.
     *
     * @param name nama pemain
     * @param row banyak baris Inventory pemain
     * @param col banyak kolom Inventory pemain
     */
    Pemain(string name, int row, int col);

    /**
     * Destruktor pemain
     */
    ~Pemain();

    /**
     * Mengembalikan besar berat badan pemain
     *
     * @return berat badan pemain
     */
    float getBeratBadan();

    /**
     * Menambah besar berat badan pemain
     *
     * @param bb pertambahan berat badan pemain
     */
    void tambahBeratBadan(float bb);

    /**
     * Mengembalikan jumlah gulden pemain
     *
     * @return jumlah gulden pemain
     */
    float getGulden();

    /**
     * Menambah jumlah gulden pemain
     *
     * @param g jumlah gulden yang ditambah
     */
    void tambahkanGulden(float g);

    /**
     * Mengurangi jumlah gulden pemain
     *
     * @param g jumlah gulden yang dikurang
     */
    void kurangiGulden(float g);

    /**
     * Mengembalikan nama pemain
     *
     * @return nama pemain
     */
    string getName();

    /**
     * Mengeluarkan item dari inventory
     *
     * @param idx row item yang ingin dikeluarkan
     * @param idx column item yang ingin dikeluarkan
     */
    void keluarkanItem(int idx_row, int idx_col);

    /**
     * Memasukkan item ke dalam inventory
     *
     * @param idx row item yang ingin dimasukkan
     * @param idx column item yang ingin dimasukkan
     */
    void masukanItem(Item item, int idx_row, int idx_col);

    /**
     * Memasukkan item ke dalam inventory pada posisi yang kosong pertama
     *
     * @param item yang ingin dimasukkan
     */
    void masukanItem(Item *item);

    /**
     * Membeli barang dari toko
     *
     * @param nama_item yang ingin dibeli
     * @param kuantitas item yang ingin dibeli
     * @param idx row inventory yang ingin dimasukkan item yang baru dibeli
     * @param idx row inventory yang ingin dimasukkan item yang baru dibeli
     */
    void beli(Item nama_item, int kuantitas, int idx_row, int idx_col);

    /**
     * Menjual barang ke toko
     *
     * @param nama_item yang ingin dijual
     * @param kuantitas item yang ingin dibeli
     * @param idx row inventory item yang ingin dijual
     * @param idx row inventory item yang ingin dijual
     */
    void jual(Item nama_item, int kuantitas, int idx_row, int idx_col);

    /**
     * Melakukan aktivitas makan yang nantinya dapat menambah berat badan
     *
     */
    void makan();

    Inventory *getInventory();

    // Menambahkan operator < untuk priority queue
    bool operator<(const Pemain &other) const
    {
        return this->nama < other.nama;
    }
};

#endif