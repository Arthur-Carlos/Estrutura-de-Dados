#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long valor;
    int pos;
} Elemento;

int compara(const void *a, const void *b)
{
    long long x = ((Elemento *)a)->valor;
    long long y = ((Elemento *)b)->valor;
    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

int main()
{
    int entrada;
    long long Alvo;
    scanf("%d %lld", &entrada, &Alvo);

    Elemento *vet = malloc(entrada * sizeof(Elemento));
    for (int i = 0; i < entrada; i++)
    {
        scanf("%lld", &vet[i].valor);
        vet[i].pos = i + 1;
    }

    qsort(vet, entrada, sizeof(Elemento), compara);

    int i = 0, j = entrada - 1;
    while (i < j)
    {
        long long soma = vet[i].valor + vet[j].valor;
        if (soma == Alvo)
        {
            printf("%d %d\n", vet[i].pos, vet[j].pos);
            free(vet);
            return 0;
        }
        else if (soma < Alvo)
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
