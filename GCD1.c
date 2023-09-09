//Implement various method included in finding GCD of two numbers
#include<stdio.h>
#include<stdlib.h>
FILE *fc;
int count=0;
void GCDEu(int m, int n)
{
    count=0;
    int r;
    fprintf(fc,"%d\t%d\t",m,n);
    while(n!=0)
    {
        count++;
        r=m%n;
        m=n;
        n=r;
    }
    fprintf(fc,"%d\t%d\t",m,count);
}
void GCDS(int m, int n)
{
    count=0;
    while(m!=n)
    {
        count++;
        if(m>n)
        m-=n;
        else
        n-=m;
    }
    fprintf(fc, "%d\t",count);
}
void GCDC(int m, int n)
{
    count=0;
    int min=(m>n)?n:m;
    while(min!=1)
    {
        count++;
        if(m%min==0)
        {
            if(n%min==0)
            {
                break;
            }
        }
        min--;
    }
    fprintf(fc,"%d\n",count);
}
int main()
{
    fc=fopen("GCDCount1.txt","w");
    fprintf(fc,"M\tN\tGCD\tC1\tC2\tC3\n");
    for(int i=0;i<10;i++)
    {
        int m=rand()%1000;
        int n=m+rand()%1000;
        GCDEu(m,n);
        GCDS(m,n);
        GCDC(m,n);
    }
    return 0;
}