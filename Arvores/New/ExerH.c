// arvore Igualdade

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool comparador(tree_node_t *t1, tree_node_t *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return true;
    }

    if (t1 == NULL || t2 == NULL)
    {
        return false;
    }
    if (t1->data != t2->data)
    {
        return false;
    }

    return comparador(t1->left, t2->left) && comparador(t1->right, t2->right);
}

bool is_equal(tree_t *t1, tree_t *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return true;
    }

    if (t1 == NULL || t2 == NULL)
    {
        return false;
    }

    return comparador(t1->root, t2->root);
}