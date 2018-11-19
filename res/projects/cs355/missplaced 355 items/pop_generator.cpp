#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
    fstream fout;
    fout.open("pop_data.txt",ios::out);
    int age,counter=0;
    default_random_engine gen;

    uniform_int_distribution<int> a0dist(1,145);
    uniform_int_distribution<int> udist(1,59);
    exponential_distribution<double> edist(.25);
    for(int i=0; i<1000; i++)
    {
    age = a0dist(gen);
    if(age>120){counter++;
                age = 59 + edist(gen);
                cout<<age<<endl;
                }
    else {age = udist(gen);}
    }

    cout<<1000-counter<<" under age 60 and "<<counter<<" 60 and over "<<endl;
    return 0;
}
