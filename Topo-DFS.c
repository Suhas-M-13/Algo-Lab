//Implement DFS based topological sorting in directed graph
#include<stdio.h>
#include<stdlib.h>
int n;
int stk[20],top=-1;

void checkdir(int a[n][n])
{
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		if(a[i][j]&&a[j][i])
		{
			printf("Graph is Undirected\nTopological sorting is not possible\n");
			exit(0);
		}
	}
}
}

void checkcyc(int a[n][n])
{
int i,j,k;
int r[n][n];
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		r[i][j]=a[i][j];
}
for(k=0;k<n;k++)
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			r[i][j]=r[i][j]||(r[i][k]&&r[k][j]);
	}
}
for(i=0;i<n;i++)
{
	if(r[i][i])
	{
		printf("Graph is cyclic\nTopological sorting is not possible\n");
		exit(0);
	}
}
}

void dfs(int w, int a[n][n], int v[n])
{
v[w]=1;
for(int i=0;i<n;i++)
{
	if(a[w][i]&&!v[i])
		dfs(i,a,v);
}
stk[++top]=w;
}

void main()
{
int i,j;
printf("Enter the number of vertices: ");
scanf("%d",&n);
int a[n][n], v[n];
printf("Enter the adjacency matrix:\n");
for(i=0;i<n;i++)
{
	v[i]=0;
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
}
checkdir(a);
checkcyc(a);
printf("\nTopological Sorting:\n");
for(i=0;i<n;i++)
{
	if(!v[i])
		dfs(i,a,v);
}
for(i=top;i>=0;i--)
printf("%d ",stk[i]+1);
printf("\n");
}