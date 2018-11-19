#ifndef COMPUTER1_H
#define COMPUTER1_H

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

        bool checkLegal(Game&, int& xMove, int& yMove, ostream& out);

        bool checkLegalComp(Game&, int xMove, int yMove);

        void setX(int spot, Game& theGame);

        void setY(int someNumber, Game& theGame);

        int testY(int spot, Game& game);

        void setXVel(int& x);

        void setYVel(int& y);

        int getX();

        int getY();

        int getXVel();

        int getYVel();

        int getGridSpot();

        int getMaxSpeed();

        void getMove(Game& game);

        int  possibleMove(Game& game, int x, int y);

        void isGameOver(Game& game,int x, int y);

        void moveCar(Game& game, int x, int y);


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
        int firstMove;
        int roundCount;

};
#endif
