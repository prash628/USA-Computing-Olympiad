/*
ID: prash621
PROG: dualpal
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
 
using namespace std;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");
int N,S;
void func();
int findanother();
int findres(int i,int base);
int findbase(int x,int b);

int main()
{
	fin>>N;
	fin>>S;
	func();
	  
	return(0);
}

void func()
{
	int i;
	for(i=0;i<N;i++)
	{
		findanother();
	}
}

int findanother()
{
	int i=S+1;
	int base;
	int count=0;
	int res;
	for(;1;i++)
	{
       count=0;
       for(base=2;base<=10;base++)
	   {
          res=findres(i,base);
		  if(res)
		  {
                 
			  count++; 
			  if(count==2)
 			  {   
				  S=i;
				  fout<<i<<"\n";
				  return(1);
			  }
		  }
	   }
	}
}

int findres(int x,int base)
{
	int rem,quo,den;
	int maxbase=findbase(x,base);
	char basenum[100];
	basenum[maxbase]='\0';
	int y=maxbase-1;
	 
	for(;y>=0;y--)
	{
		if(x%base==0)
		{
			basenum[y]=0; 
		}
		else
		{
			basenum[y]=(x%base); 
		}
		                                     
		x=x/base;
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
int findbase(int x,int b)
{
	int y,yy=0;

	for(y=1;y<=x;yy++)
	{
		y=y*b;
	}
	return(yy);
}
