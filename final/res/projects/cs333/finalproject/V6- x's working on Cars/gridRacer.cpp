#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "computer1.h"
#include "computer2.h"
#include "humanPlayer.h"
#include "map.h"
#include "game.h"



void playAGame(HumanPlayer& human, Computer1& car1, Computer2& car3, istream& in) {
    Game game;
    game.getMap().createMap(in);

    while (!game.gameEnded()) {
        game.getMap().display (cout);
        game.car1.getlocation(cout);
        game.car2.getlocation(cout);
        game.car3.getlocation(cout);
        //To hold who is going next
        int whoIsNext;
        whoIsNext = game.whoIsNext();
        //Determine who goes next

        int xMove = -1;
        int yMove = -1;
        bool legalMove = false;
        if (whoIsNext == 2)
        {
        while (!legalMove) {
            human.getMove (game, xMove, yMove);
            legalMove = game.moveIsLegal(xMove, yMove);

            if (!legalMove) {
                cout << "Sorry, but that is not a legal move." << endl;
            }

        }
        }
        else if (whoIsNext == 1) {
            // Computer player's move
            game.getMap().display (cout);
            car1.getMove (game, xMove, yMove);
//            game.getMap().makeMove (xMove, yMove);
            }
        else if (whoIsNext == 3) {
            // Computer player's move
            game.getMap().display (cout);
//            car3.getMove (game, xMove, yMove);
//            game.getMap().makeMove (xMove, yMove);
            }
        }
    }




using namespace std;
int main (int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << "Needs course.dat" << endl;
        return -1;
    }
    ifstream mapIn(argv[1]);
    Computer1 car1;
    Computer2 car2;
    HumanPlayer human;
    playAGame(human, car1, car2, mapIn);
    ///----------------------------Delete this after!!!!/////////////////////////////////////////////////////////////////////////////////////////
    /*Game game;
    game.getMap().createMap(mapIn);
    game.getMap().display (cout);
    */
    ///-----------------------------------------------------------------------------------------------------------------------------------------

    mapIn.close();
    return 0;
}
