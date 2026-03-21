#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    char nome[31];
} Aluno;

static void merge(Aluno *v, Aluno *v1, Aluno *v2, size_t size)
{
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;

    size_t i = 0, j = 0, k = 0;

    while (j < size_v1 && k < size_v2)
    {
        if (strcmp(v1[j].nome, v2[k].nome) < 0)
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

void mergesort(Aluno *v, size_t size)
{
    if (size > 1)
    {
        size_t meio = size / 2;

        Aluno *v1 = malloc(sizeof(Aluno) * meio);
        Aluno *v2 = malloc(sizeof(Aluno) * (size - meio));

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

int main()
{
    int n;
    scanf("%d", &n);

    Aluno *alunos = malloc(sizeof(Aluno) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", alunos[i].nome);
    }

    mergesort(alunos, n);
    int contador = 1, max = 1;
    char copia[31];
    strcpy(copia, alunos[0].nome);
    for (int i = 1; i < n; i++)
    {
        if (strcmp(alunos[i].nome, alunos[i - 1].nome) == 0)
        {
            contador++;
        }
        else
        {
            if (contador > max)
            {
                max = contador;
                strcpy(copia, alunos[i - 1].nome);
            }
            contador = 1;
        }
    }
    if (contador > max)
    {
        max = contador;
        strcpy(copia, alunos[n - 1].nome);
    }
    printf("%s %d\n", copia, max);
    free(alunos);
    return 0;
}