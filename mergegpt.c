#include <stdio.h>
#include <stdlib.h>

FILE *f;
int count = 0;

void merge(int *, int *, int *, int, int, int);
void mergeSort(int *, int);

void merge(int *b, int *c, int *a, int p, int q, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < p && j < q)
    {
        count++;
        if (b[i] <= c[j])
            a[k++] = b[i++];
        else
            a[k++] = c[j++];
    }
    while (i != p)
    {
        a[k++] = b[i++];
    }
        
    while (j != q)
    {
        a[k++] = c[j++];
    }
}

void mergeSort(int *a, int n)
{
    if (n <= 1)
        return;

    int *b, *c, i, j, k;
    b = (int *)malloc(sizeof(int) * (n / 2));
    c = (int *)malloc(sizeof(int) * (n - (n / 2)));

    for (i = 0; i < n / 2; i++)
        b[i] = a[i];
    for (i = n / 2, j = 0; i < n; i++, j++)
        c[j] = a[i];

    mergeSort(b, n / 2);
    mergeSort(c, n - (n / 2));
    merge(b, c, a, n / 2, n - (n / 2), n);

    free(b);
    free(c);
}

int main()
{
    int *a, i;

    srand(0);
    f = fopen("MergeCount.txt", "w");
    fprintf(f, "N\tB\tA\tW\n");

    for (int n = 10; n <= 100; n += 10)
    {
        a = (int *)malloc(n * sizeof(int));

        // Best case
        count = 0;
        a[0] = rand() % 1000;
        for (i = 1; i < n; i++)
            a[i] = a[i - 1] + rand() % 1000;
        mergeSort(a, n);
        fprintf(f, "%d\t%d\t", n, count);

        // Avg Case
        count = 0;
        for (i = 0; i < n; i++)
            a[i] = rand() % 1000;
        mergeSort(a, n);
        fprintf(f, "%d\t", count);

        // Worst Case
        count = 0;
        for (i = 0; i < n; i++)
            a[i] = rand() % 1000;
        mergeSort(a, n);
        fprintf(f, "%d\n", count);

        free(a);
    }

    fclose(f);
    return 0;
}
