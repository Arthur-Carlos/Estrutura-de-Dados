#include <stdio.h>
#include <stdlib.h>

int divisor;

int compara(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;

    int rx = x % divisor;
    int ry = y % divisor;

    if (rx != ry)
        return rx - ry;

    int parX = (x % 2 == 0);
    int parY = (y % 2 == 0);

    if (parX != parY)
    {
        return parX - parY;
    }

    if (parX && parY)
    {
        return (x > y) - (x < y);
    }

    if (!parX && !parY)
    {
        return (y > x) - (y < x);
    }

    return 0;
}

int main()
{
    int entrada;
    scanf("%d %d", &entrada, &divisor);

    int *Inteiros = malloc(entrada * sizeof(int));

    for (int i = 0; i < entrada; i++)
    {
        scanf("%d", &Inteiros[i]);
    }

    qsort(Inteiros, entrada, sizeof(int), compara);

    for (int i = 0; i < entrada; i++)
    {
        printf("%d\n", Inteiros[i]);
    }

    free(Inteiros);
    return 0;
}
