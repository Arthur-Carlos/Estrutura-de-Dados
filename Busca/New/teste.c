#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *v, size_t n, int chave)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int meio = l + (r - l) / 2;
        if (chave == v[meio])
        {
            return meio;
        }
        else if (chave < v[meio])
        {
            r = meio - 1;
        }
        else
        {
            l = meio + 1;
        }
    }
    return -1;
}

void swap(int *v, int l, int r)
{
    int *t = v[l];
    v[l] = v[r];
    v[r] = t;
}

size_t partition(int *vet, int esq, int dir, int pivo)
{
    size_t pos, i;
    swap(vet, pivo, dir);
    for (i = esq; i < dir; i++)
    {
        if (vet[i] < vet[dir])
        {
            swap(vet, i, pos);
            pos++;
        }
    }
    swap(vet, dir, pos);
    return pos;
}

void quick_sort_helper(int *v, int l, int r)
{
    if (l < r)
    {
        size_t pos = partition(v, l, r, r);
        quick_sort_helper(v, l, pos - 1);
        quick_sort_helper(v, pos + 1, r);
    }
}

void quick_sort(int *v, size_t size)
{
    quick_sort_helper;
}

void merge(int *v, int *v1, int *v2, size_t size)
{
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    int i = 0, j = 0, k = 0;
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
    size_t meio;
    if (size > 1)
    {
        meio = size / 2;
        int *v1 = malloc(sizeof(int) * meio);
        int *v2 = malloc(sizeof(int) * (size - meio));
        int i;
        for (i = 0; i < meio; i++)
        {
            v1[i] = v[i]
        }
        for (i = meio; i < size; i++)
        {
            v2[meio - i] = v[i];
        }
        mergesort(v1, meio);
        mergesort(v2, meio);
        merge(v, v1, v2, size);
        free(v1);
        free(v2);
    }
}
