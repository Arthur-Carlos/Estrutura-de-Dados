#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef struct list_node_t
{
    char data[31];
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
    *l = malloc(sizeof(list_t));
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
    return l->size == 0;
}

static list_node_t *list_new_node(const char *data)
{
    list_node_t *new_node = malloc(sizeof(list_node_t));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

void list_append(list_t *l, const char *data)
{
    list_node_t *new_node = list_new_node(data);
    if (l->tail == NULL)
    {
        l->head = l->tail = new_node;
    }
    else
    {
        l->tail->next = new_node;
        l->tail = new_node;
    }
    l->size++;
}

void list_delete(list_t **l)
{
    list_node_t *aux = (*l)->head;
    while (aux != NULL)
    {
        list_node_t *next = aux->next;
        free(aux);
        aux = next;
    }
    free(*l);
    *l = NULL;
}

void print_list(list_t *l)
{
    for (list_node_t *aux = l->head; aux != NULL; aux = aux->next)
    {
        printf("%s\n", aux->data);
    }
}

char *josephus(list_t *l, int x)
{
    assert(l && l->size > 0);

    l->tail->next = l->head;

    list_node_t *prev = l->tail;
    list_node_t *curr = l->head;

    while (l->size > 1)
    {

        for (int count = 1; count < x; count++)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        if (curr == l->head)
            l->head = curr->next;
        if (curr == l->tail)
            l->tail = prev;

        list_node_t *to_delete = curr;
        curr = curr->next;
        free(to_delete);
        l->size--;
    }

    l->head = curr;
    l->tail = curr;
    l->tail->next = NULL;
    return curr->data;
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);

    list_t *l;
    list_initialize(&l);

    char nome[31];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", nome);
        list_append(l, nome);
    }

    char *vencedor = josephus(l, x);
    printf("%s\n", vencedor);

    list_delete(&l);
    return 0;
}
