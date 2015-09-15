/*
ID: prash621
PROG: namenum
LANG: C++
*/
#include<iostream>
#include <string>
#include <fstream> 
                    
using namespace std;

string N;
int Nlen;
ifstream fin("namenum.in");
ofstream fout("namenum.out");
ifstream dict("dict.txt");
void myfunc();
string change(string x);
int findNlen(string x);

int main()
{

fin>>N;
Nlen=findNlen(N); 
myfunc();
                        
return(0);

}

int findNlen(string x)
{
	int len=x.length();
}

void myfunc()
{
	int count=0;
	string x,y;
	int slen;
	int conv;
	string cmp;
	while(1)
	{
	  dict>>x;
	  slen=x.length();
	  
	  if(x[0]=='Z'){break;}
      if(slen==Nlen)
	  {
	    y=change(x);
	     
	    if(N.compare(y)==0){fout<<x<<"\n";count++;}
	  }
	}
	if(count==0){fout<<"NONE"<<"\n";}
}

string change(string x)
{
    
   int number=0,i;
   char z;
   for(i=0;i<x.length();i++)
   {
	   z=x[i];
	   if(z=='A'||z=='B'||z=='C')
	   {
		   x[i]='2';
	   }
	   else if(z=='D'||z=='E'||z=='F')
	   {
		   x[i]='3';
	   }
	   else if(z=='G'||z=='H'||z=='I')
	   {
		   x[i]='4';
	   }
	   else if(z=='J'||z=='K'||z=='L')
	   {
		   x[i]='5';
	   }
	   else if(z=='M'||z=='N'||z=='O')
	   {
		   x[i]='6';
	   }
	   else if(z=='P'||z=='R'||z=='S')
	   {
		   x[i]='7';
	   }
	   else if(z=='T'||z=='U'||z=='V')
	   {
		   x[i]='8';
	   }
	   else if(z=='W'||z=='X'||z=='Y')
	   {
		   x[i]='9';
	   }
   }
   x[i]='\0';
   return(x);
}
	   
