#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int key;
    struct node *next;
} node_t;

void insert_end(node_t **head, int key) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = key;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

int hash_multiplicacao(int k, int m, double A) {
    double frac = fmod(k * A, 1.0);
    return (int) floor(m * frac);
}

int main() {
    int n, m;
    double A;

    scanf("%d %d", &n, &m);
    scanf("%lf", &A);

    node_t **table = calloc(m, sizeof(node_t*));

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        int idx = hash_multiplicacao(k, m, A);
        insert_end(&table[idx], k);
    }

    for (int i = 0; i < m; i++) {
        printf("T[%d]", i);

        node_t *curr = table[i];
        while (curr != NULL) {
            printf(" -> %d", curr->key);
            curr = curr->next;
        }

        printf(" -> NULL\n");
    }

    for (int i = 0; i < m; i++) {
        node_t *curr = table[i];
        while (curr != NULL) {
            node_t *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(table);

    return 0;
}
