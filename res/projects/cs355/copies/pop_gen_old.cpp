#include <string>
#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;
#include "person.h"

int main()
{   list<int>::iterator iitr;
    list<int>::iterator ibegin;
    list<int>::iterator iend;
    list<person>pop;
    list<person>::iterator pitr;
    person * pptr;
    int age;
    int fid = 100;
    int fsize;
    int pcount;
    int Num = 100;
    int Old;
    int kount=0;
    int numg;
    int x;

    default_random_engine Gen(time(NULL));
    ///Adist is athe age distribution
    uniform_int_distribution<int> OldDist(0,100);
    uniform_int_distribution<int> Adist(1,65);
    ///Sdist the size of the family group
    uniform_int_distribution<int> Sdist(1,7);
    ///Gdist is the number of additional groups each belongs
    uniform_int_distribution<int> Gdist(2,4);
    ///generic mixing groups non-work/school/family/hosp
    uniform_int_distribution<int> MGdist(2000,2050);
    ///Edist returns a value greater than 0 but
    ///with 3.5 terminating at 1.0-ish
    exponential_distribution<double>Edist(3.0);

    for(int i=10000; i<Num+10000; i++)
    {
       pptr=new person(i);
       pop.push_back(*pptr);
    }
    pitr=pop.begin();

    while(kount<Num)
    {
        fsize=Sdist(Gen);
        for(int j=0; j<fsize; j++)
        {   Old = OldDist(Gen);
            if(Old>9)
            {
            age = Adist(Gen);
            while((j==0)&&(age<18))
            {
            age = Adist(Gen);
            }
            }
            else{
               age = 65+int(Edist(Gen)*35);
            }
        pitr->setFid(fid);
        pitr->setAge(age,&Gen);


        numg=Gdist(Gen);
        for(int k=0; k<numg; k++)
        {
           x = MGdist(Gen);
           pitr->add2mxg(x);
        }
        pitr->mxguniq();
        pitr->display();
        kount++;
        pitr++;
        if(pitr==pop.end()){j=fsize; kount=Num;}
        }
      fid++;
    }

    fstream fout;
    fout.open("pop_data_old.txt",ios::out);

    pitr=pop.begin();
    while(pitr!=pop.end())
    {
         fout<<"person("<<pitr->getPid()<<", "<<pitr->getAge()<<", "<<pitr->getFid()
            <<", "<<pitr->getsymptom()<<", "<<pitr->getexposedDays()<<", "
            <<pitr->getincubateDays()<<", "<<pitr->getisDiagnosed()<<", "
            <<pitr->getdayDiesAfter()<<", [";

            ibegin = pitr->get_mixgrps_begin();
            iend=pitr->get_mixgrps_end();
            iitr=ibegin;
            while(iitr!=iend){
                    if(iitr!=ibegin){fout<<", "<<*iitr;}
                    else{fout<<*iitr;}
                    iitr++;}
                fout<<"], [])."<<endl;
        pitr++;
    }
    return 0;


}
