// Implement Quick Sort
#include <stdio.h>
#include <stdlib.h>
int count = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int l, int r)
{
    int i = l, j = r + 1, p = a[l];
    do
    {
        do
        {
            i++;
            count++;
        } while (p > a[i] && i <= r);
        do
        {
            j--;
            count++;
        } while (p < a[j] && j >= l);
        swap(&a[i], &a[j]);
    } while (i <= j);
    swap(&a[i], &a[j]);
    swap(&a[l], &a[j]);
    return j;
}
void quicksort(int *a, int l, int r)
{
    if (l < r)
    {
        int s = partition(a, l, r);
        quicksort(a, l, s - 1);
        quicksort(a, s + 1, r);
    }
}
int main()
{
    FILE *f;
    int *a;
    f = fopen("Quick.txt", "w");
    for (int n = 10; n <= 100; n += 10)
    {
        a = (int *)malloc(sizeof(int) * n);
        // Best Case
        count = 0;
        a[0] = rand() % 100;
        for (int i = 1; i < n; i++)
            a[i] = a[0];
        quicksort(a, 0, n - 1);
        fprintf(f, "%d\t%d\t", n, count);
        // Average Case
        count = 0;
        for (int i = 0; i < n; i++)
            a[i] = rand() % 100;
        quicksort(a, 0, n - 1);
        fprintf(f, "%d\t", count);
        // Worst Case
        count = 0;
        a[0] = rand() % 100;
        for (int i = 1; i < n; i++)
            a[i] = a[i - 1] + rand() % 100;
        quicksort(a, 0, n - 1);
        fprintf(f, "%d\n", count);
    }
    free(a);
    fclose(f);
    return 0;
}