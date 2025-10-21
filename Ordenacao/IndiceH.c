#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10005

typedef struct Autor
{
    char nome[31];
    int indiceH;
} Autor;

int comaparaIndice(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return y - x;
}

int calcularIndiceH(int *citacoes, int n)
{
    qsort(citacoes, n, sizeof(int), comaparaIndice);
    int h = 0;
    for (int i = 0; i < n; ++i)
    {
        if (citacoes[i] >= i + 1)
        {
            h = i + 1;
        }
        else
        {
            break;
        }
    }
    return h;
}

int compara(const void *a, const void *b)
{
    Autor *A = (Autor *)a;
    Autor *B = (Autor *)b;
    if (A->indiceH != B->indiceH)
    {
        return B->indiceH - A->indiceH;
    }
    return strcmp(A->nome, B->nome);
}

int main()
{
    int entrada;
    scanf("%d", &entrada);
    Autor *autores = malloc(entrada * sizeof(Autor));

    for (int i = 0; i < entrada; ++i)
    {
        int publicacoes;
        int citacoes[MAX];
        scanf("%s %d", autores[i].nome, &publicacoes);
        for (int j = 0; j < publicacoes; j++)
        {
            scanf("%d", &citacoes[j]);
        }

        autores[i].indiceH = calcularIndiceH(citacoes, publicacoes);
    }

    qsort(autores, entrada, sizeof(Autor), compara);
    for (int i = 0; i < entrada; i++)
    {
        printf("%s %d\n", autores[i].nome, autores[i].indiceH);
    }
    free(autores);
    return 0;
}
