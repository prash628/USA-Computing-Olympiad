/*
ID: prash621
PROG: calfflac
LANG: C++
*/
#include<iostream>
#include<fstream>        
#include<string>
#include<conio.h>
using namespace std;

ifstream fin("calfflac.in");
ofstream fout("calfflac.out");
int len;
 string str;
 int res=0;
 int ipos=0;
 
 char ch;
 
 string strtemp2,strtemp;

 void func();
 int checkpalin(int init);
 int check(int i,int max);

int main()
{
     while(1)
     {
             
	 fin>>strtemp2;
	 fin>>ch;
	 
	 if(ch==EOF){break;}
	 strtemp=strtemp+strtemp2;strtemp=strtemp+ch;
	 
	 str=str+strtemp;
     }
	 
	 int z;
	 int y=0;
	 for(z=0;z<strtemp.length();z++)
	 {
                                    if((strtemp[z]>=65 && strtemp[z]<=90) || (strtemp[z]>=97 && strtemp[z]<=122))
                                    {
                                                       if((strtemp[z]>=65 && strtemp[z]<=90))
                                                       {
                                                       str[y]=strtemp[z]+32;
                                                       }
                                                       else
                                                       {
                                                       str[y]=strtemp[z];
                                                       }
                                                       y++;
                                    }
     }
	 str[y]='\0';
	 len=str.length();fout<<len<<"\n";
	 func();
	 
	 fout<<res<<"\n";
	 
     int j;
	 for(j=ipos;j<=(ipos+res);j++){fout<<str[j];}
	 fout<<"\n";
	 
	return(0);
}

void func()
{
	int i=0;
	for(;i<len;i++)
	{
		checkpalin(i);
	}
}

int checkpalin(int i)
{
	int max=len-i;
	int x;int chk;
	for(x=1;x<max;x++)
	{
		chk=check(i,(x+i+1));
		if(chk)
		{
			if((x>res)){res=x;ipos=i;}
		}
	}
}

int check(int i,int j)
{
	int fin=j;
	j--;
	for(;i<fin;i++,j--)
	{
		if(str[i]!=str[j])
		{
			return(0);
		}
	}                                         
	return(1);
}
