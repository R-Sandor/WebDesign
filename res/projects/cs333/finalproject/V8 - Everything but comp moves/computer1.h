#ifndef COMPUTERP1_H
#define COMPUTERP1_H

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
         * Construct a new {CoumpterPlayer}.
         */
        Computer1();

        void addCarNum(int number);

        void createLoc(Game& game);

        /**
         * Get the computer player's next move for this game.
         * "Return" the move as location x,y of next bite.
         *
         * @param game current {Game} state
         * @param x col position
         * @param y row position
         */
        void getMove (Game& game, int& x, int& y);

        void setX(int spot, Game& theGame);

        void setY(int someNumber, Game& theGame);

        int getX();

        int getY();

        int getXVel();

        int getYVel();


    private:
        int xPoint;
        int yPoint;
        int xVelocity;
        int yVelocity;
        int carNumber;

};
#endif
