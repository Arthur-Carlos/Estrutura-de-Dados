//media flutuante

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct queue_t
{
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
    double *queue;
} queue_t;

void queue_initialize(queue_t **q)
{
    (*q) = malloc(sizeof(queue_t));
    (*q)->front = 0;
    (*q)->back = 3;
    (*q)->size = 0;
    (*q)->capacity = 4;
    (*q)->queue = malloc(sizeof(double) * 4);
}
void queue_delete(queue_t **q)
{
    free((*q)->queue);
    free(*q);
    *q = NULL;
}

size_t queue_size(queue_t *q)
{
    return q->size;
}

static int queue_is_empty(queue_t *q)
{
    return q->front == q->back;
}

static void queue_expand(queue_t *q)
{
    size_t old_capacity = q->capacity;
    q->capacity *= 2;
    q->queue = realloc(q->queue, sizeof(double) * q->capacity);
    if (q->front > q->back)
    {
        for (size_t i = q->front; i < old_capacity; i++)
        {
            q->queue[i + old_capacity] = q->queue[i];
        }
        q->front = q->front + old_capacity;
    }
}

static void queue_shrink(queue_t *q)
{
    size_t new_capacity = q->capacity / 2;
    if (q->front <= q->back)
    {
        for (size_t i = q->front, j = 0; i <= q->back; i++, j++)
        {
            q->queue[j] = q->queue[i];
        }
    }
    else
    {
        size_t front_len = q->capacity - q->front;
        for (int i = q->back; i >= 0; i--)
        {
            q->queue[i + front_len] = q->queue[i];
        }
        for (size_t i = q->front, j = 0; i < q->capacity; i++, j++)
        {
            q->queue[j] = q->queue[i];
        }
    }
    q->front = 0;
    q->back = q->size - 1;
    q->capacity = new_capacity;
    q->queue = realloc(q->queue, q->capacity * sizeof(double));
}

void queue_push(queue_t *q, double data)
{
    if (q->size == q->capacity)
    {
        queue_expand(q);
    }
    q->back++;
    if (q->back == q->capacity)
        q->back = 0;
    q->queue[q->back] = data;
    q->size++;
}

void queue_pop(queue_t *q)
{
    assert(q->size > 0);
    if (q->size == q->capacity / 4 && q->capacity > 4)
    {
        queue_shrink(q);
    }
    q->front++;
    q->size--;
    if (q->front == q->capacity)
    {
        q->front = 0;
    }
}

int queue_front(queue_t *q)
{
    assert(q->front < q->capacity);
    return q->queue[q->front];
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    queue_t *fila;
    queue_initialize(&fila);
    double valor, soma = 0.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &valor);
        queue_push(fila, valor);
        soma += valor;

        if (fila->size > k)
        {
            soma -= queue_front(fila);
            queue_pop(fila);
        }
        printf("%.4lf\n", soma / fila->size);
    }

    queue_delete(&fila);
    return 0;
}
