#include "map.h"
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


int main (int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << "Needs course.dat" << endl;
        return -1;
    }
    ifstream mapIn(argv[1]);
    Map myMap(mapIn);
    myMap.initMapVal(mapIn);
    cout << myMap;
    myMap.getMap();



    bool winner;
    winner = false;
    //while (winner != true)
    //{

    //}

    mapIn.close();
    return 0;
}


