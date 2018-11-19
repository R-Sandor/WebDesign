#ifndef COMPUTER3_H
#define COMPUTERP3_H

#include <string>

#include "game.h"

/**
 * This class represents the structure of a single ComputerPlayer.
 * This includes both the interface (public and private) and
 * attributes (private member data).
 */
class Computer3 {
    public:
        /**
         * Construct a new {CoumpterPlayer}.
         */
        Computer3();

        /**
         * Get the computer player's next move for this game.
         * "Return" the move as location x,y of next bite.
         *
         * @param game current {Game} state
         * @param x col position
         * @param y row position
         */
        void getMove (Game& game, int& x, int& y);


    private:
        int xPoint;
        int yPoint;

};

#endif
