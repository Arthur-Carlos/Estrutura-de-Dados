#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int *buscasup(int *ini, int *fim, int x)
{
    int *res = NULL;
    while (ini <= fim)
    {
        int *meio = ini + (fim - ini) / 2;
        if (*meio == x)
        {
            res = meio;
            ini = meio + 1;
        }
        else if (*meio < x)
        {
            ini = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return res;
}

int *buscainf(int *ini, int *fim, int x)
{
    int *res = NULL;
    while (ini <= fim)
    {
        int *meio = ini + (fim - ini) / 2;
        if (*meio == x)
        {
            res = meio;
            fim = meio - 1;
        }
        else if (*meio < x)
        {
            ini = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return res;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int *vet = malloc(n * sizeof(int));
    if (!vet) return 1;

    for (int i = 0; i < n; i++)
        scanf("%d", &vet[i]);

    qsort(vet, n, sizeof(int), cmp);

    int *ini = vet;
    int *fim = vet + n - 1;

    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);

        int *inf = buscainf(ini, fim, x);
        int *sup = buscasup(ini, fim, x);

        if (!inf)
        {
            printf("-1\n");
        }
        else
        {
            int l = (inf - vet) + 1;
            int r = (sup - vet) + 1;
            printf("%d %d\n", l, r);
        }
    }

    free(vet);
    return 0;
}