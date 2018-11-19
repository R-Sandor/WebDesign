#ifndef MAP_H
#define MAP_H
#include <iostream>

/**
This is the map class that is responsible for the map of the game
**/


class Map {
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

    Map& getMap();

    int getCol();

    int getRows();

    void setupData();

    int searchListLocation(int number);

    bool searchList(int number);


};


inline
    std::ostream& operator << (std::ostream& out, const Map& m) {
    m.display(out);
    return out;
}
#endif



