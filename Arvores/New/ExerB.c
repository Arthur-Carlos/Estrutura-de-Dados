// arvore Busca em Largura
#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node_t
{
    tree_node_t *data;
    struct queue_node_t *next;
} queue_node_t;

typedef struct
{
    queue_node_t *ini;
    queue_node_t *fim;
} queue_t;

void enqueue(queue_t *q, tree_node_t *node)
{
    queue_node_t *novo = (queue_node_t *)malloc(sizeof(queue_node_t));
    novo->data = node;
    novo->next = NULL;

    if (q->fim == NULL)
    {
        q->ini = q->fim = novo;
    }
    else
    {
        q->fim->next = novo;
        q->fim = novo;
    }
}

tree_node_t *dequeue(queue_t *q)
{
    if (q->ini == NULL)
        return NULL;

    queue_node_t *temp = q->ini;
    tree_node_t *node = temp->data;

    q->ini = q->ini->next;
    if (q->ini == NULL)
        q->fim = NULL;

    free(temp);
    return node;
}

int empty(queue_t *q)
{
    return q->ini == NULL;
}

void bfs(tree_t *t)
{
    if (t == NULL || t->root == NULL)
        return;

    queue_t fila;
    fila.ini = fila.fim = NULL;

    enqueue(&fila, t->root);

    while (!empty(&fila))
    {
        tree_node_t *atual = dequeue(&fila);

        printf("%d\n", atual->data);

        if (atual->left != NULL)
            enqueue(&fila, atual->left);

        if (atual->right != NULL)
            enqueue(&fila, atual->right);
    }
}