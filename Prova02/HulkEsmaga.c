#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// essa eu erraria de qualquer maneira, quando eu estava discutindo com os colegas eu percebi que o metodo que eu iria utilizar seria de O(N^2) pois eu
// não estaria utilizando a priority Queue e tentaria reordenar após cada listagem.
int heap[200000];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int x) {
    heap[size] = x;
    int i = size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] >= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

int pop() {
    int top = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, largest = i;
        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;
        if (largest == i) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
    return top;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    while (size > 1) {
        int a = pop();
        int b = pop();
        if (a != b) {
            push(a - b);
        }
    }

    if (size == 1) printf("%d\n", heap[0]);
    else printf("0\n");

    return 0;
}
