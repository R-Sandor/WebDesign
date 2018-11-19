#include <iostream>
#include <string>
#include "computer1.h"
#include "game.h"
#include "map.h"
#include <cstdlib>
#include <iostream>

using namespace std;

/**
 *
 */
Computer1::Computer1()
{
    xPoint = 0;
    yPoint = 0;
    xVelocity = 0;
    yVelocity = 0;
    carNumber = 0;
    int gridSpot = 0;
    minSpeed = -5;
    maxSpeed = 5;
    roundCount = 1;

}

void Computer1::setXVel(int& x)
{
    xVelocity = x;
}

void Computer1::setYVel(int& y)
{
    yVelocity = y;
}

void Computer1::createLoc(Game& game)
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

void Computer1::addCarNum(int number)
{
    carNumber = number;
}

bool Computer1::checkLegal(Game& game, int& x, int& y, ostream& out)
{
    int tempSpot;
    int yVar = 0;
    if (y >= -5 && y<= 5)
        yVar = (y+yVelocity)*game.getMap().getCol();
    //out << gridSpot << endl;
    /// Check if it goes outside of the map
    tempSpot = gridSpot +xVelocity;
    int yTest =testY(tempSpot, game);
    if (yTest != yPoint)
    {
        out << "Car " << carNumber << " struck a wall" <<endl;
        return false;
    }
    tempSpot =gridSpot + (xVelocity+x) + yVar ;
    //out << tempSpot <<endl;
    if ((x == -1 && y ==0) || (x == 0 && y == 0) || (x ==1 && y==0) || (x == 0 && y == -1) || (x ==0 && y==1))
    {
        int carVar =0;
        if (carNumber == 1)
            carVar = -11;
        if (carNumber == 2)
            carVar = -12;
        if (carNumber == 3)
            carVar =-13;
        //cout << "This is the carVar " << carVar << "\n\n";
        if (carVar == -11 )
        {

            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12 && game.getMap().dataSpot(tempSpot) != -13 )
                return true;
            if (game.getMap().dataSpot(tempSpot) == -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) != -13 )
            {
                out << "Car " << carNumber << " struck a wall" << endl;
                if (minSpeed > 1)
                    minSpeed--;
                if (maxSpeed > 1)
                    maxSpeed--;
                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) == -12  ||game.getMap().dataSpot(tempSpot) != -13 )
            {
                out << "Car " << carNumber << " bumbed another car" << endl;
                if (minSpeed > 1)
                    minSpeed--;
                if (maxSpeed > 1)
                    maxSpeed--;
                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) == -13 )
            {
                out << "Car " << carNumber << " bumbed another car"<<endl;
                if (minSpeed > 1)
                    minSpeed--;
                if (maxSpeed > 1)
                    maxSpeed--;
                return false;
            }
        }


        else if (carVar == -12)
        {
            //cout << "We Have made to the if statements for the -12 car" <<endl;
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -11  && game.getMap().dataSpot(tempSpot) != -13 )
            {
                //out << " We can move here no problems" <<endl;
                return true;
            }
            else if (game.getMap().dataSpot(tempSpot) == -1 && game.getMap().dataSpot(tempSpot) != -11  ||game.getMap().dataSpot(tempSpot) != -13 )
            {
                out << "Car " << carNumber << " struck a wall" <<endl;
                if (minSpeed > 1)
                    minSpeed--;
                if (maxSpeed > 1)
                    maxSpeed--;
                return false;
            }
            else if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) == -11  ||game.getMap().dataSpot(tempSpot) != -13 )
            {
                out << "Car " << carNumber << " bumbed another car"<<endl;
                if (minSpeed > 1)
                    minSpeed--;
                if (maxSpeed > 1)
                    maxSpeed--;
                return false;
            }
            else if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) == -13 )
            {
                out << "Car " << carNumber << " bumbed another car" << endl;
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
                out << "Car " << carNumber << " struck a wall"<< endl;
                if (minSpeed > 1)
                    minSpeed--;
                if (maxSpeed > 1)
                    maxSpeed--;
                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) == -12  ||game.getMap().dataSpot(tempSpot) != -11 )
            {
                out << "Car " << carNumber << " bumbed another car"<< endl;
                if (minSpeed > 1)
                    minSpeed--;
                if (maxSpeed > 1)
                    maxSpeed--;
                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) == -11 )
            {
                out << "Car " << carNumber << " bumbed another car"<< endl;
                if (minSpeed > 1)
                    minSpeed--;
                if (maxSpeed > 1)
                    maxSpeed--;
                return false;
            }
        }
    }
    else
    {
        out << "Not a legal Velocity" << endl;
        return false;
    }
}

