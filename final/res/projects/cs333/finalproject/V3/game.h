#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "map.h"

/**
 * This class represents the structure of a single Game.
 * This includes both the interface (public and private) and
 * attributes (private member data).
 */
class Game {
    public:
        /**
         * Create a new game.
         */
        Game();

        /**
         * Check to see if the current game has been ended
         * (i.e., has someone eaten the poisin crumb?)
         */
        bool gameEnded();

        /** Check a proposed move to see if it is legal.
         * A legal move must not go out of bounds.
         */
        bool moveIsLegal (int column, int row);

        /**
         * Allow access to the map
         *
         * @return map& reference to the map private data member
         */
        Map& getMap();


    private:
        /**
         * The map for this game.
         */
        Map myMap;
};

#endif
