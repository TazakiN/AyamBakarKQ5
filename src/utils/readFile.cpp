#include "readFile.h"

using namespace std;

string readFile(const string &filepath)
{
    ifstream file(filepath);
    stringstream buffer;
    string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            buffer << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    return buffer.str();
}