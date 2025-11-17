#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double *data;
    int front, rear, size, capacity;
} queue_t;

void queue_init(queue_t *q, int cap)
{
    q->data = malloc(cap * sizeof(double));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = cap;
}

int queue_empty(queue_t *q)
{
    return q->size == 0;
}

int queue_full(queue_t *q)
{
    return q->size == q->capacity;
}

void queue_push(queue_t *q, double value)
{
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
}

double queue_pop(queue_t *q)
{
    double value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return value;
}

void queue_free(queue_t *q)
{
    free(q->data);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    queue_t fila;
    queue_init(&fila, k);

    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        double x;
        scanf("%lf", &x);
        queue_push(&fila, x);
        sum += x;

        if (fila.size > k)
        {
            sum -= queue_pop(&fila);
        }
        printf("%.4lf\n", sum / fila.size);
    }

    queue_free(&fila);
    return 0;
}
