#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto
{
    int pontoX;
    int pontoY;
} Ponto;

int compara(const void *a, const void *b)
{
    const Ponto *p1 = (const Ponto *)a;
    const Ponto *p2 = (const Ponto *)b;

    if (p1->pontoX != p2->pontoX)
        return (p1->pontoX > p2->pontoX) - (p1->pontoX < p2->pontoX);
    return (p1->pontoY > p2->pontoY) - (p1->pontoY < p2->pontoY);
}

int main()
{
    int entrada, questoes, auxX, auxY;
    scanf("%d %d", &entrada, &questoes);
    Ponto *vetor = malloc(entrada * sizeof(Ponto));
    for (int i = 0; i < entrada; i++)
    {
        scanf("%d %d", &vetor[i].pontoX, &vetor[i].pontoY);
    }
    qsort(vetor, entrada, sizeof(Ponto), compara);
    for (int i = 0; i < questoes; i++)
    {
        Ponto aux;
        scanf("%d %d", &aux.pontoX, &aux.pontoY);

        Ponto *resultado = bsearch(&aux, vetor, entrada, sizeof(Ponto), compara);

        if (resultado)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    free(vetor);
    return 0;
}
