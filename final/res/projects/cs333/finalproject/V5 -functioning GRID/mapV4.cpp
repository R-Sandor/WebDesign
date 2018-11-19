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
            if (myMap[i] != -1 && myMap[i] != 0 && myMap[i] != -10 && myMap[i] != -11 && myMap[i] !=-12 && myMap[i] !=-13)
                out<< " ";


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
                out <<"0";
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
            if (myMap[i] == 7)
                out <<"7";
            if (myMap[i] == 8)
                out <<"8";
            if (myMap[i] == 9)
                out <<"9";
            if (myMap[i] == 10)
                out <<"0";
            if (myMap[i] == 11)
                out <<"1";
            if (myMap[i] == 12)
                out <<"2";
            if (myMap[i] == 13)
                out <<"3";
            if (myMap[i] == 14)
                out<< "4";
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
        vector<int> locations;
        cout << searchList(findNum) << " = is found number" << endl;
        locations = searchListLocation(findNum);
        for (std::vector<int>::const_iterator i = locations.begin(); i != locations.end(); ++i)
        {
            std::cout << *i << " ";
            addNextNum(*i, findNum+1);

        }
        cout << endl;
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

vector<int> Map::searchListLocation(int number)
{
    vector<int> foundDataAt;
    int index = 0;
    while(index < rows*columns)
    {
        myMap[index];
        if (myMap[index] == number)
        {
            foundDataAt.push_back(index);

        }


        index++;
    }
    return foundDataAt;
}



void Map::addNextNum( int location, int data )
{

    /// Setup left data

    if (myMap[location-1] == -10)
    {
        myMap[location-1] =  data;
        cout << "The data of spot: " << location - 1 << " is now equal to: " << myMap[location-1] << endl;
    }


    ///Setup data for right
    if (myMap[location+1] ==-10)
    {
        cout << "The data of spot: " << location +1 << " is before we do anything: " << myMap[location+1] << endl;
        myMap[location+1] = 1;
        cout << "The data of spot: " << location+1 << " is now equal to: " << myMap[location+1]<< endl;
    }

    /// Setup data for diagnols

    // Down Diagnol
    //myMap[columns+location-1]
    cout << "DOWNLEFT Diagnol of:" << location <<endl;
    cout << "DOWNLEFT Diagnol is " << location+columns-1 << endl;

    if (myMap[columns+location-1] == -10)
    {

        myMap[columns+location-1] = data;
        cout << "The data of spot: " << columns+location-1 << " is now equal to: " <<  myMap[columns+location-1] << endl;
    }
    // Right Diagnol
    cout << "DownRIGHTDiagnol of:" << location <<endl;
    cout << "The DOWN RIGHT diagnol is " << columns+location+1 << endl;

    if ( myMap[columns+location+1] == -10)
    {

        myMap[columns+location+1]= data;
        cout << "The data of spot: " << columns+location+1 << " is now equal to: " << myMap[columns+location+1] << endl;
    }

    // Upright Diagnol

    cout << "UPLEFT DIAGNOL of:" << location <<endl;
    cout << "UPLEFT diagnol is " << location-1-columns << endl;

    if (myMap[location-1-columns] == -10)
    {

        myMap[location-1-columns] = data;
        cout << "The data of spot: " << location-1-columns << " is now equal to: " << myMap[location-1-columns] << endl;
    }

    /// Upright Diagnol
    cout << "UPRdiagnol of:" << location <<endl;
    cout << "The UPRIGHT Diagnol is " << location+1-columns << endl;

    if (  myMap[location+1-columns] == -10)
    {
        myMap[location+1-columns] = data;
        cout << "The data of spot: " << location+1-columns << " is now equal to: " << myMap[location+1-columns] << endl;
    }

    /// Down data setup
    cout << "DOWN of :" << location<<endl;
    cout << "The DOWN is " << columns+location-1 << endl;
    if (myMap[columns+location-1] == -10)
    {
        myMap[columns+location-1] = data;
        cout << "The data of spot: " << columns+location-1<< " is now equal to: " <<myMap[columns+location-1]<< endl;
    }

    // up data setup

    cout << "find UP of:" << location <<endl;
    cout << "The UP is " << location-columns+1<< endl;
    if (myMap[location-columns+1] == -10)
    {

        myMap[location-columns+1] = data;
        cout << "THE DATA OF UP IS " << location-columns+1 << " is now equal to: " << myMap[location-columns+1] << endl;
    }


}
