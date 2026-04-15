#include "grader.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void list_insertionsort_insert(list_t *l, int data)
{
    list_node_t *novo = malloc(sizeof(list_node_t));
    novo->data = data;
    novo->next = NULL;

    if (list_empty(l))
    {
        l->head = l->tail = novo;
        l->size = 1;
        return;
    }
    if (data <= l->head->data)
    {
        novo->next = l->head;
        l->head = novo;
        l->size++;
        return;
    }
    list_node_t *atual = l->head;
    while (atual->next != NULL && atual->next->data < data)
    {
        atual = atual->next;
    }
    novo->next = atual->next;
    atual->next = novo;
    if (novo->next == NULL)
    {
        l->tail = novo;
    }

    l->size++;
}
