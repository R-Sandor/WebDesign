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
    myMap = new int [columns*rows];

    inputMap(in);
}


Map::Map()
{

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



    // x is a counter for the spot
    int x = 0;
    int spot;
    //while there is still input we are goint to save values to the
    // grid nodes.
    while (in)
    {

        string str;
        getline (in,str);
        int z = 0;
        while (z< str.length())
        {
            int data;
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

                data = -11;

            }
            if (str.at(z)== '2')
            {
                data = -12;

            }
            if (str.at(z)== '3')
            {
                data = -13;
            }
            if (str.at(z)== 'F')
            {
                cout << "Finish line" <<endl;
                data =0;
            }
            cout << "Line 74: square number: " << x << endl;
            myMap[x] = data;
            z++;
            x++;
        }
    }
    findNum = 0;
    setupData();
}




void Map::display( std::ostream& out ) const
{
    int i = 0;
    while (i < columns*rows)
    {

        for (int z=0; z < columns; z++)
        {

            if (myMap[i] == -1)
                out<< "*";

            if (myMap[i] == 0)
                out <<"F";
            if (myMap[i] == -10)
                out<< " ";
            if (myMap[i] == -11)
                out<< "1";
            if (myMap[i] == -12)
                out<< "2";
            if (myMap[i] == -13)
                out<< "3";
            i++;

        }
        cout << endl;
    }
}

void Map::displayWithData( std::ostream& out ) const
{
    int i = 0;
    while (i < columns*rows)
    {

        for (int z=0; z < columns; z++)
        {

            if (myMap[i] == -1)
                out<< "*";

            if (myMap[i] == 0)
                out <<"F";
            if (myMap[i] == 1)
                out <<"1";
            if (myMap[i] == 2)
                out <<"2";
            if (myMap[i] == 3)
                out <<"3";
            if (myMap[i] == 4)
                out <<"4";
            if (myMap[i] == 5)
                out <<"5";
            if (myMap[i] == 6)
                out <<"6";
            if (myMap[i] == -10)
                out<< " ";
            if (myMap[i] == -11)
                out<< "1";
            if (myMap[i] == -12)
                out<< "2";
            if (myMap[i] == -13)
                out<< "3";
            i++;

        }
        cout << endl;
    }
}


int Map::getCol()
{
    return columns;
}

void Map::setupData()
{
    // F stands for a finish line spot
    if (searchList(findNum) == true)
    {

        cout << searchList(findNum) << " = is found number" << endl;
        displayWithData(cout);
        findNum++;
        setupData();
    }
    else
    {
        cout << "data is setup" << endl;
    }
}


bool Map::searchList(int number)
{
    int index = 0;
    bool found = false;

    while(index < rows*columns && !found)
    {
        myMap[index];
        if (myMap[index] == number)
        {
            found =true;
            return true;


        }
        else
        index++;
    }
    return false;
}

/*
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
        for(int i =0; i < (columns+location-1);i++)
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
        for(int i =0; i < (location-columns+1);i++)
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
*/
