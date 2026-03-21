#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Autor
{
    char nome[31];
    int indice;
} Autor;

static void merge(Autor *v, Autor *v1, Autor *v2, size_t size)
{
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;

    size_t i = 0, j = 0, k = 0;

    while (j < size_v1 && k < size_v2)
    {
        if (v1[j].indice > v2[k].indice ||
            (v1[j].indice == v2[k].indice && strcmp(v1[j].nome, v2[k].nome) < 0)) //esqueci de desempatar
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

void mergesort(Autor *v, size_t size)
{
    if (size > 1)
    {
        size_t meio = size / 2;

        Autor *v1 = malloc(sizeof(Autor) * meio);
        Autor *v2 = malloc(sizeof(Autor) * (size - meio));

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

int calculaindice(int *citacao, int n)
{
    int *count = calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if (citacao[i] >= n)
            count[n]++;
        else
            count[citacao[i]]++;
    }

    int soma = 0;
    for (int i = n; i >= 0; i--)
    {
        soma += count[i];
        if (soma >= i)
        {
            free(count);
            return i;
        }
    }

    free(count);
    return 0;
}

int main()
{
    int n, artigos;
    scanf("%d", &n);

    Autor *autores = malloc(sizeof(Autor) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", autores[i].nome, &artigos);
        int *citacao = malloc(sizeof(int) * artigos);

        for (int j = 0; j < artigos; j++)
        {
            scanf("%d", &citacao[j]);
        }

        autores[i].indice = calculaindice(citacao, artigos);
        free(citacao);
    }

    mergesort(autores, n);

    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", autores[i].nome, autores[i].indice);
    }

    free(autores);
    return 0;
}