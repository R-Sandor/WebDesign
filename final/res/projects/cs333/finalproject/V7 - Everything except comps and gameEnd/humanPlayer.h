#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <string>

#include "game.h"

/**
 * This class represents the structure of a single ComputerPlayer.
 * This includes both the interface (public and private) and
 * attributes (private member data).
 */
class HumanPlayer {
    public:
        /**
         * Construct a new {CoumpterPlayer}.
         */
        HumanPlayer();

        void addCarNum(int number);

        void createLoc(Game& game);

        bool checkLegal(Game&, int& xMove, int& yMove, ostream& out);

        void setX(int spot, Game& theGame);

        void setY(int someNumber, Game& theGame);

        int testY(int spot, Game& game);

        void setXVel(int& x);

        void setYVel(int& y);

        int getX();

        int getY();

        int getXVel();

        int getYVel();

        int getMaxSpeed();

        void isGameOver(Game& game,int x, int y);

        void moveCar(Game& game, int& x, int& y);

        void makeMove(Game& game, int& x, int& y);
    private:
        int xPoint;
        int yPoint;
        int xVelocity;
        int yVelocity;
        int carNumber;
        int gridSpot;
        int maxSpeed;
        int minSpeed;

};
#endif
