#include <stdio.h>
#include <stdlib.h>
FILE *fp;
int count;
void stringmatch(char *a, int n, char *p, int m)
{
    int i, j;
    for (i = 0; i <= (n - m); i++)
    {
        for (j = 0; j < m; j++)
        {
            count++;
            if (p[j] != a[i + j])
                break;
        }
        if (j == m)
            break;
    }
}

void patstr(char *p, int m)
{
    for (int i = 0; i < m; i++)
        p[i] = 'h';
}

void main()
{
    char *a, *p;
    int n, i, j, m;
    fp = fopen("StringMatching.txt", "w");
    fprintf(fp, "N B A W\n");
    for (i = 10; i <= 100; i = i + 10)
    {
        a = (char *)malloc(sizeof(char) * i);
        m = i / 2;
        p = (char *)malloc(sizeof(char) * m);
        
        for (j = 0; j < i; j++)
            a[j] = 'h';
        
        count = 0;
        fprintf(fp, "%d ", i);
        patstr(p, m);
        stringmatch(a, i, p, m);
        fprintf(fp, "%d ", count);

        patstr(p, m);
        p[(m - 1) / 2] = 'l';
        count = 0;
        stringmatch(a, i, p, m);
        fprintf(fp, "%d ", count);
        
        patstr(p, m);
        p[m - 1] = 'l';
        count = 0;
        stringmatch(a, i, p, m);
        fprintf(fp, "%d ", count);
        fprintf(fp, "\n");
    }
    fclose(fp);
}