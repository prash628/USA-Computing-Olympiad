/*
ID: prash621
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>
struct mytype
{
    char name[14];
    int mdonate;
    int mrec;
    int no;
}group[10];
int np;  //No of memebers
FILE *fin;
FILE *fout;
int findindex(char nom[14]);
void startdonating(int pos);
void printres();
main () 
{ 
    fin=fopen("gift1.in", "r");
    fout=fopen("gift1.out", "w");
    char namechk[14];
    int index;
    int i;
    int x,y;
    
    fscanf(fin,"%d",&np);
    for(i=0;i<np;i++){fscanf(fin,"%s",group[i].name);group[i].mrec=0;}
    for(i=0;i<np;i++)
    {
                     fscanf(fin,"%s",namechk);
                     index=findindex(namechk);
                     fscanf(fin,"%d %d",&x,&y);
                     group[index].mdonate=x;
                     group[index].no=y;  
                     if(y!=0){startdonating(index);}
    } 
    printres();
    exit (0);
}
int findindex(char nom[14])
{
    int i;
    for(i=0;i<np;i++)
    {
                     if((strcmp(nom,group[i].name))==0){return(i);}
    }
}
void startdonating(int pos)
{
     char name1[14];
     int index;
     int notdonatin;
     int part=(group[pos].mdonate)/(group[pos].no);
     notdonatin=group[pos].mdonate-(part*(group[pos].no));
     group[pos].mdonate=group[pos].mdonate-notdonatin;
     int x=group[pos].no;
     int i;  
     for(i=0;i<x;i++)
     { 
                     fscanf(fin,"%s",name1);
                     index=findindex(name1);
                     group[index].mrec+=part;
     }
}     
void printres()
{
      int i;
      int val;
      for(i=0;i<np;i++)
      {
              fprintf(fout,"%s ",group[i].name);
              val=(group[i].mrec)-(group[i].mdonate);
              fprintf(fout,"%d\n",val);
      }
}              
      
