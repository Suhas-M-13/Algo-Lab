//Implement Sequential Search 
#include<stdio.h>
#include<stdlib.h>
FILE *f, *fc;
int count=0;
void sequential(int a[], int n, int key)
{
    count=0;
    for(int i=0;i<n;i++)
    {
        count++;
        if(a[i]==key)
        {
            break;
        }
    }
    fprintf(fc, "%d\t",count);
}
int main()
{
    int *a, n, key;
    f=fopen("SeqSeaArr.txt","w");
    fc=fopen("SeqSeaCount.txt","w");
    for(int n=5;n<=50;n+=5)
    {
        a=(int *)malloc(n*sizeof(int)); 
        fprintf(f,"Array : ");
        for(int j=0;j<n;j++)
        {
            a[j]=rand()%10000;
            fprintf(f,"%d\t",a[j]);
        }  
        fprintf(f, "\n");
        //For Best Case
        key=a[0];
        sequential(a,n,key);
        //For average case
        key=a[n/2];
        sequential(a,n,key);
        //For Worst case
        key=999;
        sequential(a,n,key);
        fprintf(fc,"\n");
    }
return 0;
}