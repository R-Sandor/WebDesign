#ifndef MAP_H
#define MAP_H
#include<vector>
#include <iostream>

/**
This is the map class that is responsible for the map of the game
**/
using namespace std;

class Map
{
private:
    int columns;
    int rows;
public:
    int findNum;

    int *myMap;
    Map();
    void createMap(std::istream& in);

    void inputMap(std::istream& input);

    void display( std::ostream& out )const;

    void displayWithData( std::ostream& out )const;

    void addNextNum( int location, int somedata );

    Map& getMap();

    int getCol();

    int getRows();

    void setupData();

    vector<int> searchListLocation(int number);

    bool searchList(int number);

    int dataSpot(int spot);

    void placeCar(int loc, int theCarNumber);

    void correctMap( int location);

    void changeData(int spot, int data);

};


inline
std::ostream& operator << (std::ostream& out, const Map& m)
{
    m.display(out);
    return out;
}
#endif



