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

vector<vector<string>> ekstrakConfig(const string &filepath)
{
    stringstream buffer = bacaFile(filepath);
    vector<vector<string>> res;
    string line;

    while (getline(buffer, line))
    {
        vector<string> temp;
        stringstream ss(line);
        string word;

        while (ss >> word)
        {
            temp.push_back(word);
        }

        res.push_back(temp);
    }

    return res;
}