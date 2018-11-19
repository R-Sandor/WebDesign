#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <map>
using namespace std;

int main()
{
    fstream fout;
    fout.open("Newpop_data.txt",ios::out);
    int portion, age,counter=0;
    default_random_engine gen(time(NULL));
    int over90=0;
    uniform_int_distribution<int> a0dist(1,145);
    uniform_int_distribution<int> udist(1,59);
    exponential_distribution<double>  edist(.395);
    exponential_distribution<double> edist2(.25);


    for(int i=0; i<=5000; i++)
    {
    portion = a0dist(gen);
    if(portion>120){counter++;
                if(portion >138)
     			{
                    if(portion >143)
                    {
                        age = 90 + edist(gen);
                    }
                    else{

                    age = 80 + edist(gen);
                    }
            	}
            	else
            	{
                   age = 60 + edist2(gen);
            	}

                }
    else {age = udist(gen);}

    fout << age << endl;
    }

    cout<<5000-counter<<" under age 60 and "<<counter<<" 60 and over "<<endl;
    fout.close();
    return 0;
}
