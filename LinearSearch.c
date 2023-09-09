
#include<stdio.h>
#include<stdlib.h>
#define x 5
#define y 50
#define z 5
FILE *fp1,*fp2;
void printfile(int*,int,int);
void linearsearch(int*,int,int);
void main()
{
    srand(0);
    int *a,key,j;
    fp1=fopen("linearlist.txt","w");
    fp2=fopen("linearcount.txt","w");
    fprintf(fp2,"\tN\tBEST\tWORST\tAVGERAGE\n");
    for(int i=x;i<=y;i=i+z)
    {
        a=(int*)malloc(i*sizeof(int));
        for(int j=0;j<i;j++)
        a[j]=rand()%100;

        fprintf(fp2,"\t%d",i);
        key=*(a+0); //best
        printfile(a,i,key);
        linearsearch(a,i,key);

        key=9999; //worst
        printfile(a,i,key);
        linearsearch(a,i,key);
        
        key=a[(i-1)/2]; //average
        printfile(a,i,key);
        linearsearch(a,i,key);
        fprintf(fp2,"\n");
    }
    fclose(fp1);
    fclose(fp2);

}
void linearsearch(int *a,int n,int key)
{
    int count=0;
    for(int j=0;j<n;j++)
        {
            count++;
            if(*(a+j)==key)
            break;
        }
        fprintf(fp2,"\t%d",count);
}
void printfile(int *a,int n,int key)
{
    for(int j=0;j<n;j++)
        {
            fprintf(fp1,"%d\t",*(a+j));
        }
        fprintf(fp1,"\nSearch Key:%d\n",key);
}