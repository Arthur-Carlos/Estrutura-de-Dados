// Arvore Espelhada
#include <stdio.h>
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
    return comparador(t1->left, t2->right) && comparador(t1->right, t2->left);
}

bool is_mirrored(tree_t *t)
{
    if (t == NULL || t->root = NULL)
    {
        return true;
    }
    return comparador(t->root->left, t->root->right);
}