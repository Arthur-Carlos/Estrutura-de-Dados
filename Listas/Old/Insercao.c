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

void list_prepend(list_t *l, int data)
{
    list_node_t *new_node = list_new_node(data);
    new_node->next = l->head;
    l->head = new_node;
    if (list_empty(l))
    {
        l->tail = new_node;
    }
    l->size++;
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

void list_insert(list_t *l, int data, size_t i)
{
    assert(i <= list_size(l));
    if (list_empty(l) || i == 0)
    {
        list_prepend(l, data);
    }
    else if (i == list_size(l))
    {
        list_append(l, data);
    }
    else
    {
        list_node_t *new_node = list_new_node(data);
        list_node_t *aux = l->head;
        size_t k;
        for (k = 0; k < i - 1; k++)
        {
            aux = aux->next;
        }
        new_node->next = aux->next;
        aux->next = new_node;
        l->size++;
    }
}