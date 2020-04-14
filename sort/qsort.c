//C中的快排api
#include <stdlib.h>
#include <stdio.h>

int intcomp(const void *x, const void *y)
{
    return *((int *)x) - *((int *)y);
}

int a[1000000];

int main(void)
{
    int i, n = 0;

    while (scanf("%d", &a[n]) != EOF)
    {
        n++;
    }

    qsort(a, n, sizeof(int), intcomp);

    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}