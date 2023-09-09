//Implement and analyse Selection Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *fc, *f1;

void Selsort(int *a, int n)
{
    int i, j, min, t, count=0;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            count++;
            if(a[j]<a[min])
            {
                min=j;
            }
            
        }
        t=a[i];
        a[i]=a[min];
        a[min]=t;
        
    }
    fprintf(fc,"%d\t%d\n",n,count);
}
int main()
{
    int *a, n, i;
    f1=fopen("SelSort.txt","w");
    fc=fopen("SelsortCount.txt","w");
    srand(time(0));
    for(n=10;n<=100;n+=10)
    {
        a=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            a[i]=rand()%100;
            fprintf(f1,"%d\t",a[i]);
        }
        Selsort(a,n);
        fprintf(f1,"\n");
        for(int j=0;j<n;j++)
        fprintf(f1,"%d\t",a[j]);
        fprintf(f1,"\n");
    }
    fclose(f1);
    fclose(fc);
return 0;
}