#include <stdio.h>
#include <stdlib.h>

typedef struct Corredor
{
    char nome[31];
    int tempo;
} Corredor;

int calculatempo(int segundo, int milissegundo)
{
    return segundo * 1000 + milissegundo;
}

static void merge(Corredor *v, Corredor *v1, Corredor *v2, size_t size)
{
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++)
    {
        if (v1[j].tempo <= v2[k].tempo)
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

void mergesort(Corredor *v, size_t size)
{
    size_t meio;
    if (size > 1)
    {
        meio = size / 2;
        Corredor *v1 = malloc(sizeof(Corredor) * meio);
        Corredor *v2 = malloc(sizeof(Corredor) * (size - meio));
        int i;
        for (i = 0; i < meio; i++)
        {
            v1[i] = v[i];
        }
        for (i = meio; i < size; i++)
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

int main()
{
    int n;
    int segundo, milissegundo, total;
    int tempo, min, seg, mil;
    scanf("%d", &n);
    Corredor *dados = malloc(sizeof(Corredor) * n);
    for (int i = 0; i < n; i++)
    {
        total = 0;
        scanf("%s", dados[i].nome);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d.%d", &segundo, &milissegundo);
            total += calculatempo(segundo, milissegundo);
        }
        dados[i].tempo = total;
    }
    mergesort(dados, n);
    for (int i = 0; i < n; i++)
    {
        tempo = dados[i].tempo;
        min = tempo / 60000;
        seg = (tempo % 60000) / 1000;
        mil = tempo % 1000;
        printf("%d. %s - %d:%02d.%03d\n", i + 1, dados[i].nome, min, seg, mil);
    }
    return 0;
}