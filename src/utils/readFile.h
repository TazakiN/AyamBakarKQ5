#define READFILE_H
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

/**
 * Membaca file dan mengembalikan string yang berisi isi file
 *
 * @param filepath nama file yang akan dibaca
 */
stringstream bacaFile(const string &filepath);
