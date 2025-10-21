#include <stdio.h>
#include <stdlib.h>

long long llabs_(long long x)
{
    return x < 0 ? -x : x;
}

int main()
{
    int entrada;
    scanf("%d", &entrada);

    int *vetor = malloc(entrada * sizeof(long long));
    for (int i = 0; i < entrada; i++)
    {
        scanf("%d", &vetor[i]);
    }

    long long divisor = 0;
    for (int i = 0; i < entrada; i++)
    {
        if (vetor[i] != 0)
        {
            long long absoluto = llabs_(vetor[i]);
            if (divisor == 0 || absoluto < divisor)
            {
                divisor = absoluto;
            }
        }
    }
    if (divisor == 0)
    {
        printf("Sim\n");
        free(vetor);
        return 0;
    }

    for (int i = 0; i < entrada; i++)
    {
        if (vetor[i] != 0 && (vetor[i] % divisor != 0))
        {
            printf("Nao\n");
            free(vetor);
            return 0;
        }
    }

    printf("Sim\n");
    free(vetor);
    return 0;
}
