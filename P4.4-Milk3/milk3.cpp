/*
ID: prash621
PROG: milk3
LANG: C++
*/
#include<iostream>
#include<fstream>        
#include<string>
using namespace std;

ifstream fin("milk3.in");
ofstream fout("milk3.out");

int A,B,C;
int res[21];
void func(int x,int y,int z);
int state[21][21][21];
void printres();
int main()
{
	fin>>A;
	fin>>B;
	fin>>C;
	for(int i=0;i<21;i++)
	{
		res[i]=-1;
	}
	for(int i=0;i<21;i++)
	{
		for(int j=0;j<21;j++)
		{
			for(int k=0;k<21;k++)
			{
				state[i][j][k]=-1;
			}
		}
	}
	func(0,0,C);
	printres();
	return(0);
}
void printres()
{
	int first=1;
	for(int i=0;i<21;i++)
	{
		if(res[i]==1)
		{
			if(first==1){fout<<i;first=0;}
			else{fout<<" "<<i;}
		}
	}
	fout<<"\n";
}
void func(int x,int y,int z)
{
	state[x][y][z]=1;
	if(x==0)
	{
		//Add the value of z
		res[z]=1;
	}
	//From z
	if(z!=0)
	{
		int maxZ=z;
		//Z to X
		if((A-x)>=maxZ)
		{//Empty Z naw
			if(state[x+maxZ][y][0]==-1){func(x+maxZ,y,0);}
		}
		else
		{//Fill up x completely
			if(state[A][y][z-(A-x)]==-1){func(A,y,z-(A-x));}
		}

		//Z to Y
		if((B-y)>=maxZ)
		{//Empty Z naw
			if(state[x][y+maxZ][0]==-1){func(x,y+maxZ,0);}
		}
		else
		{//Fill up y completely
			if(state[x][B][z-(B-y)]==-1){func(x,B,z-(B-y));}
		}
	}

	//From y
	if(y!=0)
	{
		int maxY=y;
		//Y to X
		if((A-x)>=maxY)
		{//Empty Y naw
			if(state[x+maxY][0][z]==-1){func(x+maxY,0,z);}
		}
		else
		{//Fill up x completely
			if(state[A][y-(A-x)][z]==-1){func(A,y-(A-x),z);}
		}

		//Y to Z
		if((C-z)>=maxY)
		{//Empty Y naw
			if(state[x][0][z+maxY]==-1){func(x,0,z+maxY);}
		}
		else
		{//Fill up z completely
			if(state[x][y-(C-z)][C]==-1){func(x,y-(C-z),C);}
		}
	}

	//From x
	if(x!=0)
	{
		int maxX=x;
		//X to Y
		if((B-y)>=maxX)
		{//Empty X naw
			if(state[0][y+maxX][z]==-1){func(0,y+maxX,z);}
		}
		else
		{//Fill up Y completely
			if(state[x-(B-y)][B][z]==-1){func(x-(B-y),B,z);}
		}

		//X to Z
		if((B-y)>=maxX)
		{//Empty X naw
			if(state[0][y][z+maxX]==-1){func(0,y,z+maxX);}
		}
		else
		{//Fill up Z completely
			if(state[x-(C-z)][y][C]==-1){func(x-(C-z),y,C);}
		}

	}	
}
