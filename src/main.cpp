#include <iostream>
#include "utils/readFile.h"
#include "utils/pcolor.hpp"
#include "Item/Herbivora.hpp"
#include "Item/Karnivora.hpp"
#include "Item/Omnivora.hpp"
#include "Item/Tanaman.hpp"
#include "Grid/Inventory.hpp"
#include "Item/Bangunan.hpp"
#include "Grid/Toko.hpp"
#include "Pemain/Walikota.hpp"
#include "GameEngine/GameEngine.hpp"
#include <cmath>

using namespace std;

int main()
{
    GameEngine gameEngine;
    gameEngine.initGame();

    return 0;
}
