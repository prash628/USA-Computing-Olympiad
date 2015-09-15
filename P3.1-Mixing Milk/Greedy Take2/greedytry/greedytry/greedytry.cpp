/*
ID: prash621
PROG: milk
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>                 
//#include<conio.h>
using namespace std;

ifstream fin("milk.in");
ofstream fout("milk.out");
int N,M;

struct mystruct
{
	int P;
	int A;
}myA[5000];

bool mybool(const struct mystruct &left,const struct mystruct &right)
{
	return(left.P<right.P);
}
int myfunc();
int main()
{
	fin>>N;
	fin>>M;
	int i;
	for(i=0;i<M;i++)
	{
		fin>>myA[i].P;
		fin>>myA[i].A;
	}
	sort(&myA[0],&myA[M],mybool);
    myfunc();
	return(0);
}
int myfunc()
{
	int cost=0;
	int total=N;
	int i=0;
	while(total>0)
	{
		if(total<=myA[i].A)
		{
			cost=cost+(myA[i].P*total);
			total=0;
			fout<<cost;
			return(0);
		}
		else
		{
			cost=cost+(myA[i].P*myA[i].A);
			total=total-myA[i].A;
		}
		i++;
	}
}

/*

int N,M;
int S,C;
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
*/