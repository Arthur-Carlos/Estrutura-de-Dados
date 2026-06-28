// arvore ZigZag

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool comparador(tree_node_t *t1, bool flag)
{
    if (t1 == NULL)
    {
        return true;
    }
    if (t1->left != NULL && t1->right != NULL)
    {
        return false;
    }
    if (flag)
    {
        if (t1->left != NULL)
        {
            return false; 
        }
        return comparador(t1->right, false);
    }
    else
    {
        if (t1->right != NULL)
        {
            return false;
        }
        return comparador(t1->left, true);
    }
}

bool is_zigzag(tree_t *t)
{
    if (t == NULL || t->root == NULL)
    {
        return true;
    }

    if (t->root->left == NULL && t->root->right == NULL)
    {
        return true;
    }

    if (t->root->left != NULL && t->root->right != NULL)
    {
        return false;
    }
    if (t->root->left != NULL)
    {
        return comparador(t->root->left, true);
    }
    return comparador(t->root->right, false);
}
