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
    else
    {
        TidakDapatBukaFile e;
        throw e;
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

string pairToPositionString(const pair<int, int> &position)
{
    string res = "";
    res += (char)(position.second + 65);
    res += to_string(position.first / 10);
    res += to_string(position.first % 10 + 1);

    return res;
}

vector<string> stringSplitter(string s, char del)
{
    stringstream ss(s);
    string word;
    vector<string> res;
    while (!ss.eof())
    {
        getline(ss, word, del);
        // Hapus spasi di awal kata
        word.erase(0, word.find_first_not_of(" "));
        // Hapus spasi di akhir kata
        word.erase(word.find_last_not_of(" ") + 1);
        if (!word.empty()) 
            res.push_back(word);
    }
    
    return res;
}

string trim(const string &str)
{
    const string WHITESPACE = " \t\n\r\f\v"; // Define whitespace characters

    size_t start = str.find_first_not_of(WHITESPACE);
    if (start == string::npos)
    {
        return ""; // String consists only of whitespace
    }

    size_t end = str.find_last_not_of(WHITESPACE);

    size_t range = end - start + 1;
    return str.substr(start, range);
}