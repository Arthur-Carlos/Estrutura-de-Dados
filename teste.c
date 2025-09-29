#include <stdio.h>
#include <stdbool.h>

typedef struct dlist_node_t
{
    int data;
    struct dlist_node_t *next;
    struct dlist_node_t *prev;
} dlist_node_t;

typedef struct dlist_t
{
    dlist_node_t *head;
    dlist_node_t *tail;
    size_t size;
} dlist_t;

void dlist_initialize(dlist_t **l)
{
    (*l) = mallocx(sizeof(dlist_t));
    (*l)->head == NULL;
    (*l)->tail == NULL;
    (*l)->size == 0;
}

size_t dlist_size(dlist_t *l)
{
    return l->size;
}

bool dlist_empty(dlist_t *l)
{
    return dlist_size(l) == 0 ? true : false;
}

static *dlist_new_node(int data)
{
    dlist_node_t *new_node = mallocx(sizeof(dlist_node_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
}

static void dlist_delete_node(dlist_node_t *node)
{
    free(node);
}

void dlist_prepend(dlist_t *l, int data)
{
    dlist_node_t *new_node = dlist_new_node(data);
    if (dlist_empty(l))
    {
        l->tail = new_node;
    }
    else
    {
        l->head->prev = new_node;
    }
    new_node->next = l->head;
    l->head = new_node;
    l->size++;
}

void dlist_append(dlist_t *l, int data)
{
    dlist_node_t *new_node = dlist_new_node(data);
    if (dlist_empty(l))
    {
        l->head = new_node;
    }
    else
    {
        l->tail->next = new_node;
    }
    new_node->prev = l->tail;
    l->tail = new_node;
    l->size++;
}

void dlist_insert(dlist_t *l, int data, size_t i)
{
    assert(i <= dlist_size(l));
    if (dlist_empty(l) || i == 0)
    {
        dlist_prepend(l, data);
    }
    else if (i == dlist_size(l))
    {
        dlist_append(l, data);
    }
    else
    {
        dlist_node_t *new_node = dlist_newnode(data);
        dlist_node_t *aux = l->head;
        size_t k;
        for (k = 0; k < i - 1; k++)
        {
            aux = aux->next;
        }
        new_node->next = aux->next;
        new_node->prev = aux;
        aux->next->prev = new_node;
        aux->next = new_node;
        l->size++;
    }
}

void dlist_remove_head(dlist_t *l){
    assert(!dlist_empty(l));
    
}