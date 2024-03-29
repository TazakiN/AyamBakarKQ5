#include "Mediator.hpp"

using namespace std;

Mediator::Mediator(/* args */)
{
    // populate data dari file config
    populateData();
}

Mediator::~Mediator()
{
}

void Mediator::populateData()
{
    // baca config animal.txt
    string filename = "config/animal.txt";
    string masukan = readFile(filename);
    // Split the string into lines
    stringstream ss(masukan);
    string line;
    string words;
    while (getline(ss, line))
    {
        cout << line << endl;
        stringstream lines(line);
        getline(lines, words, ' ');
        cout << words[0] << endl;
    }
}