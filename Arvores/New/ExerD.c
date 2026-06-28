// arvore Cheia

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool comparador(tree_node_t *t1)
{
    if (t1 == NULL)
    {
        return true;
    }

    if ((t1->left == NULL) != (t1->right == NULL))
    {
        return false;
    }
    return comparador(t1->left) && comparador(t1->right);
}

bool is_full(tree_t *t1)
{
    if (t1 == NULL || t1->root == NULL)
    {
        return true;
    }
    return comparador(t1->root);
}