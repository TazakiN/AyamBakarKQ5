#include <iostream>
#include "utils/readFile.h"

using namespace std;

int main()
{
    string filename = "config/animal.txt";
    stringstream buffer = bacaFile(filename);
    cout << buffer.str() << endl;
    return 0;
}
