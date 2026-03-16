#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[35];
    int tempo;
    int ordem;
} Piloto;

int cmp(const void *a, const void *b)
{
    Piloto *p1 = (Piloto *)a;
    Piloto *p2 = (Piloto *)b;

    if (p1->tempo != p2->tempo)
        return p1->tempo - p2->tempo;
    return p1->ordem - p2->ordem;
}

int main()
{
    int entrada, i;
    scanf("%d", &entrada);

    Piloto pilotos[entrada];

    for (i = 0; i < entrada; i++)
    {
        scanf("%s", pilotos[i].nome);

        int ss, mmm;
        int total = 0;

        for (int j = 0; j < 3; j++)
        {
            scanf("%d.%d", &ss, &mmm);
            total += ss * 1000 + mmm;
        }

        pilotos[i].tempo = total;
        pilotos[i].ordem = i;
    }

    qsort(pilotos, entrada, sizeof(Piloto), cmp);

    for (int i = 0; i < entrada; i++)
    {
        int ms = pilotos[i].tempo;
        int minutos = ms / 60000;
        int segundos = (ms % 60000) / 1000;
        int milisseg = ms % 1000;

        printf("%d. %s - %d:%02d.%03d\n", i + 1, pilotos[i].nome,
               minutos, segundos, milisseg);
    }

    return 0;
}
