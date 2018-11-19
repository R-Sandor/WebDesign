#include <cstdlib>
#include <sys/types.h>
#include <iostream>
#include <string>
//#include "computer1.h"
//#include "computer2.h"
#include "map.h"
#include "game.h"


using namespace std;

Game::Game() {

    Map();

}

/**
 *
 */
bool Game::gameEnded()
{
    //return getMap().getNumberOfColumns() <= 0;
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
 *
 */
bool Game::moveIsLegal (int column, int row) {
    //return (column >= 0) && ( row >= 0)
    //&& (row < getMap().getNumberOfRows(column))
    //&& (column < getCookie().getNumberOfColumns(row));
}


