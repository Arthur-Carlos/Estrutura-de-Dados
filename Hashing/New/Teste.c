#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int key;
    struct Lista *next;
} Lista;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Lista **table = (Lista **)calloc(m, sizeof(Lista *));

    for (int i = 0; i < n; i++)
    {
        int key;
        scanf("%d", &key);

        int index = key % m;

        Lista *novo = (Lista *)malloc(sizeof(Lista));
        novo->key = key;
        novo->next = NULL;

        if (table[index] == NULL)
        {
            table[index] = novo;
        }
        else
        {
            Lista *aux = table[index];
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = novo;
        }
    }

    for (int i = 0; i < m; i++)
    {
        printf("T[%d]", i);

        Lista *aux = table[i];
        while (aux != NULL)
        {
            printf(" -> %d", aux->key);
            aux = aux->next;
        }

        printf(" -> NULL\n");
    }

    for (int i = 0; i < m; i++)
    {
        Lista *aux = table[i];
        while (aux != NULL)
        {
            Lista *tmp = aux;
            aux = aux->next;
            free(tmp);
        }
    }

    free(table);

    return 0;
}