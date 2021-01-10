#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include "Flatulan.h"
#include "Player.h"
#include "globals.h"
#include "City.h"
#include "Game.h"
using namespace std;


int main()
{
    // Create a game
    // Use this instead to create a mini-game:   
    //Game g(3, 4, 2);
    Game g(7, 8, 25);

    // Play the game
    g.play();

    return 0;
}

