#include "Target.h"

Target::~Target(){}

Target::Target()
{
		id = idCount++;
}

Target::Target(default_random_engine * gen)
{
	normal_distribution<> threatDist(100, 15);
	id=idCount++;
	threatScore= threatDist(*gen);	

}	

double Target::getThreatScore(){
	return threatScore;
}	

int Target::idCount =0;

int Target::getId()
{
	return id;	
}
