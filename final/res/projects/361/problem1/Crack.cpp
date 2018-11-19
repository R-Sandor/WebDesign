#include "Crack.h"
#include <iostream>
#include <math.h>
#include <iomanip>
int Crack::idCount=0;
// nost the most precise pie but it need not be that precise
#define PI 3.141592
// default constructor
Crack::Crack()
{
	next = nullptr;
	id=idCount++;
}
// This constructor takes in the starting point, a magnitude, and degrees/angle

Crack::Crack(double xVal, double yVal,double mag,double angleIn, ofstream &fout, default_random_engine * inGen)
{
	next = nullptr;
	next2 = nullptr;
	segCordCount=0;
	if (idCount< 250)
	{	
	angle = angleIn;
	x = xVal;
	y = yVal;
	xCords[segCordCount]=x;
	yCords[segCordCount++]=y;
	id= idCount++;
	gen = inGen;
	fout << x<< " " << y << endl;
	magnitude = mag;
	continueCracking();
	}
}

// the constructor calls this so that when
// an object is created it can continue
// the operations of a crack
void Crack::continueCracking()
{
	normal_distribution<double> magDist(3.0,1.0);

	uniform_real_distribution<> angleDis(0.0, 360.0);
	uniform_real_distribution<> probDis (0.0, 1.0);

	double probability = probDis(*gen); 
	if (probability >= .90)
	{
			continueStraight();
	}
	else if ( probability >= .70)
	{
		// change direction
		changeDirection(magDist(*gen),angleDis(*gen) );
	}
	else if ( probability >= .5)
	{
		// stop	
	}
	else {
			split();
	}

}
// returns the number of times the type of object has been created.
int	Crack::getIdCount()
{
	return idCount;	
}
// makes the line continue at its current angle and magnitude
void Crack::continueStraight()
{
	fout<<setprecision (2)<< showpoint << fixed;
	double cosX = cos(angle*PI/180);
	double newX = (cosX*magnitude)+x;
	x = newX;
	double sinY = sin(angle*PI/180);
	double newY = sinY*magnitude+y;
	fout << newX << " "<< newY;
	y = newY;
	xCords[segCordCount]=x;
	yCords[segCordCount++]=y;
	fout<<setprecision (2)<< showpoint << fixed;
	continueCracking();
}
// returns id's
int  Crack::getId()
{
	return id;
}
// creates two more line segmenets and pushes them on 
// to the list passing their starting points as the last
// location of the current segment
void Crack::split()
{
	if (idCount <250)
	{
	if (next == nullptr)
	{
		next = new Crack(x,y,magnitude,angle, fout, gen);
		next2 = new Crack(x,y,magnitude,angle, fout, gen);
		
		continueCracking();
	}
	else
	{		
	
		Crack * it =next; 	
		while (it->next != nullptr)
		{
			it = it->next;	
		}
		it->next = new Crack(x,y,magnitude,angle, fout, gen);
		it =next2; 	
		while (it->next2 != nullptr)
		{
			it = it->next2;	
		}
		it->next2 = new Crack(x,y,magnitude,angle, fout, gen);
		continueCracking();
	}
	}
}
// changes the direction of the line and magnitude
// the saves the cordinate for that segment
void Crack::changeDirection(double mag, double newAngle)
{
	x = cos(newAngle*PI/180)*mag+x;
	y = sin(newAngle*PI/180)*mag+y;
	xCords[segCordCount]=x;
	yCords[segCordCount++]=y;
	continueCracking();

}

// print function completes the program 
// the program also make sure to delete pointer
// by using the recursive behavior of this
// function
void Crack::printCords(ofstream &fout)
{
	if (segCordCount !=0)
	{		
	for (int i=0; i <segCordCount; i++)
			fout << xCords[i] << " " << yCords[i]<<endl;
			fout << endl;
	Crack * it =next; 		

	
	}	

	if (next != nullptr)
		{

			next->printCords(fout);
			delete next;
		}
			if (next2 != nullptr)
			next2->printCords(fout);
			delete next2;

}


