#ifndef CRACK_H
#define CRACK_H
#include <fstream>
#include <random>
#include <list> 

using namespace std;

class Crack
{
	public:
	// default constructor
	Crack();
	Crack * next=nullptr;
	Crack * next2= nullptr;
	// overloaded constructor
	// takes values of x and y 
	Crack(double x, double y,double mag,double angle, ofstream &fout, default_random_engine * inGen);


	void printCords(ofstream &out);
	int getId();	
	int getIdCount();
	
	private:
	static int idCount;
	int id;
	double x;
	double y;
	
	// Holds 100 possible codinates that a single segment could have
	double xCords[150];
	double yCords[150];

	int segCordCount;
	double magnitude;
	double angle;
	ofstream fout;
	default_random_engine * gen;
	void continueCracking();
	void split();
	void continueStraight();
	void changeDirection(double mag, double angle);
};

#endif
