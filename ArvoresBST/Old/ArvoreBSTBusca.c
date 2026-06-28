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

bool bst_find(bst_t *t, int data)
{
    return bst_find_helper(t->root, data);
}

static bool bst_find_helper(bst_node_t *x, int data)
{
    if (x == NULL)
        return false;
    if (data == x->data)
        return true;
    if (data < x->data)
        return bst_find_helper(x->left, data);
    return bst_find_helper(x->right, data);
}