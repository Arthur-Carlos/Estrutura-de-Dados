#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOME 15

int comparador(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{
    int entrada;
    scanf("%d", &entrada);

    char (*nomes)[MAXNOME] = malloc(entrada * MAXNOME);

    for (int i = 0; i < entrada; i++)
    {
        scanf("%s", nomes[i]);
    }

    qsort(nomes, entrada, MAXNOME, comparador);

    int maxFreq = 1, freq = 1;
    char maisFrequente[MAXNOME];
    strcpy(maisFrequente, nomes[0]);

    for (int i = 1; i < entrada; i++)
    {
        if (strcmp(nomes[i], nomes[i - 1]) == 0)
        {
            freq++;
        }
        else
        {
            if (freq > maxFreq || (freq == maxFreq && strcmp(nomes[i - 1], maisFrequente) < 0))
            {
                maxFreq = freq;
                strcpy(maisFrequente, nomes[i - 1]);
            }
            freq = 1;
        }
    }

    if (freq > maxFreq || (freq == maxFreq && strcmp(nomes[entrada - 1], maisFrequente) < 0))
    {
        maxFreq = freq;
        strcpy(maisFrequente, nomes[entrada - 1]);
    }

    printf("%s %d\n", maisFrequente, maxFreq);

    free(nomes);
    return 0;
}
