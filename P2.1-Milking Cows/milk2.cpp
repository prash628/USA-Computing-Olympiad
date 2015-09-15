/*
ID: prash621
PROG: milk2
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include <vector>
#include <fstream> 
using namespace std;

int N,idle=0,work=0;
ifstream fin("milk2.in");
ofstream fout("milk2.out");
struct mystr
{
       int a;
       int b;
}xxx;
vector<mystr> v;

void readem();
bool myfunc(const mystr &one,const mystr &two);
void darealdeal();

int main()
{
int i;  
fin>>N;
readem();
sort(v.begin(),v.end(),myfunc);
darealdeal();
fout<<work<<" "<<idle<<"\n";
   
    return(0);
}

void readem()
{
     int i;
     for(i=0;i<N;i++)
     {
                     fin>>xxx.a;
                     fin>>xxx.b;
                     v.push_back(xxx);
     }
}

bool myfunc(const mystr &one,const mystr &two)
{
     return(one.a<two.a);
}

void darealdeal()
{
     int i,j,res,wki,wkop,idlex=v[0].b;
     int p,q,r,s;
     int e,f,g,h;
     
     for(p=v[0].b,i=0;i<N;)
     {  
            i++;
            for(;i<N;)
                  {
                               if(v[i].b<=p){i++;}
                               else{break;}
                               
                  }
             if(i==N){break;}
                
            if(v[i].a<=p)
            {
                   p=v[i].b;     
            }
            else
            {   
                     
                     q=v[i].a-p;
                     if(q>idle){idle=q;}
                     p=v[i].b;
            }
              
     }
     e=v[0].a;
     for(p=v[0].b,i=0;i<N;)
     {  
            i++;
            for(;i<N;)
                  {
                               if(v[i].b<=p){i++;}
                               else{break;}
                               
                  }
             if(i==N){f=p-e;if(f>work){work=f;}
                      break;}
                
            if(v[i].a<=p)
            {
                   p=v[i].b;     
            }
            else
            {   
                     f=p-e;
                     q=v[i].a-p;
                     if(q>idle){idle=q;}
                     if(f>work){work=f;};
                     p=v[i].b;
                     e=v[i].a;
            }
              
     } 
}
                              
                  
