#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int x = abs(*(int *)a);
    int y = abs(*(int *)b);

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *v = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    qsort(v, n, sizeof(int), cmp);

    for (int i = 1; i < n; i++)
    {
        int a = abs(v[i - 1]);
        int b = abs(v[i]);
        if (a == 0)
        {
            if (b != 0)
            {
                printf("Nao\n");
                free(v);
                return 0;
            }
        }
        else
        {
            if (b % a != 0)
            {
                printf("Nao\n");
                free(v);
                return 0;
            }
        }
    }

    printf("Sim\n");
    free(v);
    return 0;
}