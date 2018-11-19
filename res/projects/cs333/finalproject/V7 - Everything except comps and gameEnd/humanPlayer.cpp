#include <iostream>
#include <string>
#include "humanPlayer.h"
#include "game.h"
#include "map.h"
#include <cstdlib>
#include <iostream>

using namespace std;

/**
 *
 */
HumanPlayer::HumanPlayer()
{
    xPoint = 0;
    yPoint = 0;
    xVelocity = 0;
    yVelocity = 0;
    carNumber = 0;
    int gridSpot = 0;
    minSpeed = -5;
    maxSpeed = 5;


}

void HumanPlayer::setXVel(int& x)
{
    xVelocity = x;
}

void HumanPlayer::setYVel(int& y)
{
    yVelocity = y;
}

void HumanPlayer::createLoc(Game& game)
{
    int tofind;
    if (carNumber == 1 )
        tofind = -11;
    else if (carNumber == 2)
        tofind = -12;
    else if (carNumber == 3)
        tofind =-13;
    int spotfound;
    vector<int> aLocation= game.getMap().searchListLocation(tofind );
    for (std::vector<int>::const_iterator i = aLocation.begin(); i != aLocation.end(); ++i)
    {
        //std::cout << *i << " ";
        spotfound = *i;
        gridSpot = *i;
    }
    //cout << spotfound << endl;
    setX(spotfound, game);
    //cout << xPoint << endl;
    setY(spotfound, game);
}

/**
*   Should have been called setCarNum but I didn't want to break my code by changing it.
*
*/

void HumanPlayer::addCarNum(int number)
{
    carNumber = number;
}

bool HumanPlayer::checkLegal(Game& game, int& x, int& y, ostream& out)
{
    int tempSpot;
    int yVar = 0;
    if (y >= -5 && y<= 5)
    yVar = (y+yVelocity)*game.getMap().getCol();
    out << gridSpot << endl;
    /// Check if it goes outside of the map
    tempSpot = gridSpot +xVelocity;
    int yTest =testY(tempSpot, game);
    if (yTest != yPoint)
    {
        out << "Car " << carNumber << " struck a wall";
        return false;
    }
    tempSpot =gridSpot + (xVelocity+x) - yVar ;
    out << tempSpot <<endl;
    if ((x == -1 && y ==0) || (x == 0 && y == 0) || (x ==1 && y==0) || (x == 0 && y == -1) || (x ==0 && y==1))
    {
        int carVar =0;
        if (carNumber == 1)
            carVar = -11;
        if (carNumber == 2)
            carVar = -12;
        if (carNumber == 3)
            carVar =-13;
        cout << "This is the carVar " << carVar << "\n\n";
        if (carVar == -11 )
        {

            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12 && game.getMap().dataSpot(tempSpot) != -13 )
                return true;
            if (game.getMap().dataSpot(tempSpot) == -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) != -13 )
            {
                out << "Car " << carNumber << " struck a wall";
                if (minSpeed > 1)
                minSpeed--;
                if (maxSpeed > 1)
                maxSpeed--;
                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) == -12  ||game.getMap().dataSpot(tempSpot) != -13 )
            {
                out << "Car " << carNumber << " bumbed another car";
                if (minSpeed > 1)
                minSpeed--;
                if (maxSpeed > 1)
                maxSpeed--;
                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) == -13 )
            {
                out << "Car " << carNumber << " bumbed another car";
                if (minSpeed > 1)
                minSpeed--;
                if (maxSpeed > 1)
                maxSpeed--;
                return false;
            }
        }


        else if (carVar == -12)
        {
            cout << "We Have made to the if statements for the -12 car" <<endl;
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -11  && game.getMap().dataSpot(tempSpot) != -13 )
            {
                out << " We can move here no problems" <<endl;
                return true;
            }
            else if (game.getMap().dataSpot(tempSpot) == -1 && game.getMap().dataSpot(tempSpot) != -11  ||game.getMap().dataSpot(tempSpot) != -13 )
            {
                out << "Car " << carNumber << " struck a wall";
                if (minSpeed > 1)
                minSpeed--;
                if (maxSpeed > 1)
                maxSpeed--;
                return false;
            }
            else if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) == -11  ||game.getMap().dataSpot(tempSpot) != -13 )
            {
                out << "Car " << carNumber << " bumbed another car";
                if (minSpeed > 1)
                minSpeed--;
                if (maxSpeed > 1)
                maxSpeed--;
                return false;
            }
            else if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) == -13 )
            {
                out << "Car " << carNumber << " bumbed another car";
                if (minSpeed > 1)
                minSpeed--;
                if (maxSpeed > 1)
                maxSpeed--;
                return false;
            }
        }
        else if (carVar == -13)
        {
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -11  && game.getMap().dataSpot(tempSpot) != -12 )
                return true;
            if (game.getMap().dataSpot(tempSpot) == -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) != -11 )
            {
                out << "Car " << carNumber << " struck a wall";
                if (minSpeed > 1)
                minSpeed--;
                if (maxSpeed > 1)
                maxSpeed--;
                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) == -12  ||game.getMap().dataSpot(tempSpot) != -11 )
            {
                out << "Car " << carNumber << " bumbed another car";
                if (minSpeed > 1)
                minSpeed--;
                if (maxSpeed > 1)
                maxSpeed--;
                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) == -11 )
            {
                out << "Car " << carNumber << " bumbed another car";
                if (minSpeed > 1)
                minSpeed--;
                if (maxSpeed > 1)
                maxSpeed--;
                return false;
            }
        }
    }
    else
    {   out << "Not a legal Velocity" << endl;
        return false;
    }
}


