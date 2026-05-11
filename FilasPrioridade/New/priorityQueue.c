#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct priority_queue_t
{
    int *pqueue;
    size_t size;
    size_t capacity;
} priority_queue_t;

static void priority_queue_heapify_top_down(priority_queue_t *pq, size_t i)
{
    size_t l, r;
    size_t largest = i;
    while (i < pq->size)
    {
        i = largest;
        l = 2 * i + 1;
        r = 2 * i + 2;
        if (l < pq->size && pq->pqueue[i] < pq->pqueue[l])
        {
            largest = l;
        }
        if (r < pq->size && pq->pqueue[largest] < pq->pqueue[r])
        {
            largest = r;
        }
        if (largest == i)
        {
            break;
        }

        int aux = pq->pqueue[i];
        pq->pqueue[i] = pq->pqueue[largest];
        pq->pqueue[largest] = aux;
    }
}

static void priority_queue_heapify_bottom_up(priority_queue_t *pq, size_t i)
{
    size_t p;
    for (p = (i - 1) / 2; i != 0; i = p, p = (p - 1) / 2)
    {
        {
            if (pq->pqueue[p] >= pq->pqueue[i])
            {
                break;
            }
            int aux = pq->pqueue[i];
            pq->pqueue[i] = pq->pqueue[p];
            pq->pqueue[p] = aux;
        }
    }
}

void priority_queue_initialize(priority_queue_t **pq)
{
    (*pq) = malloc(sizeof(priority_queue_t));
    (*pq)->size = 0;
    (*pq)->capacity = 4;
    (*pq)->pqueue = malloc(sizeof(int) * (*pq)->capacity);
}

size_t priority_queue_size(priority_queue_t *pq)
{
    return pq->size;
}

bool priority_queue_empty(priority_queue_t *pq)
{
    return priority_queue_size(pq) == 0;
}

void priority_queue_push(priority_queue_t *pq, int data)
{
    if (pq->size == pq->capacity)
    {
        pq->capacity *= 2;
        pq->pqueue = realloc(pq->pqueue, sizeof(int) * pq->capacity);
    }
    pq->pqueue[pq->size] = data;
    priority_queue_heapify_bottom_up(pq, pq->size);
    pq->size;
}

int priority_queue_front(priority_queue_t *pq)
{
    assert(!priority_queue_empty(pq));
    return pq->pqueue[0];
}

void priority_queue_pop(priority_queue_t *pq)
{
    assert(!priority_queue_empty(pq));
    if (pq->size == pq->capacity / 4 && pq->capacity > 4)
    {
        pq->capacity /= 2;
        pq->pqueue = realloc(pq->pqueue, sizeof(int) * pq->capacity);
    }

    pq->size--;
    if (!priority_queue_empty(pq))
    {
        pq->pqueue[0] = pq->pqueue[pq->size];
        priority_queue_heapify_top_down(pq, 0);
    }
}

void priority_queue_delete(priority_queue_t **pq)
{
    free((*pq)->pqueue);
    free(*pq);
    (*pq) = NULL;
}
