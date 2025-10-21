#include "grader.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void list_reverse(list_t *l)
{
    assert(!list_empty(l));
    list_node_t *prev = NULL;
    list_node_t *current = l->head;
    list_node_t *next = NULL;

    l->tail = l->head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    l->head = prev;
}