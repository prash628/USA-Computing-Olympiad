#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("permute.in");
ofstream fout("permute.out");

int A[100];
int N;

void readelem();
int permute(int no,int chk[100],int P[100]);
void printem(int P[100]);

int main()
{
	fin>>N;
	readelem();
	
	int chk[100];
	int i;
	for(i=0;i<N;i++)
	{
		chk[i]=0;
	}
	int P[100];

	permute(0,chk,P);
	return(1);
}

void readelem()
{
	int i;
	for(i=0;i<N;i++)
	{
		fin>>A[i];
	}
}

int permute(int no,int chk[100],int P[100])
{
	//Base Case
	if(no==N)
	{
		printem(P);
		return(1);
	}
	int i;
	for(i=0;i<N;i++)
	{
		if(chk[i]==0)
		{
			chk[i]=1;
			P[no]=i;
		    permute(no+1,chk,P);
		    chk[i]=0;
		}
	}
	return(1);
}

void printem(int P[100])
{
	int i;
	int pos;
	for(i=0;i<N;i++)
	{
		pos=P[i];
		fout<<A[pos];
	}
	fout<<"\n";
}

