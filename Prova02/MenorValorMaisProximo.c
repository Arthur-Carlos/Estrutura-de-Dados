#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/* Esta foi a versão que eu fiz pra atividade e tentei fazer durante a prova, porém não consegui
#define MAX 200000

int main()
{
    int n;
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int *stack = malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        while (top >= 0 && v[stack[top]] >= v[i])
            top--;

        if (top >= 0)
            printf("%d ", stack[top] + 1);
        else
            printf("0 ");

        stack[++top] = i;
    }

    free(v);
    free(stack);
    return 0;
}
*/

#include <stdio.h>

typedef struct
{
    int valor;
    int indice;
} Item;

Item stack[200000];
int top = -1;

int main()
{
    int n;
    scanf("%d", &n);

    int v;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v);
        while (top >= 0 && stack[top].valor >= v)
        {
            top--;
        }
        if (top < 0)
        {
            printf("0 ");
        }
        else
        {
            printf("%d ", stack[top].indice);
        }
        stack[++top].valor = v;
        stack[top].indice = i;
    }

    return 0;
}
