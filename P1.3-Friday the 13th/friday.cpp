/*
ID: prash621
PROG: friday
LANG: C++
*/
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
int mdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int N;
int op[7];
int pday,pyear;
void compute();
int findleap(int yr);
void compyr(int leap);
void compmon(int d);
int main()
{
    int z;
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    fin>>N;
    pday=2;
    pyear=1900;
    compute();
    for(z=0;z<=5;z++){fout<<op[z]<<" ";}
    fout<<op[z]<<endl;

    return(0);
}
void compute()
{
     int last=pyear+N;
     int i,isleap;
     for(i=pyear;i<last;i++)
     {
                            isleap=findleap(i);
                            compyr(isleap);
     }
}
int findleap(int yr)
{
    if(yr%4==0)
    {
               if(yr%100==0)
               {
                            if(yr%400==0){return(1);}
                            else{return(0);}
               }
               else{return(1);}
    }
    else
    {return(0);}
}
void compyr(int leap)
{
     int mon,dayz;
     for(mon=1;mon<=12;mon++)
     {
                             dayz=mdays[mon];
                             if(leap==1 && mon==2){dayz=dayz+1;}
                             compmon(dayz);
     }
}
void compmon(int d)
{
     int xtra;
     pday=(pday+12)%7;
     xtra=d-12;
     op[pday]=op[pday]+1;
     pday=(pday+xtra)%7;
}
     




