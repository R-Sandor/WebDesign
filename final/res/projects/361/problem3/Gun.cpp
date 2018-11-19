#include "Gun.h"
#include <iostream>
#include <iomanip>
using namespace std;

Gun::Gun(){}
// The gun will engage itself after being initialized 
Gun::Gun(vector<Target*> newTargets, default_random_engine * gen)
{
	for( Target* target: newTargets)
			targetQueue.push(target);
	engageThreats(gen);
}

Gun::~Gun(){}

void Gun::engageThreats(default_random_engine * gen)
{
	uniform_int_distribution<int> intDist(0,100);
	int numBursts =0;
	
	while (!targetQueue.empty())
	{
		Target* target = targetQueue.top();
		++numBursts;
		while ( intDist(*gen) <= 15 )
		{
			++numBursts;
		}
		cout << "Target Id: " << target->getId()<<"     " << "threat ";
	    cout << target->getThreatScore() << setw(5); 
		cout << numBursts << " burst\n";
		delete target;
		numBursts =0;
		targetQueue.pop();
		
	}	
}		
