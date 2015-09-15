/*
ID: prash621
PROG: transform
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include <vector>
#include <fstream> 
using namespace std;

int N;
ifstream fin("transform.in");
ofstream fout("transform.out");
char ip[10][10];
char op[10][10];
char temp[10][10];
char iptemp[10][10];

void iprestore();
void readem();
int nochangecase();
int compare();
void deg90();
void horizontalref();

int main()
{
int i; 
int res=0;
fin>>N;
readem();
deg90();//90
res=compare();
if(res){fout<<1<<"\n";} 
else
{
	deg90();//180
	res=compare();
	if(res){fout<<2<<"\n";} 
	else
	{
		deg90();//270
		res=compare();
		if(res){fout<<3<<"\n";}
		else
		{
            iprestore();
			horizontalref();
			res=compare();
			if(res){fout<<4<<"\n";}
			else
			{
				deg90();//deg90
				res=res+compare();
				deg90();//180deg
				res=res+compare();
				deg90();//270deg
				res=res+compare();
                if(res>0){fout<<5<<"\n";}
				else
				{
					res=nochangecase();
					if(res){fout<<6<<"\n";} 
					else
					{fout<<7<<"\n";}
				}
			}
		}
	}
}
return(0);
}

int nochangecase()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(op[i][j]!=iptemp[i][j]){return(0);}
		}
	}
	return(1);
}

int compare()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
            
			if(op[i][j]!=ip[i][j]){return(0);}
		}
		
	}
	return(1);
}

void readem()
{
     int i,j;
     for(i=0;i<N;i++)
     {
		 for(j=0;j<N;j++)
		 {

                     fin>>ip[i][j];
					 iptemp[i][j]=ip[i][j];
         }
     }
	 for(i=0;i<N;i++)
     {
		 for(j=0;j<N;j++)
		 {

                     fin>>op[i][j];
         }
     }
}
             
                  
void deg90()
{
	int i,j;
	int n=N-1;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			temp[j][n-i]=ip[i][j];
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			ip[i][j]=temp[i][j];
		}
		
	}
	
}

void horizontalref()
{
	int i,j;
	int n=N-1;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			temp[j][n-i]=ip[j][i];
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			ip[i][j]=temp[i][j];
		}
	}
}

void iprestore()
{
     int i,j;
     for(i=0;i<N;i++)
     {
                     for(j=0;j<N;j++)
                     {
                                     ip[i][j]=iptemp[i][j];
                     }
     }
}
