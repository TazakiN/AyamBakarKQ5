#include <iostream>
#include "utils/readFile.h"

using namespace std;

int main()
{
    string filename = "config/animal.txt";
    string masukan = readFile(filename);
    // Split the string into lines
    stringstream ss(masukan);
    string line;
    while (getline(ss, line))
    {
        cout << line << endl;
    }
    return 0;
}
