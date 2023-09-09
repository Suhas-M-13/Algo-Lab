#include<stdio.h>
#include<stdlib.h>
int count;
FILE *fp1,*fp2;

void worstmerge(int *b,int *c,int *a,int p,int q,int n)
{
int i=0,j=0,k=0;
while(j!=p)
a[i++]=b[j++];
while(k!=q)
a[i++]=c[k++];
}

void worstcase(int *a,int n)
{
int *b,*c;
int i=0,j=0,k=0;
b=(int*)malloc(sizeof(int)*(n/2));
c=(int*)malloc(sizeof(int)*(n-(n/2)));
if(n>1)
{
  while(i<n)
  {
    if(i%2==0)
    b[j++]=a[i++];
    else
    c[k++]=a[i++];
  }
  worstcase(b,(n/2));
  worstcase(c,(n-(n/2)));
  worstmerge(b,c,a,(n/2),(n-(n/2)),n);
}
}

void merge(int *b,int *c,int *a,int p,int q,int n)
{
int i=0,j=0,k=0;
while(i<p&&j<q)
{
count++;
if(b[i]<=c[j])
a[k++]=b[i++];
else
a[k++]=c[j++];
}
while(i!=p)
a[k++]=b[i++];
while(j!=q)
a[k++]=c[j++];
}

void Mergesort(int *a,int n)
{
int *b,*c,i,j,k;
b=(int*)malloc(sizeof(int)*(n/2));
c=(int*)malloc(sizeof(int)*(n-(n/2)));

if(n>1)
{
  for(i=0;i<(n/2);i++)
    b[i]=a[i];
  for(i=(n/2),j=0;i<n;i++,j++)                                                                                                                
    c[j]=a[i];

  Mergesort(b,(n/2));
  Mergesort(c,(n-(n/2)));
  merge(b,c,a,(n/2),(n-(n/2)),n);
}
}

void print(int *a,int n)
{
int j;
for(j=0;j<n;j++)
fprintf(fp1,"%d\t",a[j]);
}

void bestcaseinput(int *a,int n)
{
int j;
a[n-1]=(rand()+1)%1000;
for(j=n-2;j>=0;j--)
a[j]=a[j+1]+(rand()+1)%1000;
}

void averagecaseinput(int *a,int n)
{
int i;
for(i=0;i<n;i++)
a[i]=(rand()+1)%1000;
}

void worstcaseinput(int *a,int n)
{
int i;
a[0]=(rand()+1)%1000;
for(i=1;i<n;i++)
a[i]=a[i-1]+(rand()+1)%1000;
worstcase(a,n);
}
void main()
{
int *a,i,j,k;
srand(0);
fp1=fopen("MergeSort.txt","w");
fp2=fopen("MergeSortcount.txt","w");
fprintf(fp2,"N\tB\tA\tW\n");
for(i=10;i<=100;i=i+10)
{
count=0;
fprintf(fp2,"%d ",i);
a=(int*)malloc(sizeof(int)*i);
bestcaseinput(a,i);
fprintf(fp1,"Array before sorting: ");
print(a,i);
Mergesort(a,i);
fprintf(fp1,"\nArray after sorting: ");
print(a,i);
fprintf(fp2,"%d\t",count);
count=0;
averagecaseinput(a,i);
fprintf(fp1,"\n\nArray before sorting: ");
print(a,i);
Mergesort(a,i);
fprintf(fp1,"\nArray after sorting: ");
print(a,i);
fprintf(fp2,"%d\t",count);

count=0;
worstcaseinput(a,i);
fprintf(fp1,"\n\nArray before sorting: ");
print(a,i);
Mergesort(a,i);
fprintf(fp1,"\nArray after sorting: ");
print(a,i);
fprintf(fp2,"%d\n",count);
fprintf(fp1,"\n\n\n");
}
fclose(fp1);
fclose(fp2);
}

