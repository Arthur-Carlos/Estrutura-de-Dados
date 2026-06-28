#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int chave;
    struct Lista_node *prox;
} Lista_node;

typedef struct
{
    Lista_node *ini;
    Lista_node *fim;
} Lista;

int main()
{
    int num, tab;
    scanf("%d %d", &num, &tab);
    Lista *tabela = (Lista *)calloc(tab, sizeof(Lista));
    for (int i = 0; i < num; i++)
    {
        int valor;
        scanf("%d", &valor);
        int indice = valor 
    }
}