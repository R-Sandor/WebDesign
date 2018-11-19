#ifndef GUN_H
#define GUN_H
#include "Target.h"
#include <queue>
#include <random>
#include <list>

using namespace std;

struct lessOfAThreat
{
	bool operator()(Target * lhs, Target * rhs)
	{
		return lhs->getThreatScore() < rhs->getThreatScore();	
	}
};

class Gun
{
	public:
	Gun();
	Gun(vector<Target*> newTargets, default_random_engine * gen);
	~Gun();
	void engageThreats(default_random_engine * gen);
	void setThreats(vector<Target*> targets);
	private:
	
	priority_queue<Target* , vector<Target*>, lessOfAThreat> targetQueue;

		
};

#endif
