#include "grader.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

static void list_delete_node(list_node_t *n)
{
    free(n);
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
