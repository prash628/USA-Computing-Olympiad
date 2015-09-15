/*
ID: prash621
PROG: palsquare
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");
int N;
void func();
int func2(int x);
void printbase(int x);
void print1();
int findbase(int x);
int main()
{
	fin>>N;
	print1();
	func();
	 
	return(0);
}
void func()
{
	int x,xsq,ispalin;
	for(x=2;x<=300;x++)
	{
      xsq=x*x;
	  ispalin=func2(xsq);
	  if(ispalin)
	  {
		  printbase(x);
		  fout<<" ";
		  printbase(xsq);
		  fout<<"\n";
	  }
	}
}
void print1()
{
	fout<<1<<" "<<1<<"\n";
}
int func2(int x)
{
	int rem,quo,den;
	int maxbase=findbase(x);
	char basenum[100];
	basenum[maxbase]='\0';
	int y=maxbase-1;
	 
	for(;y>=0;y--)
	{
		if(x%N==0)
		{
			basenum[y]=0; 
		}
		else
		{
			basenum[y]=(x%N); 
		}
		                                     
		x=x/N;
	}
	//Finding if itz a palindrome
    int a=0,b=maxbase-1;
    int i,j;
	for(;a<=(maxbase-1);)
	{   
        
		if(basenum[a]!=basenum[b]){return(0);}
		else
		{
			a++;b--;
		}
	}
	return(1);
}
int findbase(int x)
{
	int y,yy=0;

	for(y=1;y<=x;yy++)
	{
		y=y*N;
	}
	return(yy);
}
void printbase(int x)
{
	int rem,quo,den;
	int maxbase=findbase(x);
	char basenum[100];
	basenum[maxbase]='\0';
	int y=maxbase-1;
	for(;y>=0;y--)
	{
		if(x%N==0)
		{
			basenum[y]=0;
		}
		else
		{
			basenum[y]=(x%N);
		}
		x=x/N;
	}
	int a;
	int j;
	char z;
	for(a=0;a<=maxbase-1;a++)
	{
		j=basenum[a];
		if(j<10)
		{
		fout<<j;
        }
        else
        {
            z=j-10+65;
            fout<<z;
        }
            
            
    
	}
}
