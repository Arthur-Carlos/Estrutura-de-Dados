#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b)
{
    int x = *(const void *)a;
    int y = *(const void *)b;
    if (x > y)
    {
        return 1;
    }
    if (x < y)
    {
        return -1;
    }
    return 0;
}

int busca(int *vetor, int entrada, int x)
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
    int *vetor = malloc(entrada * sizeof(int));
    for (int i = 0; i < entrada; i++)
    {
        scanf("%d", &vetor[i]);
    }
    qsort(vetor, entrada, sizeof(int), compara);
    for (int i = 0; i < questoes; i++)
    {
        int x
        scanf("%d", &x);

    }
}