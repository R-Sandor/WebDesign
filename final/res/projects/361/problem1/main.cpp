// Raphael J. Sandor
// problem one
#include "Crack.h"
#include <random>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	   default_random_engine * randomEngine = new default_random_engine(time(NULL));
	ofstream fout;
	fout.open("gnuplot.txt");
	normal_distribution<double> magDist(3.0,1.0);
	uniform_real_distribution<> angleDis(0.0,360.0);	
	Crack* crack1 =new Crack(0,0,magDist(*randomEngine), angleDis(*randomEngine), fout, randomEngine);

	Crack *crack2 = new Crack(0,0,magDist(*randomEngine), angleDis(*randomEngine), fout, randomEngine);
	Crack* crack3 =new Crack(0,0,magDist(*randomEngine), angleDis(*randomEngine), fout, randomEngine);
	cout <<"Number of Crack objects created:  " << crack1->getIdCount()<< endl;
	crack1->printCords(fout);
	crack2->printCords(fout);
	crack3->printCords(fout);
	fout.close();
	delete crack1;
	delete crack2;
	delete crack3;
	
	fout.open("commands.txt");
	fout << "plot 'gnuplot.txt' with lines\n";
	fout << "pause -1\n";
	fout.close();
	system("gnuplot commands.txt");
			
	return 0;
}
