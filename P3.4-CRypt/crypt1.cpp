/*
ID: prash621
PROG: crypt1
LANG: C++
*/
#include<iostream>
#include<fstream>        
#include<string>
using namespace std;

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");
int N;
int A[11];
int pro1[3];
int pro2[2];

int partial1[3];
int partial2[3];
int sum[4];


void func();
void findpro1();
void findpro2();
int findpartial1();
int findpartial2();
int findsum();
int checkvalidity();
int checkdigit(int x);

int total=0;


int main()
{
	 fin>>N;
	 func();
	 findpro1();

	 fout<<total<<"\n";
	 
	 
	return(0);
}

void func()
{
	int i;
	for(i=0;i<N;i++)
	{
		fin>>A[i];
	}
}

void findpro1()
{
	int i,j,k;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{
				pro1[0]=A[i];pro1[1]=A[j];pro1[2]=A[k];
				findpro2();
			}
		}
	}
}

void findpro2()
{
	int i,j;
	int val;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			pro2[0]=A[i];pro2[1]=A[j];
			val=checkvalidity();
			//if(val>0){fout<<"\n"<<pro1[2]<<pro1[1]<<pro1[0]<<"\n "<<pro2[1]<<pro2[0]<<"\n";}
			total=total+val;                  
		}
	}
}


int checkvalidity()
{
	int res;
	res=findpartial1();
	if(res==0){return(0);}
	
	res=findpartial2();
	if(res==0){return(0);}
	
	res=findsum();
	if(res==0){return(0);}
	return(1);
}

int findpartial2()
{
	int a,b;
	int val;

	a=0;
	partial2[2]=pro1[2]*pro2[0];
	a=partial2[2]/10;
	partial2[2]=partial2[2]%10;
	val=checkdigit(partial2[2]);
	if(val==0){return(0);}

	
	partial2[1]=pro1[1]*pro2[0];
	partial2[1]=partial2[1]+a;
	a=partial2[1]/10;
	partial2[1]=partial2[1]%10;
	val=checkdigit(partial2[1]);
	if(val==0){return(0);}

	partial2[0]=pro1[0]*pro2[0];
	partial2[0]=partial2[0]+a;
	if(partial2[0]>9)
	{
		return(0);
	}
	val=checkdigit(partial2[0]);
	if(val==0){return(0);}

	return(1);
}


int findpartial1()
{
int a,b;
	int val;

	a=0;
	partial1[2]=pro1[2]*pro2[1];
	a=partial1[2]/10;
	partial1[2]=partial1[2]%10;
	val=checkdigit(partial1[2]);
	if(val==0){return(0);}

	
	partial1[1]=pro1[1]*pro2[1];
	partial1[1]=partial1[1]+a;
	a=partial1[1]/10;
	partial1[1]=partial1[1]%10;
	val=checkdigit(partial1[1]);
	if(val==0){return(0);}

	partial1[0]=pro1[0]*pro2[1];
	partial1[0]=partial1[0]+a;
	if(partial1[0]>9)
	{
		return(0);
	}
	val=checkdigit(partial1[0]);
	if(val==0){return(0);}

	return(1);	
}


int checkdigit(int x)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(A[i]==x){return(1);}
	}
	return(0);
}

int findsum()
{
	int carry;
	int val;
	sum[3]=partial1[2];

	sum[2]=partial1[1]+partial2[2];
	carry=sum[2]/10;
	sum[2]=sum[2]%10;
	val=checkdigit(sum[2]);
	if(val==0){return(0);}

	sum[1]=partial1[0]+partial2[1]+carry;	
	carry=sum[1]/10;
	sum[1]=sum[1]%10;
	val=checkdigit(sum[1]);
	if(val==0){return(0);}

	sum[0]=partial2[0]+carry;
	if(sum[0]>9)
	{
		return(0);
	}
	val=checkdigit(sum[0]);
	if(val==0){return(0);}
	/*
    fout<<"\n"<<pro1[0]<<pro1[1]<<pro1[2]<<"\n "<<pro2[0]<<pro2[1]<<"\n";
    fout<<""<<partial1[0]<<partial1[1]<<partial1[2]<<"\n"<<partial2[0]<<partial2[1]<<partial2[2]<<"\n";          
    fout<<sum[0]<<sum[1]<<sum[2]<<sum[3]<<"\n";
    */
	return(1);
}
