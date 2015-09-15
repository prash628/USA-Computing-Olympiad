/*
ID: prash621
PROG: beads
LANG: C++
*/
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
int N;
string str;
int func();
int splcase();
int lpadb;
int lpadr;
int rpadb;
int rpadr;
void findpads();
int dafunc();
int main()
{
    int res;
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    fin>>N;
    fin>>str;
    res=func();
    fout<<res<<endl;                  
    return(0);
} 
int func()
{
    int x;
    if(splcase())
    {
               return(N);
    }
    else
    {
        findpads();       
        x=dafunc();
        return(x);
    }
}
int splcase()
{
     char firstcol,secondcol;int temp;
    int chkr=0;int chkb=0;int cnt=0;
    int i;
    for(i=0;i<N;i++)
    {
                    if(chkr==0&&str[i]=='r'){chkr++;cnt++;}
                    if(chkb==0&&str[i]=='b'){chkb++;cnt++;}
                    if(cnt==2){i=N;}
    }
    if(cnt<2){return(1);}
                
         for(i=0;i<N;i++)
         {
             if(str[i]!='w'){firstcol=str[i];temp=i;i=N;}            
         }
         for(i=1+temp;i<N;i++)
         {
                              if(str[i]!=firstcol&&str[i]!='w'){secondcol=str[i];temp=i;i=N;}
         }
         for(i=1+temp;i<N;i++)
         {
                              if(str[i]!=secondcol&&str[i]!='w'){return(0);}
         }
         if(i==N){return(1);}
                              
                 
    if(cnt>=2){return(0);}
}
void findpads()
{
     int count,i;
     
     /*Finding lpadr*/
     for(count=0,i=N-1;i>=0;i--)
     {
                        if(str[i]!='b'){count++;}
                        else{i=-1;}
     }                                                     
     lpadr=count;
     
     /*Finding lpadb*/
     for(count=0,i=N-1;i>=0;i--)
     {
                        if(str[i]!='r'){count++;}
                        else{i=-1;}
     }
     lpadb=count;
                            
     /*Finding rpadr*/
     for(count=0,i=0;i<N;i++)
     {
                             if(str[i]!='b'){count++;}
                             else{i=N;}
     }
     rpadr=count;
                                                              
     /*Finding rpadb*/
     for(count=0,i=0;i<N;i++)
     {
                             if(str[i]!='r'){count++;}
                             else{i=N;}
     }                                                          
     rpadb=count;    
}
int dafunc()
{
    int i,j,lval,rval;
    int total,max;
    char col,nxtcol;
    for(i=0;i<N;)
    {
                
                
       /*Finding lval*/
       if(i==0){if(lpadr>lpadb){lval=lpadr;}
                                   else{lval=lpadb;}
               }
       else
       {    
                 col=str[i-1];
                 if(col=='w')
                 {  
                    lval=0;
                    nxtcol='w';
                    for(j=i-1;j>=0;j--)
                    {
                                     if(str[j]!='w'){nxtcol=str[j];j=-1;}
                    }                                                          
                    if(j==-1&&nxtcol=='w')
                    {
                                   if(lpadr>lpadb){lval=lpadr;}
                                   else{lval=lpadb;}
                    }
                      for(j=i-1;j>=0;j--)
                      {
                                     if(str[j]=='w'||str[j]==nxtcol){lval++;}
                                     else{j=-1;}
                                     
                      } 
                 } 
                 else
                 {
                        col=str[i-1];
                        lval=0;
                        for(j=i-1;j>=0;j--)
                        {
                                     if(str[j]=='w'||str[j]==col){lval++;}
                                     else{j=-10;}              
                        }                        
                        if(j==-1)
                        {
                                 if(col=='b'){lval=lval+lpadb;}
                                 else{lval=lval+lpadr;}
                        }
                 }
       }          
       
       /*Finding rval*/ 
    if(i==N-1){col=str[i];
               if(col=='b'){rval=rpadb;}
                                   else{rval=rpadr;}
                                   rval=rval+1;
               }
    else
    {
       col=str[i];
       if(col=='w')
                 {
                    nxtcol='w';
                    for(j=i+1;j<N;j++)
                    {
                                     if(str[j]!='w'){nxtcol=str[j];j=N;}
                                     
                    } 
                                                                                    
                    if(nxtcol=='w')
                    {
                                   if(rpadr>rpadb){rval=rpadr;}
                                   else{rval=rpadb;}
                    }
                    else
                    {
                      rval=0;
                      for(j=i;j<N;j++)
                      {
                                     if(str[j]=='w'||str[j]==nxtcol){rval++;}
                                     else{j=N;}                
                      }
                    }
                 } 
       else
                 {
                        rval=0;
                        for(j=i+1;j<N;j++)
                        {
                                     if(str[j]=='w'||str[j]==col){rval++;}
                                     else{j=N+20;}
                                     
                        }                        
                        if(j==N)
                        {
                                 if(col=='b'){rval=rval+rpadb;}
                                 else{rval=rval+rpadr;}
                        }
                        rval=rval+1; 
                 }
    }        
    total=rval+lval;                                                
     if(i==0){max=total;}
     else{if(total>max){max=total;}}
     i=i+1;
  }
  return(max);
} 
                  
