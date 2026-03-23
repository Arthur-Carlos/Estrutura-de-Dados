#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *v1, int *v2, size_t size)
{
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++)
    {
        if (v1[j] <= v2[k])
        {
            v[i] = v1[j++];
        }
        else
        {
            v[i] = v2[k++];
        }
    }
    while (j < size_v1)
    {
        v[i++] = v1[j++];
    }
    while (k < size_v2)
    {
        v[i++] = v2[k++];
    }
}

void mergesort(int *v, size_t size)
{
    size_t mid;
    if (size > 1)
    {
        mid = size / 2;
        int *v1 = malloc(sizeof(int) * mid);
        int *v2 = malloc(sizeof(int) * (size - mid));
        size_t i;
        for (i = 0; i < mid; i++)
        {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++)
        {
            v2[i - mid] = v[i];
        }
        mergesort(v1, mid);
        mergesort(v2, size - mid);
        merge(v, v1, v2, size);
        free(v1);
        free(v2);
    }
}

int busca(int *v, int tam, int maes, int maior)
{
    int l = 0, r = maior, res;
    while (l <= r)
    {
        int meio = (l + r) / 2;
        int total = 0;
        for (int i = 0; i < tam; i++)
        {
            total += v[i] / meio;
            if (total >= maes)
            {
                break;
            }
        }
        if (total >= maes)
        {
            res = meio;
            l = meio + 1;
        }
        else
        {
            r = meio - 1;
        }
    }
    return res;
}

int main()
{
    int caixas, maes, maior = 0;
    scanf("%d %d", &caixas, &maes);
    int *vet = malloc(sizeof(int) * caixas);
    for (int i = 0; i < caixas; i++)
    {
        scanf("%d", &vet[i]);
        if (vet[i] > maior)
        {
            maior = vet[i];
        }
    }
    int res = busca(vet, caixas, maes, maior);
    printf("%d\n", res);
    return 0;
}