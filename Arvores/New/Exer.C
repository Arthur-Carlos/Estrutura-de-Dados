// arvore ZigZag

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree_node_t
{
    int data;
    struct tree_node_t *left;
    struct tree_node_t *right;
} tree_node_t;

typedef struct tree_t
{
    tree_node_t *root;
} tree_t;


bool comparador(tree_node_t *t1)
{
    if (t1->left == NULL && t1->right == NULL)
    {
        return true;
    }
    if (t1->left == NULL)
    {
        if (t1->right->left == NULL && t1->right->right != NULL)
        {
            return false;
        }
        comparador(t1->right);
    }
    if (t1->right == NULL)
    {
        if (t1->left->left != NULL && t1->left->right == NULL)
        {
            return false;
        }
        comparador(t1->left);
    }
    return false;
}

bool is_full(tree_t *t1)
{
    if (t1 == NULL)
    {
        return true;
    }
    return comparador(t1->root);
}
