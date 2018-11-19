#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
//#include "computer1.h"
//#include "computer2.h"
//#include "humanPlayer.h"
#include "map.h"
#include "game.h"
using namespace std;
int main (int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << "Needs course.dat" << endl;
        return -1;
    }
    ifstream mapIn(argv[1]);
//    Computer1 car1;
  //  Computer2 car2;
//    HumanPlayer human;
    //playAGame(human, car1, car2, mapIn);

    ///----------------------------Delete this after!!!!/////////////////////////////////////////////////////////////////////////////////////////
    Game game;
    cout << game.getMap().getCol() << endl;
    game.getMap().createMap(mapIn);
    cout << game.getMap().getCol() << endl;
    game.getMap().display(cout);


    mapIn.close();
    return 0;
}
