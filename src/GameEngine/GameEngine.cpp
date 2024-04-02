#include "GameEngine.hpp"

using namespace std;

GameEngine::GameEngine(/* args */)
{
    // populate data dari file config
    populateData();
}

GameEngine::~GameEngine()
{
}

void GameEngine::populateData()
{
    // ********** BACA CONFIG MISC ********** //
    string filename = "config/misc.txt";
    stringstream masukan = bacaFile(filename);
    string line;

    // masukin guldenMenang
    getline(masukan, line);
    guldenMenang = stoi(line);

    // masukin beratBadanMenang
    getline(masukan, line);
    beratBadanMenang = stoi(line);

    // masukin ukuran inventory
    getline(masukan, line);
    stringstream ss(line);
    string token;
    getline(ss, token, ' ');
    ukuranInventory.first = stoi(token);
    getline(ss, token, ' ');
    ukuranInventory.second = stoi(token);

    // masukin ukuran ladang
    getline(masukan, line);
    stringstream ss2(line);
    getline(ss2, token, ' ');
    ukuranLadang.first = stoi(token);
    getline(ss2, token, ' ');
    ukuranLadang.second = stoi(token);

    // masukin ukuran peternakan
    getline(masukan, line);
    stringstream ss3(line);
    getline(ss3, token, ' ');
    ukuranPeternakan.first = stoi(token);
    getline(ss3, token, ' ');
    ukuranPeternakan.second = stoi(token);

    // ********** BACA CONFIG RECIPE ********** //
    // Membaca data per baris
    masukan = bacaFile("config/recipe.txt");
    while (getline(masukan, line))
    {
        // Memecah baris per spasi
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        listOfResepBangunan.push_back(tokens);
    }

    // ********** BACA CONFIG ANIMAL ********** //
    // Membaca data per baris
    masukan = bacaFile("config/animal.txt");
    while (getline(masukan, line))
    {
        // Memecah baris per spasi
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        dataOfHewan.push_back(tokens);
    }

    // ********** BACA CONFIG PLANT ********** //
    // Membaca data per baris
    masukan = bacaFile("config/plant.txt");
    while (getline(masukan, line))
    {
        // Memecah baris per spasi
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        dataOfTanaman.push_back(tokens);
    }

    // ********** BACA CONFIG PRODUCT ********** //
    // Membaca data per baris
    masukan = bacaFile("config/product.txt");
    while (getline(masukan, line))
    {
        // Memecah baris per spasi
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        dataOfProduct.push_back(tokens);
    }
}