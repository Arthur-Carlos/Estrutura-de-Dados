#include <stdio.h>
#include <stdlib.h>

long long *busca_inferior(long long *ini, long long *fim, int x)
{
    long long *res = NULL;
    while (ini <= fim)
    {
        long long *meio = ini + (fim - ini) / 2;
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

long long *busca_superior(long long *ini, long long *fim, int x)
{
    long long *res = NULL;
    while (ini <= fim)
    {
        long long *meio = ini + (fim - ini) / 2;
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

int compara(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y)
    {
        return -1;
    }
    if (x > y)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int entrada, perguntas;
    scanf("%d %d", &entrada, &perguntas);
    long long *sequencia = malloc(entrada * sizeof(long long));
    for (int i = 0; i < entrada; i++)
    {
        scanf("%lld", &sequencia[i]);
    }
    qsort(sequencia, entrada, sizeof(long long), compara);
    for (int i = 0; i < perguntas; i++)
    {
        long long x;
        scanf("%lld", &x);
        long long *ini = sequencia;
        long long *fim = sequencia + entrada - 1;
        long long *l_ptr = busca_inferior(ini, fim, x);
        long long *r_ptr = busca_superior(ini, fim, x);
        if (!l_ptr || !r_ptr)
        {
            printf("-1\n");
        }
        else
        {
            long long l = (l_ptr - sequencia) + 1;
            long long r = (r_ptr - sequencia) + 1;
            printf("%lld %lld\n", l, r);
        }
    }
    free(sequencia);
    return 0;
}