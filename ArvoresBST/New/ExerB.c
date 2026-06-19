#include <stdlib.h>
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

static bst_node_t *bst_new_node(int data)
{
    bst_node_t *ptr = malloc(sizeof(bst_node_t));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->data = data;
    return ptr;
}

bst_node_t *bst_insert_helper(bst_node_t *t, int data)
{
    if (t == NULL)
    {
        return bst_new_node(data);
    }
    assert(t->data != data);
    if (data < t->data)
    {
        t->left = bst_insert_helper(t->left, data);
    }
    else
    {
        t->right = bst_insert_helper(t->right, data);
    }
    return t;
}

void bst_insert(bst_t *t, int data)
{
    t->root = bst_insert_helper(t->root, data);
    t->size++;
}