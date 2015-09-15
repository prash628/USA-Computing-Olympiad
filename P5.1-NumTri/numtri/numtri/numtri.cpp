/*
ID: prash621
PROG: numtri
LANG: C++
*/
#include<iostream>
#include<fstream>        
#include<string>
using namespace std;

ifstream fin("numtri.in");
ofstream fout("numtri.out");

int N;
int A[1001][1001];
int memo[1001][1001];
int func(int ipos,int level);
int main()
{
	fin>>N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			fin>>A[i][j];
		}
	}
	for(int i=0;i<1001;i++)
	{
		for(int j=0;j<1001;j++)
		{
			memo[i][j]=-1;
		}
	}
	int x=func(0,1);
	int y=func(1,1);
	if(x>y)
	{
		fout<<A[0][0]+x<<"\n";
	}
	else
	{
		fout<<A[0][0]+y<<"\n";
	}

	return(0);
}
int func(int ipos,int level)
{
	if(level==N)
	{//At the highest level
		return(0);
	}
	if(memo[level][ipos]!=-1){return(memo[level][ipos]);}
	else
	{
		int x=func(ipos,level+1);
		int y=func(ipos+1,level+1);
		if(x>y)
		{
			memo[level][ipos]=x+A[level][ipos];
		}
		else
		{
			memo[level][ipos]=y+A[level][ipos];
		}
		return(memo[level][ipos]);
	}
}