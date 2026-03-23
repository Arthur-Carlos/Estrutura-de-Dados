#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int valor;
    int pos;
} Elemento;

void swap(Elemento *v, int i, int j)
{
    Elemento t = v[i];
    v[i] = v[j];
    v[j] = t;
}

int partition(Elemento *v, int l, int r)
{
    int pivot = v[r].valor;
    int pos = l;

    for (int i = l; i < r; i++)
    {
        if (v[i].valor <= pivot)
        {
            swap(v, i, pos);
            pos++;
        }
    }

    swap(v, pos, r);
    return pos;
}

void quick_sort_helper(Elemento *v, int l, int r)
{
    if (l < r)
    {
        int pos = partition(v, l, r);

        if (pos > 0)
            quick_sort_helper(v, l, pos - 1);

        quick_sort_helper(v, pos + 1, r);
    }
}

void quick_sort(Elemento *v, int size)
{
    quick_sort_helper(v, 0, size - 1);
}

int main()
{
    int n, C;
    scanf("%d %d", &n, &C);

    Elemento *vet = malloc(n * sizeof(Elemento));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i].valor);
        vet[i].pos = i + 1;
    }

    quick_sort(vet, n);

    int i = 0, j = n - 1;
    while (i < j)
    {
        int soma = (int)vet[i].valor + vet[j].valor;

        if (soma == C)
        {
            printf("%d %d\n", vet[i].pos, vet[j].pos);
            free(vet);
            return 0;
        }
        else if (soma < C)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    printf("-1\n");

    free(vet);
    return 0;
}