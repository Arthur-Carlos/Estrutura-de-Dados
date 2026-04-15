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