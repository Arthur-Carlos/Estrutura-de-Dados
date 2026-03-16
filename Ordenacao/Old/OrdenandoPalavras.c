#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Palavra
{
    char palavra[11];
    int indice;
} Palavra;

int comparador(const void *a, const void *b)
{
    Palavra *p1 = (Palavra *)a;
    Palavra *p2 = (Palavra *)b;

    int len1 = strlen(p1->palavra);
    int len2 = strlen(p2->palavra);

    if (len1 != len2)
    {
        return len1 - len2;
    }
    return p1->indice - p2->indice;
};

int main()
{
    int entrada;
    scanf("%d", &entrada);
    Palavra vetor[entrada];
    for (int i = 0; i < entrada; i++)
    {
        scanf("%s", vetor[i].palavra);
        vetor[i].indice = i;
    }
    qsort(vetor, entrada, sizeof(Palavra), comparador);
    for (int i = 0; i < entrada; i++)
    {
        printf("%s\n", vetor[i].palavra);
    }
    return 0;
}