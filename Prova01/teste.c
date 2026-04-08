#include <stdio.h>
#include <stdlib.h>

// refiz ordenando pela ordem e entao pela frequencia porque o meu orginal estava rodando o bgl inteiro no for
/*
    for (int i = 0; i < n; i++)
    {
        int encontrado = 0;

        for (int j = 0; j < tamanho; j++)
        {
            if (elems[j].valor == v[i])
            {
                elems[j].freq++;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            elems[tamanho].valor = v[i];
            elems[tamanho].freq = 1;
            tamanho++;
        }
    }
*/

typedef struct
{
    int valor;
    int freq;
} Elemento;

int compare(Elemento a, Elemento b)
{
    if (a.freq != b.freq)
    {
        return b.freq - a.freq;
    }

    return b.valor - a.valor;
}

int compareInt(int a, int b)
{
    return a - b;
}

static void merge(Elemento *v, Elemento *v1, Elemento *v2, size_t size)
{
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0, j = 0, k = 0;

    while (j < size_v1 && k < size_v2)
    {
        if (compare(v1[j], v2[k]) <= 0)
        {
            v[i++] = v1[j++];
        }
        else
        {
            v[i++] = v2[k++];
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

static void mergeInt(int *v, int *v1, int *v2, size_t size)
{
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0, j = 0, k = 0;

    while (j < size_v1 && k < size_v2)
    {
        if (v1[j] <= v2[k])
        {
            v[i++] = v1[j++];
        }
        else
        {
            v[i++] = v2[k++];
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

void mergesort(Elemento *v, size_t size)
{
    if (size > 1)
    {
        size_t meio = size / 2;

        Elemento *v1 = malloc(sizeof(Elemento) * meio);
        Elemento *v2 = malloc(sizeof(Elemento) * (size - meio));

        for (size_t i = 0; i < meio; i++)
        {
            v1[i] = v[i];
        }

        for (size_t i = meio; i < size; i++)
        {
            v2[i - meio] = v[i];
        }

        mergesort(v1, meio);
        mergesort(v2, size - meio);

        merge(v, v1, v2, size);

        free(v1);
        free(v2);
    }
}

void mergesortInt(int *v, size_t size)
{
    if (size > 1)
    {
        size_t meio = size / 2;

        int *v1 = malloc(sizeof(int) * meio);
        int *v2 = malloc(sizeof(int) * (size - meio));

        for (size_t i = 0; i < meio; i++)
        {
            v1[i] = v[i];
        }

        for (size_t i = meio; i < size; i++)
        {
            v2[i - meio] = v[i];
        }

        mergesortInt(v1, meio);
        mergesortInt(v2, size - meio);

        mergeInt(v, v1, v2, size);

        free(v1);
        free(v2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    mergesortInt(v, n);

    Elemento elems[n];
    int tamanho = 0;

    int i = 0;
    while (i < n)
    {
        int valor = v[i];
        int freq = 0;

        while (i < n && v[i] == valor)
        {
            freq++;
            i++;
        }

        elems[tamanho].valor = valor;
        elems[tamanho].freq = freq;
        tamanho++;
    }
    mergesort(elems, tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < elems[i].freq; j++)
        {
            printf("%d ", elems[i].valor);
        }
    }

    printf("\n");
    return 0;
}