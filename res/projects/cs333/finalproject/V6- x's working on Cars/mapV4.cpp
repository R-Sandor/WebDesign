#include "map.h"
#include "car.h"
#include <cctype>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "dllistUtils.h"

using namespace std;

/**
*   This function calls the the map from the command line
*   and sends it to where the it will be read line by line
*   It also creates the size of the map.
*/

void Map::createMap(istream& in)
{
    // Takes input for the course from the command line in a file and then uses it to construct the map.
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


/**
*   Basic defualt constructor
*/

Map::Map()
{

    columns = 0;
    rows = 0;

}

/**
*   This function does all the work of reading each character and assigning it
*   a value in the array.
*/

void Map::inputMap(istream& in)
{
    // Reset the input
    in.clear();
    in.seekg(0, in.beg);



    // k is a counter each individaul cube in a grid.
    int k = 0;

    //while there is still input we are goind to save values to the
    // myMap array
    while (in)
    {

        string str;
        getline (in,str);
        // This intentional resets z which will reset
        // after the width of the map has been read in.
        int z = 0;
        while (z< str.length())
        {
            int data;
            if (str.at(z) == ' ')
            {
                data = -10;
                //cout << data << endl;
            }
            if (str.at(z)== 'X')
            {
                data = -1;
                //cout << "From with in the the if ** statement : " << data << endl;
            }
            if (str.at(z) == 'x')
                data = -1;
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
             //   cout << "Finish line" <<endl;
                data =0;
            }
            // cout << "Line 74: square number: " << k << endl;
            myMap[k] = data;
            z++;
            k++;
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
                out<< "X";
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


/********************************************************************************
*  I am keeping this in my code incase I had to go back and test the            *
*  grid. The only function that this served was to print the map with numbers.  *
*********************************************************************************
*
void Map::displayWithData( std::ostream& out ) const
{
    int i = 0;
    while (i < columns*rows)
    {

        for (int z=0; z < columns; z++)
        {

            if (myMap[i] == -1)
                out<< "x";

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
            if (myMap[i] == 15)
                out <<"15";
            if (myMap[i] == 16)
                out <<"16";
            if (myMap[i] == 17)
                out <<"17";
            if (myMap[i] == 18)
                out <<"18";
            if (myMap[i] == 19)
                out <<"19";
            if (myMap[i] == 20)
                out <<"20";
            if (myMap[i] == 21)
                out <<"21";
            if (myMap[i] == 22)
                out <<"22";
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
//*/

/**
*   Thi is where my alogrithms to setup map the with numerical other than values
*   of walls and other cars.  Each spot of the grid get assigned a value one greater than the
*   one before, above, to the sides and diagnol. This function will searh for a number and return back
*   if the number is somewhere in the map then it calls another function search location
*   that returns every location that the numbers are at and then those locations adjecent get
*   assigned a value one greater through the addNextNum() function.
*/

void Map::setupData()
{
    // F stands for a finish line spot
    if (searchList(findNum) == true)
    {
        vector<int> locations;
        //cout << searchList(findNum) << " = is found number" << endl;

        /// This line will return a vector that will recurrsively add the next grid values.
        locations = searchListLocation(findNum);
        for (std::vector<int>::const_iterator i = locations.begin(); i != locations.end(); ++i)
        {
          //  std::cout << *i << " ";
            addNextNum(*i, findNum+1);

        }
        //cout << endl;
        //displayWithData(cout);
        findNum++;
        setupData();
    }
    else
    {
    //    cout << "data is setup" << endl;
    }

}

/**
*   A simple search algorithm.
*/

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

/**
*   I thought this function was pretty neat
*   took me while to me a while to figure out.
*   It searches for every spot in the array where the number is found and returns their location in
*   vector.
*/

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
        //cout << "The data of spot: " << location - 1 << " is now equal to: " << myMap[location-1] << endl;
    }


    ///Setup data for right
    if (myMap[location+1] ==-10)
    {
        //cout << "The data of spot: " << location +1 << " is before we do anything: " << myMap[location+1] << endl;
        myMap[location+1] = 1;
        //cout << "The data of spot: " << location+1 << " is now equal to: " << myMap[location+1]<< endl;
    }

    /**
    *   Setup data for diagnols
    */
    // Down Diagnol
    //myMap[columns+location-1]
    //cout << "DOWNLEFT Diagnol of:" << location <<endl;
    //cout << "DOWNLEFT Diagnol is " << location+columns-1 << endl;

    /// Down Left Diagnol

    if (myMap[columns+location-1] == -10)
    {

        myMap[columns+location-1] = data;
        //cout << "The data of spot: " << columns+location-1 << " is now equal to: " <<  myMap[columns+location-1] << endl;
    }
    // Right Diagnol
    //cout << "DownRIGHTDiagnol of:" << location <<endl;
    //cout << "The DOWN RIGHT diagnol is " << columns+location+1 << endl;

    /// Down Right Diagnol

    if ( myMap[columns+location+1] == -10)
    {

        myMap[columns+location+1]= data;
        //cout << "The data of spot: " << columns+location+1 << " is now equal to: " << myMap[columns+location+1] << endl;
    }

    //cout << "UPLEFT DIAGNOL of:" << location <<endl;
    //cout << "UPLEFT diagnol is " << location-1-columns << endl;
    /// Upleft Diagnol
    if (myMap[location-1-columns] == -10)
    {

        myMap[location-1-columns] = data;
        //cout << "The data of spot: " << location-1-columns << " is now equal to: " << myMap[location-1-columns] << endl;
    }

    //cout << "UPRdiagnol of:" << location <<endl;
    //cout << "The UPRIGHT Diagnol is " << location+1-columns << endl;

    /// Upright Diagnol
    if (  myMap[location+1-columns] == -10)
    {
        myMap[location+1-columns] = data;
        //cout << "The data of spot: " << location+1-columns << " is now equal to: " << myMap[location+1-columns] << endl;
    }

    //cout << "DOWN of :" << location<<endl;
    //cout << "The DOWN is " << columns+location << endl;

    /// Down data setup
    if (myMap[columns+location] == -10)
    {
        myMap[columns+location] = data;
        //cout << "The data of spot: " << columns+location-1<< " is now equal to: " <<myMap[columns+location-1]<< endl;
    }

    // up data setup

    //cout << "find UP of:" << location <<endl;
    //cout << "The UP is " << location-columns<< endl;

    /// Up
    if (myMap[location-columns] == -10)
    {

        myMap[location-columns] = data;
        //cout << "THE DATA OF UP IS " << location-columns+1 << " is now equal to: " << myMap[location-columns+1] << endl;
    }


}
