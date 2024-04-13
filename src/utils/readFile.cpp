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

pair<int, int> positionStringToPair(const string &position)
{
    int col = position[0] - 65;
    int row1 = position[1] - '0';
    int row2 = position[2] - '0' - 1;
    int row = row1 * 10 + row2;

    return make_pair(row, col);
}

vector<string> stringSplitter(string s, char del)
{
    stringstream ss(s);
    string word;
    vector<string> res;
    while (!ss.eof())
    {
        getline(ss, word, del);
        res.push_back(word);
    }

    return res;
}