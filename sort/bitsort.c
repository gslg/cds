//C中的快排api
#include <stdlib.h>
#include <stdio.h>
#include "bit_func.h"

int a[1000000];

int main(void)
{
    int i;

    for (i = 0; i < N; i++)
    {
        clr(i);
    }

    while (scanf("%d", &i) != EOF)
    {
        set(i);
    }
    for (i = 0; i < N; i++)
    {
        if (test(i))
            printf("%d\n", i);
    }

    return 0;
}