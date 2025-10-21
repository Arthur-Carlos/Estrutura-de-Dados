#include "grader.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

static void list_delete_node(list_node_t *n)
{
    free(n);
}

void list_remove_head(list_t *l)
{
    assert(!list_empty(l));
    list_node_t *aux = l->head;
    if (list_size(l) == 1)
    {
        l->tail = NULL;
    }
    l->head = l->head->next;
    list_delete_node(aux);
    l->size--;
}

void list_remove_tail(list_t *l)
{
    assert(list_size(l) > 0);
    list_node_t *to_be_removed = l->tail;
    if (list_size(l) == 1)
    {
        l->head = NULL;
        l->tail = NULL;
    }
    else
    {
        list_node_t *aux = l->head;
        while (aux->next != l->tail)
        {
            aux = aux->next;
        }
        aux->next = NULL;
        l->tail = aux;
    }
    list_delete_node(to_be_removed);
    l->size--;
}

void list_remove(list_t *l, size_t i)
{
    assert(!list_empty(l) && i < list_size(l));
    if (list_size(l) == 1 || i == 0)
    {
        list_remove_head(l);
    }
    else if (i == list_size(l) - 1)
    {
        list_remove_tail(l);
    }

    else
    {
        list_node_t *node;
        list_node_t *aux = l->head;
        size_t k;
        for (k = 0; k < i - 1; k++)
        {
            aux = aux->next;
        }
        node = aux->next;
        aux->next = node->next;
        list_delete_node(node);
        l->size--;
    }
}
