#include <stdio.h>
#include <stdlib.h>

int heap[1000];
int heapSize = 0;

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void push(int data)
{
    heap[++heapSize] = data;
    int i = heapSize;
    while (i > 1 && heap[i] < heap[i / 2])
    {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

int pop()
{
    int minValue = heap[1];

    heap[1] = heap[heapSize--];

    int i = 1;

    while (1)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;

        if (left <= heapSize && heap[left] < heap[smallest])
            smallest = left;

        if (right <= heapSize && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return minValue;
}

int main()
{
    int N, x;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        push(x);
    }
    int totalCost = 0;

    while (heapSize > 1)
    {
        int a = pop();
        int b = pop();

        totalCost += (a > b ? a : b);

        push(a + b);
    }

    printf("%d\n", totalCost);

    return 0;
}