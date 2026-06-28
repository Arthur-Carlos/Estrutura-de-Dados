#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct bst_node_t
{
    int data;
    struct bst_node_t *left;
    struct bst_node_t *right;
} bst_node_t;

typedef struct bst_t
{
    bst_node_t *root;
    size_t size;
} bst_t;

static bool is_bst_aux(tree_node_t *node, int min, int max)
{
    if (node == NULL)
        return true;

    if (node->data <= min || node->data >= max)
        return false;
    return is_bst_aux(node->left, min, node->data) &&
           is_bst_aux(node->right, node->data, max);
}

bool is_bst(tree_t *t)
{
    if (t == NULL || t->root == NULL)
        return true;
    return is_bst_aux(t->root, INT_MIN, INT_MAX);
}