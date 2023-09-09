//Implement Binary Search
#include<stdio.h>
#include<stdlib.h>
FILE  *f1, *f2;
int count=0;
void display(int *a, int n, int key)
{
    fprintf(f1,"Array : ");
    for(int i=0;i<n;i++)
    fprintf(f1,"%d\t",a[i]);
    fprintf(f1,"\nKey=%d\n",key);
}
int binary(int *a, int key, int l, int r)
{
    count++;
    int mid=(l+r)/2;
    if(l>r)
    return -1;
    if(a[mid]==key)
    return mid;
    else if(a[mid]<key)
    return binary(a,key,mid+1,r);
    else
    return binary(a,key,l,mid-1);
}
int main()
{
    srand(0);
    int *a, key, pos, i, n;
    f1=fopen("BinarySearchArr.txt","w");
    f2=fopen("BinarySearchCnt.txt","w");
    fprintf(f2,"N\tB\tA\tW\n");
    for(n=5;n<=50;n+=5)
    {
        a=(int*)malloc(n*sizeof(int));
        //Best Case
        count=0;
        a[0]=rand()%1000;
        for(i=1;i<n;i++)
        a[i]=a[i-1]+rand()%1000;
        
        key=a[(i-1)/2];
        display(a,n,key);
        pos=binary(a,key,0,n-1);
        fprintf(f2,"%d\t%d\t",i,count);
        count=0;
        //Avg Case
        key=a[(i-1)/4];
        display(a,n,key);
        pos=binary(a,key,0,n-1);
        fprintf(f2,"%d\t",count);
        //Worst case
        count=0;
        key=9999;
        display(a,n,key);
        pos=binary(a,key,0,n-1);
        fprintf(f2,"%d\n",count);
    }
    return 0;
}