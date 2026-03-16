#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Palavra
{
    char palavra[11];
    int indice;
} Palavra;

static void merge(Palavra *v, Palavra *v1, size_t n1,
                  Palavra *v2, size_t n2);

void merge_sort(Palavra *v, size_t size)
{
    if (size > 1)
    {
        size_t mid = size / 2;

        Palavra *v1 = malloc(mid * sizeof(Palavra));
        Palavra *v2 = malloc((size - mid) * sizeof(Palavra));

        if (!v1 || !v2)
        {
            printf("Erro de memória\n");
            exit(1);
        }

        for (size_t i = 0; i < mid; i++)
            v1[i] = v[i];

        for (size_t i = mid; i < size; i++)
            v2[i - mid] = v[i];

        merge_sort(v1, mid);
        merge_sort(v2, size - mid);

        merge(v, v1, mid, v2, size - mid);

        free(v1);
        free(v2);
    }
}

static void merge(Palavra *v, Palavra *v1, size_t n1,
                  Palavra *v2, size_t n2)
{
    size_t i = 0, j = 0, k = 0;

    while (j < n1 && k < n2)
    {
        if (strcmp(v1[j].palavra, v2[k].palavra) <= 0)
            v[i++] = v1[j++];
        else
            v[i++] = v2[k++];
    }

    while (j < n1)
        v[i++] = v1[j++];

    while (k < n2)
        v[i++] = v2[k++];
}

int main()
{
    int N;
    scanf("%d", &N);

    Palavra *vetor = malloc(N * sizeof(Palavra));

    for (int i = 0; i < N; i++)
    {
        scanf("%s", vetor[i].palavra);
        vetor[i].indice = i;
    }

    merge_sort(vetor, N);

    for (int i = 0; i < N; i++)
        printf("%s\n", vetor[i].palavra);

    free(vetor);
    return 0;
}