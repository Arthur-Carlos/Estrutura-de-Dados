#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparador(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
};

int main()
{
    int entrada, contador = 0;
    scanf("%d", &entrada);

    int *inteiros = malloc(entrada * sizeof(int));
    for (int i = 0; i < entrada; i++)
    {
        scanf("%d", &inteiros[i]);
    }
    qsort(inteiros, entrada, sizeof(int), comparador);
    for (int i = 0; i < entrada; i++)
    {
        if (inteiros[i] != inteiros[i + 1])
        {
            contador++;
        }
    }
    printf("%d", contador);
    free(inteiros);
    return 0;
}