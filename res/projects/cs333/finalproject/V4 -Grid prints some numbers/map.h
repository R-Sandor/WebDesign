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
    struct Node
    {
        bool comp1;
        bool humanCar;
        bool comp3;
        bool carInSpot;
        int spot;
        int data;
        Node *next; ///< the next Node in the sequence


    };
    // The default constructor for the map. Takes input from the command line.
    Node *first;

    Map();
    void createMap(std::istream& in);

    void inputMap(std::istream& input);

    void display( std::ostream& out )const;

    void displayWithData( std::ostream& out )const;

    Map& getMap();

    int getCol();

    int getRows();

    void setupData(int data);

    int searchList(int number);

    void addNextNum(Node* addnum,int location);
};


inline
    std::ostream& operator << (std::ostream& out, const Map& m) {
    m.display(out);
    return out;
}
#endif



