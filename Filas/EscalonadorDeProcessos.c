#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 31

// Estrutura do processo
typedef struct
{
    char name[MAX_NAME];
    int pid;
    int time;
} process_t;

// Estrutura de fila circular
typedef struct
{
    process_t *data;
    int front, rear, size, capacity;
} queue_t;

void queue_init(queue_t *q, int cap)
{
    q->data = malloc(cap * sizeof(process_t));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = cap;
}

int queue_empty(queue_t *q)
{
    return q->size == 0;
}

void queue_push(queue_t *q, process_t p)
{
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = p;
    q->size++;
}

process_t queue_pop(queue_t *q)
{
    process_t p = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return p;
}

void queue_free(queue_t *q)
{
    free(q->data);
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    queue_t fila;
    queue_init(&fila, n);

    for (int i = 0; i < n; i++)
    {
        process_t p;
        scanf("%s %d %d", p.name, &p.pid, &p.time);
        queue_push(&fila, p);
    }

    int current_time = 0;

    while (!queue_empty(&fila))
    {
        process_t p = queue_pop(&fila);

        if (p.time <= q)
        {
            current_time += p.time;
            printf("%d %s %d ms\n", p.pid, p.name, current_time);
        }
        else
        {
            p.time -= q;
            current_time += q;
            queue_push(&fila, p);
        }
    }

    queue_free(&fila);
    return 0;
}
