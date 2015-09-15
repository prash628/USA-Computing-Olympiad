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

using namespace std;

ifstream fin("milk.in");
ofstream fout("milk.out");
int N,M,cost=0;

struct myarray
{
int P;
int A;
}farmers[5000];

void func();
int work();
bool mybool(const myarray &a1,const myarray &a2)
{
	return(a1.P<a2.P);
}


int main()
{
	fin>>N;
	fin>>M;
	func();
	sort(&farmers[0],&farmers[M],mybool);
	work();
	fout<<cost;
	fout<<"\n";
	 
	return(0);
}

void func()
{
	int i;
	for(i=0;i<M;i++)
	{
		fin>>farmers[i].P;
		fin>>farmers[i].A;
	}
}

int work()
{
	int farmerlimit;
	int qty;
	int i=0;
	while(1)
	{
		farmerlimit=(farmers[i].A);
		if(farmerlimit<=N)//Take da entire thing
		{
			N=N-farmerlimit;
			cost=cost+(farmers[i].A*farmers[i].P);
		}
		else //Take some partially
		{
			cost=cost+(farmers[i].P*N);
			N=0;
		}
		if(N==0)
		{return(1);}
		i++;
        
	}
}
