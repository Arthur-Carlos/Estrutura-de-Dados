// arvore Busca em Largura

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila_node_t
{
    tree_node_t *treeNode;
    struct fila_node_t *proximo;
} fila_node_t;

typedef struct
{
    fila_node_t *inicio;
    fila_node_t *fim;
} Fila;

fila_node_t *criarFilaNode(tree_node_t *t)
{
    fila_node_t *novo = (fila_node_t *)malloc(sizeof(fila_node_t));
    novo->treeNode = t;
    novo->proximo = NULL;
    return novo;
}

Fila *inicializarFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

int filaVazia(Fila *f)
{
    return f->inicio == NULL;
}

void enfileirar(Fila *f, tree_node_t *t)
{
    fila_node_t *novo = criarFilaNode(t);

    if (f->fim == NULL)
    {
        f->inicio = f->fim = novo;
        return;
    }

    f->fim->proximo = novo;
    f->fim = novo;
}

tree_node_t *desenfileirar(Fila *f)
{
    if (filaVazia(f))
        return NULL;

    fila_node_t *temp = f->inicio;
    tree_node_t *t = temp->treeNode;

    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);

    return t;
}

void bfs(tree_t *t)
{
    if (t == NULL || t->root == NULL)
        return;

    Fila *f = inicializarFila();

    enfileirar(f, t->root);

    while (!filaVazia(f))
    {
        tree_node_t *atual = desenfileirar(f);

        printf("%d ", atual->data);

        if (atual->left != NULL)
            enfileirar(f, atual->left);

        if (atual->right != NULL)
            enfileirar(f, atual->right);
    }

    free(f);
}