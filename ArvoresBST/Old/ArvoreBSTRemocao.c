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

void bst_remove(bst_t *t, int data)
{
    t->root = bst_remove_helper(t->root, data);
    t->size--;
}

void bst_delete(bst_t **t)
{
    bst_delete_helper((*t)->root);
    free(*t);
    (*t) = NULL;
}

static void bst_delete_helper(bst_node_t *x)
{
    if (x != NULL)
    {
        bst_delete_helper(x->left);
        bst_delete_helper(x->right);
        bst_delete_node(x);
    }
}

static bst_node_t *bst_find_rightmost(bst_node_t *v)
{
    if (v == NULL || v->right == NULL)
    {
        return v;
    }
    else
    {
        return bst_find_rightmost(v->right);
    }
}

static bst_node_t *bst_remove_helper(bst_node_t *x, int data)
{
    assert(x != NULL);
    if (data < x->data)
        x->left = bst_remove_helper(x->left, data);
    else if (data > x->data)
    {
        x->right = bst_remove_helper(x->right, data);
    }
    else
    {
        if (x->left == NULL)
        {
            bst_node_t *y = x->right;
            bst_delete_node(x);
            x = y;
        }
        else if (x->right == NULL)
        {
            bst_node_t *y = x->left;
            bst_delete_node(x);
            x = y;
        }
        else
        {
            bst_node_t *previous_x = bst_find_rightmost(x->left);
            int aux = x->data;
            x->data = previous_x->data;
            previous_x->data = aux;
            x->left = bst_remove_helper(x->left, data);
        }
    }
    return x;
}