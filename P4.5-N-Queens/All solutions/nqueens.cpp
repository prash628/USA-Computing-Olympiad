#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nqueens.in");
ofstream fout("nqueens.out");


int sols=0;
int N;
void func();
int solve(int i,int j);
int a[100][100];
int positionable(int i,int j);
void showpositions();

int main()
{
	fin>>N;
	func();
	solve(0,0);
	fout<<sols;
	return(0);
}

void func()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			a[i][j]=-1;
		}
	}
}

int solve(int i,int j)
{
	int res;

	for(;j<N;j++)
	{
                                              
		if(positionable(i,j)) 
		{
			a[i][j]=1;
			
			if(i==N-1){sols++;a[i][j]=-1;return(1);}

			solve(i+1,0);
			a[i][j]=-1;

		}
	}
	if(j==N){return(1);}
}

void showpositions()
{
	int i,j;
	
	for(i=0;i<N;i++){fout<<i;}
	fout<<"\n";
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(a[i][j]==1)
			{
				fout<<"Q";
			}
			else
			{
				fout<<" ";
			}
		}
		fout<<"\n";
	}
}

int positionable(int i,int j)
{
	int p,q;
	//Col Check
	for(p=0;p<N;p++)
	{
		if(a[p][j]==1){return(0);}
	}

	//Diag check

	//Right down
	p=i;
	q=j;
	for(;(p<=N-1)&&(q<=N-1);)
	{
		if(a[p][q]==1){return(0);}
		p++;q++;
	}

	//Left down
    p=i;
	q=j;
	for(;(p<=N-1)&&(q>=0);)
	{
		if(a[p][q]==1){return(0);}
		p++;q--;
	}

	//Right up
	p=i;
	q=j;
	for(;(p>=0)&&(q<=N-1);)
	{
		if(a[p][q]==1){return(0);}
		p--;q++;
	}

	//Left up
	p=i;
	q=j;
	for(;(p>=0)&&(q>=0);)
	{
		if(a[p][q]==1){return(0);}
		p--;q--;
	}

	return(1);
}





