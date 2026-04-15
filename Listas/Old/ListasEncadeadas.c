#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct list_node_t
{
    int data;
    struct list_node_t *next;
} list_node_t;

typedef struct list_t
{
    list_node_t *head;
    list_node_t *tail;
    size_t size;
} list_t;

void list_initialize(list_t **l)
{
    (*l) = malloc(sizeof(list_t));
    (*l)->head = NULL;
    (*l)->tail = NULL;
    (*l)->size = 0;
}

size_t list_size(list_t *l)
{
    return l->size;
}

bool list_empty(list_t *l)
{
    return list_size(l) == 0 ? 1 : 0;
}

static list_node_t *list_new_node(int data)
{
    list_node_t *new_node = malloc(sizeof(list_node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

static void list_delete_node(list_node_t *n)
{
    free(n);
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

int list_access_head(list_t *l)
{
    assert(!list_empty(l));
    return (l->head->data);
}

int list_access_tail(list_t *l)
{
    assert(!list_empty(l));
    return (l->tail->data);
}

int list_access(list_t *l, size_t i)
{
    assert(!list_empty(l) && i < list_size(l));
    if (i == 0)
    {
        return (list_access_head(l));
    }
    else if (i == list_size(l) - 1)
    {
        return (list_access_tail(l));
    }
    size_t j;
    list_node_t *it = l->head;
    for (j = 0; j < i; j++)
    {
        it = it->next;
    }
    return (it->data);
}

void list_delete(list_t **l)
{
    while (!list_empty(*l))
    {
        list_remove_head(*l);
    }
    free(*l);
    *l = NULL;
}

void list_concat(list_t *l1, list_t *l2)
{
    assert(!list_empty(l2));
    if (list_empty(l1))
    {
        l1->head = l2->head;
        l1->tail = l2->tail;
        l1->size = l2->size;
    }
    else
    {
        l1->tail->next = l2->head;
        l1->tail = l2->tail;
        l1->size += l2->size;
    }

    l2->head = NULL;
    l2->tail = NULL;
    l2->size = 0;
}

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