#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int key;
    struct node *next;
} node_t;

void insert(node_t **head, int key) {
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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    node_t **table = calloc(m, sizeof(node_t*));

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        int idx = k % m;
        insert(&table[idx], k);
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