void HumanPlayer::setX(int spot, Game& game)
{
    //cout << "Made it to xTerms" << endl;
    //cout << "We have " << game.getMap().getCol() << " Columns" << endl;
    //cout << "There are " << game.getMap().getRows() << " Rows" << endl;
    int xComparer = 0;
    for (int x =0; x<= game.getMap().getCol(); x++)
    {
        xComparer = x;

        //cout << "The x inside the forloop is XXXXXXXXXXX " << x << endl;
        for (int y=0; y < game.getMap().getRows(); y++)
        {
            //cout << "The Value of Y " << y << endl;
            //cout << "Value we are looking for is " << spot
            //<< "\nxComparer= "
            //<< xComparer << "\n\n";
            if (spot == xComparer)
            {
                //cout << "We have a MATCH!!!\n";
                //cout << x << endl;
                xPoint = x;
                xComparer =xComparer+ game.getMap().getCol();
            }
            else
                xComparer =xComparer+ game.getMap().getCol();

        }

    }
}

void HumanPlayer::setY(int spot, Game& game)
{
    //cout << "In the setY" << endl;
    int yVar= game.getMap().getCol()*game.getMap().getRows();
    for (int x =0; x< game.getMap().getRows(); x++)
    {
        //cout << "The yVar value from inside the first while loop " << yVar << "\n\n";
        for (int y=0; y < game.getMap().getCol(); y++)
        {
            yVar--;
            //cout << "The yVar value from inside the second while loop " << yVar << endl;
            if (spot == yVar)
            {
                //cout << "Found match " << yVar << endl;
                //cout << "We are turning " << x <<endl;
                yPoint = x;
            }
        }

    }


}

int HumanPlayer::testY(int spot, Game& game)
{
    //cout << "In the setY" << endl;
    int yVar= game.getMap().getCol()*game.getMap().getRows();
    for (int x =0; x< game.getMap().getRows(); x++)
    {
        //cout << "The yVar value from inside the first while loop " << yVar << "\n\n";
        for (int y=0; y < game.getMap().getCol(); y++)
        {
            yVar--;
            //cout << "The yVar value from inside the second while loop " << yVar << endl;
            if (spot == yVar)
            {
                //cout << "Found match " << yVar << endl;
                //cout << "We are turning " << x <<endl;
                return x;
            }
        }

    }


}

int HumanPlayer::getX()
{
    return xPoint;
}

int HumanPlayer::getY()
{
    return yPoint;
}

int HumanPlayer::getXVel()
{
    return xVelocity;
}

int HumanPlayer::getYVel()
{
    return yVelocity;
}



void HumanPlayer::makeMove(Game& game, int& x, int& y)
{
    if (xVelocity+x >=minSpeed && x+xVelocity <= maxSpeed)
    {
        xVelocity = xVelocity + x;
    }
    else
    cout << "Car " << carNumber << " can't go that fast" << endl;
    if (yVelocity+y >=minSpeed && yVelocity +y <= maxSpeed)
    {
        yVelocity = yVelocity + y;

    }
    else
    cout << "Car " << carNumber << " can't go that fast";
    //  bool legal = checkLegal(game, xVelocity, yVelocity);
    moveCar(game, xVelocity, yVelocity);

}

void HumanPlayer::isGameOver(Game& game,int x, int y)
{

}

void HumanPlayer::moveCar(Game& game, int& x, int& y)
{
    int localGridLocation = gridSpot;
    int yVar = 0;
    if (y >= -5 && y<= 5)
    yVar = y*game.getMap().getCol();
    gridSpot = gridSpot +x - yVar;
    game.getMap().placeCar(gridSpot, carNumber);

    if (x == 0 && y == 0)
    {
        // simply do nothing
    }
    else
    {
    game.getMap().changeData(localGridLocation,-10);
    game.getMap().correctMap(localGridLocation);
    }

    /**
    if (game.getMap().dataSpot(localGridLocation+1) != -1 && game.getMap().dataSpot(localGridLocation+1) != -11
    && game.getMap().dataSpot(localGridLocation+1) != -12 &&
    game.getMap().dataSpot(localGridLocation+1) != -13)
        game.getMap().addNextNum(gridSpot,game.getMap().dataSpot(gridSpot+1));
    else if (game.getMap().dataSpot(localGridLocation-1) != -1 &&
    game.getMap().dataSpot(localGridLocation-1) != -11 &&
    game.getMap().dataSpot(localGridLocation-1) != -12 &&
    game.getMap().dataSpot(localGridLocation-1) != -13)
        game.getMap().addNextNum(gridSpot,game.getMap().dataSpot(gridSpot-1));
    else if (game.getMap().dataSpot(localGridLocation+game.getMap().getCol()) != -1 &&
     game.getMap().dataSpot(localGridLocation+game.getMap().getCol()) != -11 &&
     game.getMap().dataSpot(localGridLocation+game.getMap().getCol()) != -12 &&
      game.getMap().dataSpot(localGridLocation-1) != -13)
        game.getMap().addNextNum(gridSpot+game.getMap().getCol(),game.getMap().dataSpot(gridSpot+game.getMap().getCol()));
     else if (game.getMap().dataSpot(localGridLocation-game.getMap().getCol()) != -1 &&
     game.getMap().dataSpot(localGridLocation-game.getMap().getCol()) != -11 &&
     game.getMap().dataSpot(localGridLocation-game.getMap().getCol()) != -12 &&
      game.getMap().dataSpot(localGridLocation-game.getMap().getCol()) != -13)
        game.getMap().addNextNum(gridSpot-game.getMap().getCol(),game.getMap().dataSpot(gridSpot-game.getMap().getCol()));
        //*/

}

int HumanPlayer::getMaxSpeed()
{
    return maxSpeed;
}
