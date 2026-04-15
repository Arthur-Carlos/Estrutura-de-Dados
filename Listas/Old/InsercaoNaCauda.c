#include "grader.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

static list_node_t *list_new_node(int data)
{
    list_node_t *new_node = malloc(sizeof(list_node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void list_append(list_t *l, int data)
{
    list_node_t *new_node = list_new_node(data);
    if (list_empty(l))
    {
        l->head = new_node;
    }
    else
    {
        l->tail->next = new_node;
    }
    l->tail = new_node;
    l->size++;
}