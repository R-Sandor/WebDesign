#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "computer1.h"
//#include "computer3.h"
#include "humanPlayer.h"
#include "map.h"
#include "game.h"

using namespace std;



void playAGame( Computer1& car1, HumanPlayer& car2, Computer1& car3, istream& in)
{
    Game game;
    game.getMap().createMap(in);
    car1.addCarNum(1);
    car2.addCarNum(2);
    car3.addCarNum(3);

    //game.getMap().display (cout);
    car1.createLoc(game);
    car2.createLoc(game);
    car3.createLoc(game);

    while (!game.gameEnded())
    {
        car1.createLoc(game);
        car2.createLoc(game);
        car3.createLoc(game);
        game.getMap().display(cout);
        game.getMap().displayWithData(cout);

        //To hold who is going next
        int whoIsNext;
        whoIsNext = game.whoIsNext();
        //Determine who goes next

        int xMove = 0;
        int yMove = 0;
        bool legalMove = false;
        if (whoIsNext == 2)
        {
                cout << "2: (" << car2.getX() << "," << car2.getY() << ") (" << car2.getXVel() << "," << car2.getYVel()<< ")"<< endl;

                cin >> xMove >> yMove;
                legalMove = car2.checkLegal(game, xMove, yMove, cout);
                cout << " The status of legal move " << legalMove << endl;
                if (!legalMove)
                {
                    xMove = 0;
                    yMove = 0;
                    car2.setXVel(xMove);
                    car2.setYVel(yMove);
                    car2.makeMove(game, xMove,yMove);
                    legalMove = true;
                }
                else
                {
                    cout << "Desired Change in velocity: " << xMove << " " << yMove << endl;
                    car2.makeMove(game, xMove, yMove);
                }


        }
        else if (whoIsNext == 1)
        {
            cout << "1: (" << car1.getX() << "," << car1.getY() << ") (" << car1.getXVel() << "," << car1.getYVel()<< ")"<< endl;
            cout << "2: (" << car2.getX() << "," << car2.getY() << ") (" << car2.getXVel() << "," << car2.getYVel()<< ")"<< endl;
            cout << "3: (" << car3.getX() << "," << car3.getY() << ") (" << car3.getXVel() << "," << car3.getYVel()<< ")"<< endl;
            // Computer player's move
            //   game.getMap().display (cout);
            car1.getMove (game, xMove, yMove);
//            game.getMap().makeMove (xMove, yMove);
        }
        else if (whoIsNext == 3)
        {
            cout << "1: (" << car1.getX() << "," << car1.getY() << ") (" << car1.getXVel() << "," << car1.getYVel()<< ")"<< endl;
            cout << "2: (" << car2.getX() << "," << car2.getY() << ") (" << car2.getXVel() << "," << car2.getYVel()<< ")"<< endl;
            cout << "3: (" << car3.getX() << "," << car3.getY() << ") (" << car3.getXVel() << "," << car3.getYVel()<< ")"<< endl;
            // Computer player's move
            //    game.getMap().display (cout);
//            car3.getMove (game, xMove, yMove);
//            game.getMap().makeMove (xMove, yMove);
        }
    }
}




int main (int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << "Needs course.dat" << endl;
        return -1;
    }
    ifstream mapIn(argv[1]);

    Computer1 car1;
    HumanPlayer car2;
    Computer1 car3;
    playAGame(car1, car2, car3, mapIn);
    ///----------------------------Delete this after!!!!/////////////////////////////////////////////////////////////////////////////////////////
    /*
    Game game;
    game.getMap().createMap(mapIn);
    game.getMap().display (cout);
    car1.createLoc(game);
    */
    ///-----------------------------------------------------------------------------------------------------------------------------------------

    mapIn.close();
    return 0;
}
