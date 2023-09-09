#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int count=0;
void swap(int *a, int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void heapify(int *a, int n, int i)
{
	bool heap=false;
	int k=i, p=a[k], j;
	count++;
	while(!heap && 2*k<=n)
	{
		count++;
		j=2*k;
		if(j<=n)
		{
			if(a[j]<a[j+1]&&(j+1)<=n)
			{
				j=j+1;
			}
			if(p>=a[j])
			heap=true;
			else
			{
				a[k]=a[j];
				k=j;
			}
			a[k]=p;
		}
	}
}
void heapthesort(int *a, int n)
{
	int i,j;
	for(i=n/2;i>=1;i--)
	{
		heapify(a,n,i);
	}
	for(i=n;i>1;i--)
	{
		swap(&a[i],&a[1]);
		heapify(a,i-1,1);
	}
}

FILE *f;
int main()
{
	int *a, i, j, n;
	f=fopen("Heap.txt","w");
	fprintf(f,"N\tB\tA\tW\n");
	for(n=10;n<=100;n+=10)
	{
		a=(int *)malloc((n+1)*sizeof(int));
		//Best Case
		count=0;
		for(i=1;i<=n;i++)
		a[i]=(n+1)-i;
		heapthesort(a,n);
		fprintf(f,"%d\t%d\t",n,count);
		//Avg case
		count=0;
		for(i=1;i<=n;i++)
		a[i]=rand()%1000;
		heapthesort(a,n);
		fprintf(f,"%d\t",count);
		//Worst
		count=0;
		a[1]=rand()%1000;
		for(i=2;i<=n;i++)
		{
			a[i]=a[i-1]+rand()%1000;
		}
		heapthesort(a,n);
		fprintf(f,"%d\n",count);
	}
	fclose(f);
return 0;
}