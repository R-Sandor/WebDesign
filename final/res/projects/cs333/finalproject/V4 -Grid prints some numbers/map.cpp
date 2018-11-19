#include "map.h"
#include "car.h"
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "dllistUtils.h"

using namespace std;

void Map::createMap(istream& in)
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

    inputMap(in);
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

void Map::inputMap(istream& in)
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
            bool humanCar;
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
                isCar =true;
                myCube->carInSpot = isCar;
                humanCar = true;
                data = -12;
                myCube->humanCar = humanCar;

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
    // place to hold a data variable we are about to search for
    int data =0;
    /// This will call a recurisive set of functions
    /// That will call themselves to establish the grid numbers.
   // for (int data = 0; data < columns; data++)
    setupData(data );

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

        if (it->comp1 == true)
        out <<"1";
        if (it->humanCar == true)
        out <<"2";
        if (it->comp3 == true)
        out <<"3";

        if (it->data == 0)
        out <<"F";
        if (it->data != -1 && it->data != 0 && it->carInSpot != true)
        out<< " ";

        it = it->next;

        }
        out << endl;
    }
}

void Map::displayWithData( std::ostream& out ) const
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

        if (it->comp1 == true)
        out <<"1";
        if (it->humanCar == true)
        out <<"2";
        if (it->comp3 == true)
        out <<"3";
        if (it->data == 0)
        out <<"0";
        if (it->data == 1)
        out<< "1";

        if (it->data == 2)
        out<< "2";
        if (it->data == 3)
        out<< "3";

        if (it->data == 4)
        out<< "4";
         if (it->data == 5)
        out<< "5";
         if (it->data == 6)
        out<< "6";
        it = it->next;

        }
        out << endl;
    }
}


int Map::getCol()
{
    return columns;
}

void Map::setupData(int data)
{
    // F stands for a finish line spot
    int findF;
    findF = searchList(data);
    cout << "\n\n" << "Searching the list: " << findF << endl;
    Node* current;
    current = first;
    for (int i=0; i< findF;  i++)
    {
        current = current->next;
    }
    addNextNum(current, findF);

    cout << "\n\n\n\n";
    cout << "This is the Current spot: " <<  current->spot<< endl;
    cout << "The current nodes data is :" << current->data<< endl;
    cout << "The next nodes data :" << current->next->data <<endl;
    current->data = data;
    while (current->data == current->next->data)
    {
        findF++;
        current->next->data = data;
        current =  current->next;
        addNextNum(current, findF);
    }
    displayWithData(cout);


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


void Map::addNextNum(Node* to_countFrom, int location )
{

    /// Setup left data
    Node *leftCube = first;
    for(int i =0; i < location-1;i++)
    {
        leftCube = leftCube->next;
    }
    if (leftCube->data == -10)
        {
            leftCube->data = to_countFrom->data +1;
            cout << "The data of spot: " << leftCube->spot << " is now equal to: " << leftCube->data << endl;
        }


    ///Setup data for right
    if (to_countFrom->next->data ==-10)
    {
        cout << "The data of spot: " << to_countFrom->spot << " is before we do anything: " << to_countFrom->next->data << endl;
        to_countFrom->next->data = to_countFrom->data +1;
        cout << "The data of spot: " << to_countFrom->spot << " is now equal to: " << to_countFrom->data << endl;
    }

    /// Setup data for diagnols

    // Down Diagnol
    Node* downLDiagnol = first;
    for(int i =0; i < (columns+location-1);i++)
        downLDiagnol = downLDiagnol->next;
        cout << "DOWNLEFT Diagnol of:" << to_countFrom->spot <<endl;
        cout << "DOWNLEFT Diagnol is " << downLDiagnol->spot << endl;

        if (downLDiagnol->data == -10)
        {

            downLDiagnol->data = to_countFrom->data +1;
            cout << "The data of spot: " << downLDiagnol->spot << " is now equal to: " << downLDiagnol->data << endl;
        }
    // Right Diagnol
    Node* downRDiagnol = first;
    for(int i =0; i < (columns+location+1);i++)
        downRDiagnol = downRDiagnol->next;
        cout << "DownRIGHTDiagnol of:" << to_countFrom->spot <<endl;
        cout << "The DOWN RIGHT diagnol is " << downRDiagnol->spot << endl;

        if (downRDiagnol->data == -10)
        {

            downRDiagnol->data = to_countFrom->data +1;
            cout << "The data of spot: " << downRDiagnol->spot << " is now equal to: " << downRDiagnol->data << endl;
        }

          // Upright Diagnol
    Node* upLDiagnol = first;
    for(int i =0; i < (location-1-columns);i++)
        upLDiagnol = upLDiagnol->next;
        cout << "UPLEFT DIAGNOL of:" << to_countFrom->spot <<endl;
        cout << "UPLEFT diagnol is " << upLDiagnol->spot << endl;

        if (upLDiagnol->data == -10)
        {

            upLDiagnol->data = to_countFrom->data +1;
            cout << "The data of spot: " << upLDiagnol->spot << " is now equal to: " << upLDiagnol->data << endl;
        }

        // Upright Diagnol
    Node* upRDiagnol = first;
    for(int i =0; i < (location+1-columns);i++)
        upRDiagnol = upRDiagnol->next;
        cout << "UPRdiagnol of:" << to_countFrom->spot <<endl;
        cout << "The UPRIGHT Diagnol is " << upRDiagnol->spot << endl;

        if (upRDiagnol->data == -10)
        {
            upRDiagnol->data = to_countFrom->data +1;
            cout << "The data of spot: " << upRDiagnol->spot << " is now equal to: " << upRDiagnol->data << endl;
        }

    // Down data setup
    Node* down = first;
        for(int i =0; i < (columns+location);i++)
            down = down->next;
         cout << "DOWN of :" << to_countFrom->spot <<endl;
        cout << "The DOWN is " << down->spot << endl;
        if (down->data == -10)
        {
            down->data = to_countFrom->data +1;
            cout << "The data of spot: " << down->spot << " is now equal to: " << down->data << endl;
        }

    // up data setup
    Node* up = first;
        for(int i =0; i <= (location-columns);i++)
        up = up->next;
        cout << up->spot << endl;
        cout << "find UP of:" << to_countFrom->spot <<endl;
        cout << "The UP is " << up->spot << endl;
        if (up->data == -10)
        {

            up->data = to_countFrom->data +1;
            cout << "THE DATA OF UP IS " << up->spot << " is now equal to: " << up->data << endl;
        }


}