bool Computer1::checkLegalComp(Game& game, int x, int y)
{
    int tempSpot;
    int yVar = 0;
    if (y >= -5 && y<= 5)
        yVar = (y+yVelocity)*game.getMap().getCol();
    //out << gridSpot << endl;
    /// Check if it goes outside of the map
    tempSpot = gridSpot +xVelocity;
    int yTest =testY(tempSpot, game);
    if (yTest != yPoint)
    {
        return false;
    }
    tempSpot =gridSpot + (xVelocity+x) + yVar ;
    //out << tempSpot <<endl;
    if ((x == -1 && y ==0) || (x == 0 && y == 0) || (x ==1 && y==0) || (x == 0 && y == -1) || (x ==0 && y==1))
    {
        int carVar =0;
        if (carNumber == 1)
            carVar = -11;
        if (carNumber == 2)
            carVar = -12;
        if (carNumber == 3)
            carVar =-13;
        //cout << "This is the carVar " << carVar << "\n\n";
        if (carVar == -11 )
        {

            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12 && game.getMap().dataSpot(tempSpot) != -13  )

                return true;
            if (game.getMap().dataSpot(tempSpot) == -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) != -13 )
            {

                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) == -12  ||game.getMap().dataSpot(tempSpot) != -13  )
            {

                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) == -13 )

            {

                return false;
            }
        }


        else if (carVar == -12)
        {
            //cout << "We Have made to the if statements for the -12 car" <<endl;
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -11  && game.getMap().dataSpot(tempSpot) != -13 )
            {
                //out << " We can move here no problems" <<endl;
                return true;
            }
            else if (game.getMap().dataSpot(tempSpot) == -1 && game.getMap().dataSpot(tempSpot) != -11  ||game.getMap().dataSpot(tempSpot) != -13 )
            {

                return false;
            }
            else if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) == -11  ||game.getMap().dataSpot(tempSpot) != -13 )
            {

                return false;
            }
            else if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) == -13 )
            {

                return false;
            }
        }
        else if (carVar == -13 )
        {

            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12 && game.getMap().dataSpot(tempSpot) != -13 )

                return true;
            if (game.getMap().dataSpot(tempSpot) == -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) != -13)
            {

                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) == -12  ||game.getMap().dataSpot(tempSpot) != -13  )
            {

                return false;
            }
            if (game.getMap().dataSpot(tempSpot) != -1 && game.getMap().dataSpot(tempSpot) != -12  ||game.getMap().dataSpot(tempSpot) == -13  )

            {

                return false;
            }
        }
        return false;
    }
}

void Computer1::setX(int spot, Game& game)
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

void Computer1::setY(int spot, Game& game)
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

int Computer1::testY(int spot, Game& game)
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

int Computer1::getX()
{
    return xPoint;
}

int Computer1::getY()
{
    return yPoint;
}

int Computer1::getXVel()
{
    return xVelocity;
}

int Computer1::getYVel()
{
    return yVelocity;
}

int Computer1::getGridSpot()
{
    return gridSpot;
}


void Computer1::makeMove(Game& game, int& x, int& y)
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


void Computer1::getMove(Game& game)
{

    if (carNumber == 1)
    {
        bool legalMove;
        int xMove, yMove;

        xMove =1;
        yMove= 0;
        game.getMap().changeData(gridSpot, 100);

        if (!checkLegalComp(game, xMove, yMove) && possibleMove(game, xMove, yMove) <= game.getMap().dataSpot(gridSpot) )
        {
            xMove = 0;
            yMove = 1;
        }
        if (!checkLegalComp(game, xMove, yMove) && possibleMove(game, xMove, yMove) <= game.getMap().dataSpot(gridSpot) )
        {
            xMove = 0;
            yMove = -1;
        }
        if (!checkLegalComp(game, xMove, yMove) && possibleMove(game, xMove, yMove) <= game.getMap().dataSpot(gridSpot) )
        {
            xMove = -1;
            yMove = 0;
        }
        legalMove = checkLegal(game, xMove, yMove, cout);
        //  cout << " The status of legal move " << legalMove << endl;
        if (!legalMove)
        {
            xMove = 0;
            yMove = 0;
            setXVel(xMove);
            setYVel(yMove);
            makeMove(game, xMove,yMove);
        }
        else
        {
            cout << "Desired Change in velocity: " << xMove << " " << yMove << endl;
            makeMove(game, xMove, yMove);
            // game.getMap().display(cout);
        }
    }

    if (carNumber == 3)
    {
        cout << "in car three" << endl;
        bool legalMove;
        int xMove, yMove;
        roundCount++;
        if ( roundCount % 3 == 1)
        {
            cout << "2 % roundCount =  " << roundCount % 2 <<endl;
            xMove = -1;
            yMove = 0;
        }
        else
        {
        xMove=1;
        yMove= 0;
        }
        game.getMap().changeData(gridSpot, 101);

        if (!checkLegalComp(game, xMove, yMove) && possibleMove(game, xMove, yMove) < game.getMap().dataSpot(gridSpot) )
        {
            xMove = 0;
            yMove = 1;
        }
        if (!checkLegalComp(game, xMove, yMove) && possibleMove(game, xMove, yMove) < game.getMap().dataSpot(gridSpot) )
        {
            xMove = 0;
            yMove = -1;
        }
        if (!checkLegalComp(game, xMove, yMove) && possibleMove(game, xMove, yMove) < game.getMap().dataSpot(gridSpot) )
        {
            xMove = -1;
            yMove = 0;
        }
        legalMove = checkLegal(game, xMove, yMove, cout);
        //  cout << " The status of legal move " << legalMove << endl;
        if (!legalMove)
        {
            xMove = 0;
            yMove = 0;
            setXVel(xMove);
            setYVel(yMove);
            makeMove(game, xMove,yMove);
        }
        else
        {
            cout << "Desired Change in velocity: " << xMove << " " << yMove << endl;
            makeMove(game, xMove, yMove);
            // game.getMap().display(cout);
        }
    }

}


int  Computer1::possibleMove(Game& game, int x, int y)
{
    int localGridLocation = gridSpot;
    int yVar = 0;
    if (y >= -5 && y<= 5)
        yVar = y*game.getMap().getCol();
    int testSpot = gridSpot +x - yVar +xVelocity+yVelocity;
    return game.getMap().dataSpot(testSpot);


}


void Computer1::moveCar(Game& game, int x, int y)
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


}

int Computer1::getMaxSpeed()
{
    return maxSpeed;
}
