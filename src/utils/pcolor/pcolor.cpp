#include "pcolor.hpp"
#include <iostream>

using namespace std;

/**
 * Fungsi-fungsi untuk mengubah warna output di terminal
 * Penggunaan: cout << p_red() << "Hello, World!" << reset() << endl;
*/

/* Contoh */
// int main() {
//     // g++ -o p pcolor.cpp
//     cout << p_red() << "Hello, World!" << reset() << endl;
//     cout << p_green() << "Hello, World!" << reset() << endl;
//     cout << p_blue() << "Hello, World!" << reset() << endl;
//     cout << p_yellow() << "Hello, World!" << reset() << endl;
//     cout << p_magenta() << "Hello, World!" << reset() << endl;
//     cout << p_rgb(255, 0, 0) << "Hello, World!" << reset() << endl;
//     return 0;
// }

string p_red()
{
    return "\033[1;31m";
}

string p_green()
{
    return "\033[1;32m";
}

string p_blue()
{
    return "\033[1;34m";
}

string p_yellow()
{
    return "\033[1;33m";
}

string p_magenta()
{
    return "\033[1;35m";
}

string p_rgb(int r, int g, int b)
{
    return "\033[38;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m";
}

string reset()
{
    return "\033[0m";
}

