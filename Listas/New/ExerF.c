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

void list_insertionsort_insert(list_t *l, int data)
{
    if (list_empty(l))
    {
        list_prepend(l, data);
    }
    else
    {
        list_node_t *new_node = list_new_node(data);
        if (data <= l->head->data)
        {
            list_prepend(l, data);
        }
        else
        {
            list_node_t *aux = l->head;
            while (aux->next != NULL && aux->next->data < data)
            {
                aux = aux->next;
            }
            new_node->next = aux->next;
            aux->next = new_node;
            if (new_node->next == NULL)
            {
                l->tail = new_node;
            }
            l->size++;
        }
    }
}