#ifndef Target_H
#define Target_H
#include <random>

using namespace std;
class Target
{
		public:
		Target();
		Target(default_random_engine * gen);
		double getThreatScore();
		int getId();
		~Target();

		private:
		int threatScore;
		static int idCount;
		int id;
};

#endif
