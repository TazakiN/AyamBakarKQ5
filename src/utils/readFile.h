#define READFILE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../Exception/Exception.hpp"

using namespace std;

/**
 * Membaca file dan mengembalikan string yang berisi isi file
 *
 * @param filepath nama file yang akan dibaca
 */
stringstream bacaFile(const string &filepath);

/**
 * Membaca file konfigurasi dan mengembalikan vector yang berisi konfigurasi
 *
 * @param filepath nama file yang akan dibaca
 */
vector<vector<string>> ekstrakConfig(const string &filepath);

/**
 * Mengubah string yang berisi posisi menjadi pair<int, int>
 *
 * @param position string yang berisi posisi <row, col>
 *
 * @return pair<int, int> yang berisi posisi <row, col>
 */
pair<int, int> positionStringToPair(const string &position);

/**
 * Mengubah pair<int, int> menjadi string yang berisi posisi
 *
 * @param position pair<int, int> yang berisi posisi <row, col>
 *
 * @return string yang berisi posisi <row, col>
 */
string pairToPositionString(const pair<int, int> &position);

/**
 * Memisahkan string berdasarkan delimiter
 *
 * @param string string yang akan dipisah
 * @param delimiter karakter pemisah
 *
 * @return vector<string> yang berisi string yang sudah dipisah
 */
vector<string> stringSplitter(string string, char delimiter);

/**
 * Menghapus whitespace di awal dan akhir string
 *
 * @param str string yang akan dihapus whitespace
 *
 * @return string yang sudah dihapus whitespace
 */
string trim(const string &str);