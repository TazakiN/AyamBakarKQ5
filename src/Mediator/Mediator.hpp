#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "../Pemain/Pemain.hpp"
#include "../utils/readFile.h"

using namespace std;

class Mediator
{
private:
    vector<Pemain *> pemainList;
    // vector<Hewan *> dataHewan;
    // vector<Tanaman *> dataTanaman;
    int currentPemain;
    int guldenMenang;
    int beratBadanMenang;
    pair<int, int> ukuranInventory;
    pair<int, int> ukuranLadang;
    pair<int, int> ukuranPeternakan;

public:
    Mediator(/* args */);
    ~Mediator();

    void populateData();
};
