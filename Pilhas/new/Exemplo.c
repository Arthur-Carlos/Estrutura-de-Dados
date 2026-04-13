#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int v[n + 1];
    int pilha[n];
    int tam_pilha = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        while (tam_pilha > 0 && v[pilha[tam_pilha - 1]] >= v[i])
        {
            tam_pilha--;
        }
        if (tam_pilha == 0)
        {
            printf("0 ");
        }
        else
        {
            printf("%d ", pilha[tam_pilha-1]);
        }
        pilha[tam_pilha++] = i;
    }
    printf("\n");
    return 0;
} // 8 2 5 1 4 8 3 2 1
