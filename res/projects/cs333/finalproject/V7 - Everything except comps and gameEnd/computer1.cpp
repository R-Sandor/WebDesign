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
    vector<int> aLocation= game.getMap().searchListLocation(tofind);
    for (std::vector<int>::const_iterator i = aLocation.begin(); i != aLocation.end(); ++i)
        {
          //std::cout << *i << " ";
          spotfound = *i;
        }
        //cout << spotfound << endl;
        setX(spotfound, game);
        //cout << xPoint << endl;
        setY(spotfound, game);
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
/**
 *
 */
void Computer1::getMove(Game& game, int& column, int& row) {

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

void Computer1::addCarNum(int number)
{
    carNumber = number;
}
