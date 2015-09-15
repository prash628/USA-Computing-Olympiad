/*
ID: prash621
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <string.h>
int compute(char *x,int len);
main () 
{
    char ipc[6];
    char ipg[6];
    int ipcl,ipgl;
    int commod,grpmod;
    FILE *fin=fopen("ride.in","r");
    FILE *fout=fopen("ride.out","w");
    fscanf(fin,"%s",ipc);
    ipcl=strlen(ipc);
    fscanf(fin,"%s",ipg);
    ipgl=strlen(ipg);
    commod=compute(ipc,ipcl);
    grpmod=compute(ipg,ipgl);
    if(commod==grpmod){fprintf(fout,"GO\n");}
    else{fprintf(fout,"STAY\n");}
    exit (0);
}
int compute(char x[6],int len)
{
    int i;int modval;
    int res=1;int temp;
    for(i=0;i<len;i++)
    {
        temp=x[i];
        temp=temp-64;
        res=res*temp;
    }
    modval=res%47;
    return(modval);
} 
