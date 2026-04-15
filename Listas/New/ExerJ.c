#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void list_reverse(list_t *l)
{
    assert(list_size(l) > 1);
    list_node_t *anterior = NULL;
    list_node_t *atual = l->head;
    list_node_t *prox = NULL;
    l->tail = l->head;
    while (atual != NULL)
    {
        prox = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = prox;
    }
    l->head = anterior;
}