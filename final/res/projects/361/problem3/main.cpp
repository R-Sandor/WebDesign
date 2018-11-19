#include "Target.h"
#include "Gun.h"
#include <ctime>
#include <iostream>
#include <random>

using namespace std;
int main()
{
	default_random_engine * randomEng = new default_random_engine(time(NULL));	
	vector<Target*> newTargets;
	uniform_int_distribution<> intDist(4,10);
	for(int i =0; i< intDist(*randomEng); i++)
	{
		newTargets.push_back(new Target(randomEng));	
	}
	Gun gun = Gun(newTargets, randomEng);
	delete randomEng;

	return 0;


}
