#include "readFile.h"

using namespace std;

stringstream bacaFile(const string &filepath)
{
    ifstream file(filepath);
    stringstream buffer;

    if (file.is_open())
    {
        buffer << file.rdbuf();
        file.close();
    }
    else // nanti ganti exception
    {
        cout << "Unable to open file" << endl;
    }

    return buffer;
}
