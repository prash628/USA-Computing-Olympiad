/*
ID: prash621
PROG: barn1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>                 
//#include<conio.h>
using namespace std;

ifstream fin("barn1.in");
ofstream fout("barn1.out");
int N,S,C;
int res;

struct mystr
{
       int no;
       int box;
}array[201];


void func();
int work();
int barnfunc(int diff);
int findres();
bool mybool(const mystr &a1,const mystr &a2)
{
     return(a1.no<a2.no);
}

int main()
{
	fin>>N;
	fin>>S;
	fin>>C;

	func();
	sort(&array[0],&array[C],mybool);
	
	int i;
	for(i=0;i<C;i++)
	{
                    array[i].box=i;
    }
	
    
	work();
	fout<<res<<"\n";

                               // getch();
	return(0);
}

void func()
{
    res=C;
	int i;
	for(i=0;i<C;i++)
	{
		fin>>array[i].no;                  
		array[i].box=i;
	}	
}

int work()
{
	int max=C;
	int diff=0;
	int chk=1;

    if(max<=N){return(1);}
	while(1)
	{
		chk=1;
		while(chk)
		{
                                       
                                       
			chk=barnfunc(diff);
			if(chk)
			{
                
				array[chk].box=array[chk-1].box;
				max--;
				                                 
				res=res+diff-1;
				if(max<=N){return(1);}
			}
		}
		diff++;
	}
}

int barnfunc(int diff)
{
	int i;
	for(i=0;i<C-1;i++)
	{
		if((array[i+1].no-array[i].no)==diff && (array[i+1].box!=array[i].box))
		{
			return(i+1);
		}
	}
	return(0);
}

