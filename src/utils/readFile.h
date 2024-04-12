#define READFILE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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