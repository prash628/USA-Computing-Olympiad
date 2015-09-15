/*
ID: prash621
PROG: packrec
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("packrec.in");
ofstream fout("packrec.out");
int N=4;
int area=100000;//Approx infinity

struct rect
{
	int a1;
	int a2;
}figure[4];
void readrect();
int rec(int i,int A[4]);
void work(int A[4]);
int permute(int no,int chk[4],int l[4],int b[4],int P[4]);
int calcarea(int l[4],int b[4],int P[4]);

int main()
{
	readrect();
	int A[4];
	A[0]=A[1]=A[2]=A[3]=0;
	rec(0,A);
	fout<<area<<"\n";

	return(0);
}

void readrect()
{
	int i;
	for(i=0;i<N;i++)
	{
		fin>>figure[i].a1;
		fin>>figure[i].a2;
	}
}

int rec(int i,int A[4])
{
	//Base case
	if(i==4)
	{
		work(A);
		return(1);
	}

	A[i]=0;
	rec(i+1,A);
	A[i]=1;
	rec(i+1,A);

	return(1);
}

void work(int A[4])
{
	int tempx=0;
	int tempy;
	int l[4];
	int b[4];
	int i;
	for(i=0;i<N;i++)
	{
		if(A[i]==0)
		{
			l[i]=figure[i].a1;
			b[i]=figure[i].a2;
		}
		else
		{
			l[i]=figure[i].a2;
			b[i]=figure[i].a1;
		}
	}
	int P[4];
	int chk[4];
	for(i=0;i<4;i++)
	{
		chk[i]=0;
	}
	permute(0,chk,l,b,P);

}

int permute(int no,int chk[4],int l[4],int b[4],int P[4])
{
  	//Base Case
	if(no==N)
	{
		calcarea(l,b,P);
		return(1);
	}
	int i;
	
	for(i=0;i<4;i++)
	{
		if(chk[i]==0)
		{
			chk[i]=1;
			P[no]=i;
		    permute(no+1,chk,l,b,P);
		}
	}
	return(1);
}
	
int calcarea(int l[4],int b[4],int P[4])
{
}
	
