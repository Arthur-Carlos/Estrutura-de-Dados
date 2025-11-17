#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

typedef struct {
    int a[MAXN+5];
    int size;
} MaxHeap;

void max_push(MaxHeap *h, int x) {
    int i = h->size++;
    h->a[i] = x;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->a[p] >= h->a[i]) break;
        int tmp = h->a[p];
        h->a[p] = h->a[i];
        h->a[i] = tmp;
        i = p;
    }
}

int max_pop(MaxHeap *h) {
    int ret = h->a[0];
    h->a[0] = h->a[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, largest = i;
        if (l < h->size && h->a[l] > h->a[largest]) largest = l;
        if (r < h->size && h->a[r] > h->a[largest]) largest = r;
        if (largest == i) break;
        int tmp = h->a[i];
        h->a[i] = h->a[largest];
        h->a[largest] = tmp;
        i = largest;
    }
    return ret;
}

typedef struct {
    int a[MAXN+5];
    int size;
} MinHeap;

void min_push(MinHeap *h, int x) {
    int i = h->size++;
    h->a[i] = x;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->a[p] <= h->a[i]) break;
        int tmp = h->a[p];
        h->a[p] = h->a[i];
        h->a[i] = tmp;
        i = p;
    }
}

int min_pop(MinHeap *h) {
    int ret = h->a[0];
    h->a[0] = h->a[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, smallest = i;
        if (l < h->size && h->a[l] < h->a[smallest]) smallest = l;
        if (r < h->size && h->a[r] < h->a[smallest]) smallest = r;
        if (smallest == i) break;
        int tmp = h->a[i];
        h->a[i] = h->a[smallest];
        h->a[smallest] = tmp;
        i = smallest;
    }
    return ret;
}


int main() {
    int n;
    scanf("%d", &n);

    MaxHeap low = { .size = 0 };
    MinHeap high = { .size = 0 };
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (low.size == 0 || x <= low.a[0]) {
            max_push(&low, x);
        } else {
            min_push(&high, x);
        }

        if (low.size > high.size + 1) {
            int v = max_pop(&low);
            min_push(&high, v);
        } else if (high.size > low.size) {
            int v = min_pop(&high);
            max_push(&low, v);
        }

        printf("%d\n", low.a[0]);
    }

    return 0;
}
