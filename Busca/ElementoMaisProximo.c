#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b)
{
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
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

int busca(long long *vetor, int entrada, long long x)
{
    int esq = 0, dir = entrada - 1;
    while (esq <= dir)
    {
        int meio = (esq + dir) / 2;
        if (vetor[meio] == x)
        {
            return meio;
        }
        else if (vetor[meio] < x)
        {
            esq = meio + 1;
        }
        else
        {
            dir = meio - 1;
        }
    }
    return -1;
}

int main()
{
    int entrada, questoes;
    scanf("%d %d", &entrada, &questoes);

    long long *vetor = malloc(entrada * sizeof(long long));
    for (int i = 0; i < entrada; i++)
    {
        scanf("%lld", &vetor[i]);
    }

    qsort(vetor, entrada, sizeof(long long), compara);

    while (questoes--)
    {
        long long x;
        scanf("%lld", &x);

        int pos = busca(vetor, entrada, x);
        long long melhor = -1;

        if (pos > 0)
        {
            melhor = vetor[pos - 1];
        }

        if (pos < entrada - 1)
        {
            long long candidato = vetor[pos + 1];
            if (melhor == -1)
            {
                melhor = candidato;
            }
            else
            {
                long long dist_esq = llabs(vetor[pos] - melhor);
                long long dist_dir = llabs(vetor[pos] - candidato);

                if (dist_dir < dist_esq)
                {
                    melhor = candidato;
                }
                else if (dist_dir == dist_esq && candidato < melhor)
                {
                    melhor = candidato;
                }
            }
        }

        printf("%lld\n", melhor);
    }

    free(vetor);
    return 0;
}
