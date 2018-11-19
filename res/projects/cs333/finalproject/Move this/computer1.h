#ifndef COMPUTERP2_H
#define COMPUTERP2_H

#include <string>

#include "game.h"

/**
 * This class represents the structure of a single ComputerPlayer.
 * This includes both the interface (public and private) and
 * attributes (private member data).
 */
class Computer1 {
    public:
        /**
         * Construct a new {CoumpterPlayer}. This requires
         * _numGamesWon_ to be set to zero
         */
        Computer1();

        /**
         * Get the computer player's next move for this game.
         * "Return" the move as location x,y of next bite.
         *
         * @param game current {Game} state
         * @param x col position of next bite
         * @param y row position of next bite
         */
        void getMove (Game& game, int& x, int& y);




};

#endif
