#include <iostream>
#include "utils/readFile.h"
#include "utils/pcolor.hpp"

using namespace std;

int main()
{
    string filename = "config/animal.txt";
    stringstream buffer = bacaFile(filename);
    cout << p_magenta() <<buffer.str() << reset() << endl;
    return 0;
}
