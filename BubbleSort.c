//Bubble sort analysis for Best case, average case and worst case
#include<stdio.h>
#include<stdlib.h>
//#include<time.h>
#define x 10
#define y 100
#define inc 10
FILE *f1, *f2;
void bestcaseinput(int *a,int n)
{
    int i;
    a[0]=rand()%100;
    for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]+rand()%100;
        }
}
void worstcaseinput(int *a,int n)
{
    int i;
    a[n-1]=rand()%100;
    for(i=n-2;i>=0;i--)
    a[i]=a[i+1]+rand()%100;
}
void averagecaseinput(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    a[i]=rand()%100;
}
void bubblesort(int *a,int n)
{
    int count=0,flag,temp;
    for(int i=0;i<n-1;i++)
        {
       
            flag=0;
            for(int j=0;j<n-i-1;j++)
            {
              count++;
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    flag=1;
                }
            }
            if(flag==0)
                    break;
        }
        fprintf(f2,"%d ",count);
}
void print(int *a,int n)
{
    for(int i=0;i<n;i++)
        {
            fprintf(f1,"%d\t",a[i]);
        }
}
void main()
{
    int *a;
    int n;
    f1=fopen("bubblesortlist.txt","w");
    f2=fopen("bubblesortcount.txt","w");
    srand(0);
    fprintf(f2,"N B W A\n");
    for(n=x;n<=y;n=n+inc)
    {
        fprintf(f2,"%d ",n);
        a=(int*)malloc(n*sizeof(int));
        bestcaseinput(a,n);
        fprintf(f1,"Array beforing sorting: ");
        print(a,n);
        bubblesort(a,n);
        fprintf(f1,"\nArray after sorting: ");
        print(a,n);
        fprintf(f1,"\n");
        fprintf(f1,"Array beforing sorting: ");
        worstcaseinput(a,n);
        print(a,n);
        bubblesort(a,n);
        fprintf(f1,"\nArray after sorting: ");
        print(a,n);
        fprintf(f1,"\n");
        fprintf(f1,"Array beforing sorting: ");
        averagecaseinput(a,n);
        print(a,n);
        bubblesort(a,n);
        fprintf(f1,"\nArray after sorting: ");
        print(a,n);
        fprintf(f1,"\n\n");
        fprintf(f2,"\n"); 
    }
    fclose(f1);
    fclose(f2);
    }
