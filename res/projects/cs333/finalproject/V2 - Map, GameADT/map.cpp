#include "map.h"
#include "car.h"
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "dllistUtils.h"

using namespace std;
void Map::manipulateMap(istream& in)
{
    // Takes input for the course.dat and then uses it to construct the map.
    int i = 0;
    while (in)
    {
        string str;
        getline (in,str);
        if (i == 0)
        {
            columns = str.length();
        }
        i++;
    }

    rows = i-1;

    first = NULL;

    initMapVal(in);
}
Map::Map()
{
    first = NULL;

    columns = 0;
    rows = 0;

}

/**
This function is responsible for initializing the value of the map
by placing the in a linked list.
*/

void Map::initMapVal(istream& in)
{
    // Reset the input
    in.clear();
    in.seekg(0, in.beg);


    // Create a new node
    Node *myCube;
    myCube = new Node;

    // x is a counter for the spot
    int x = 0;

    //while there is still input we are goint to save values to the
    // grid nodes.
    while (in)
    {
    int z = 0;
    string str;
    getline (in,str);
    while (z < str.length())
        {
            bool isCompCar1;
            bool isCompCar3;
            myCube = new Node;
            bool isCar;
            int data;
            int spt = x+z;
            if (str.at(z) == ' ')
            {
                data = -10;
                cout << data << endl;
            }
            if (str.at(z)== '*')
            {
                data = -1;
                cout << "From with in the the if ** statement : " << data << endl;

            }
            if (str.at(z)== '1')
            {
                isCompCar1 = true;
                int numCar = 1;
                isCar = true;
                data = -11;
                myCube->carInSpot = isCar;
                myCube->comp1= isCompCar1;

            }
             if (str.at(z)== '2')
            {
                isCar = true;
                data = -12;
                myCube->carInSpot=isCar;

            }
             if (str.at(z)== '3')
            {
                isCar = true;
                data = -13;
                myCube->carInSpot= isCar;
                myCube->comp3 = isCar;
            }
            if (str.at(z)== 'F')
            {
                cout << "Finish line" <<endl;
                data =0;
            }
            cout << "Line 69" << endl;
            myCube->data= data;
            myCube->spot = spt;
            myCube->next = NULL;
            cout << "Line 74: myCube->spot;";
            cout << myCube->spot << endl << endl;

            if( first == NULL ){
               first = myCube;

            }
            else
            {
            // Move to last node
            Node* current = first;
            while (current->next != NULL)
            current = current->next;

            //Link after that node
            current->next = myCube;
            }
            z++;

            }
            x = x+z;
    }
    setupData();

}

void Map::display( std::ostream& out ) const
{
   Node *it = first; // List iterator
    while (it != NULL)
    {
        for (int z=0; z < columns;z++)
        {

        if (it->data == -1)
        out<< "*";

        if (it->data == -10)
        out<< " ";

        if (it->data == -11)
        out <<"1";
        if (it->data == -12)
        out <<"2";
        if (it->data == -13)
        out <<"3";
        if (it->data == 0)
        out <<"F";
        it = it->next;

        }
        out << endl;
    }
}



int Map::getCol()
{
    return columns;
}

void Map::setupData()
{
    // F stands for a finish line spot
    int findF =0;
    findF = searchList(findF);
    cout << "\n\n" << "Searching the list: " << findF << endl;

}

int Map::searchList(int number)
{
    Node* current;
    bool found = false;
    current =first;

    while(current != NULL && !found)
      if (current->data == number)
      {
        found =true;

    }
      else
        current = current->next;

    return current->spot;
}
