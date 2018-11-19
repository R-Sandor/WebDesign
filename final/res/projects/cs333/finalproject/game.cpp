#include <cstdlib>
#include <sys/types.h>
#include <iostream>
#include <string>
#include "computer1.h"
#include "computer3.h"
#include "map.h"
#include "game.h"


using namespace std;

Game::Game() {
    // Used by the who is next function to select player.
    playerSelect = 1;
    // Changes to 2 then three and then one every three player turns
    // therefore I am calling rounds
    rounds = 1;
    Map();

}

/**
 *
 */
bool Game::gameEnded( vector<int> finishLine,int spotCar1, int spotCar2,int spotCar3)
{
    for (int x = 0; x < 3; x++)
    {

        if (x == 1)
        for (std::vector<int>::const_iterator i = finishLine.begin(); i != finishLine.end(); ++i)
        {
            if (*i == spotCar1 )
            return true;

        }



        if (x == 2)
        for (std::vector<int>::const_iterator i = finishLine.begin(); i != finishLine.end(); ++i)
        {
            if (*i == spotCar2 )
            return true;

        }


        if (x == 3)
        for (std::vector<int>::const_iterator i = finishLine.begin(); i != finishLine.end(); ++i)
        {
            if (*i == spotCar3 )
            return true;

        }

    }
}


/**
 *
 */
Map& Game::getMap()
{
    // Print top line with numeric index of columns
    return myMap;
}

/**
*   Figure out who is next
*/
int Game::whoIsNext()
{
    if (rounds == 1)
    {
        if (playerSelect ==1)
        {
            playerSelect++;
            return 1;
        }
        else if (playerSelect == 2)
        {
            playerSelect++;
            return 2;
        }
        else if (playerSelect == 3)
        {
            playerSelect = 1;
            rounds = 2;
            return 3;
        }
    }
    else if (rounds == 2)
    {
        if (playerSelect ==1)
        {
            playerSelect++;
            return 2;
        }
        else if (playerSelect == 2)
        {
            playerSelect++;
            return 3;
        }
        else if (playerSelect == 3)
        {
            playerSelect = 1;
            rounds = 3;
            return 1;
        }
    }
      else if (rounds == 3)
    {
        if (playerSelect ==1)
        {
            playerSelect++;
            return 3;
        }
        else if (playerSelect == 2)
        {
            playerSelect++;
            return 1;
        }
        else if (playerSelect == 3)
        {
            playerSelect = 1;
            rounds = 1;
            return 2;
        }
    }

}




