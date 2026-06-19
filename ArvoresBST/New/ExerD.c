#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

bool is_bst_helper(tree_node_t *x, int min, int max)
{
    if (x == NULL)
    {
        return true;
    }
    if (x->data <= min || x->data >= max)
    {
        return false;
    }

    return is_bst_helper(x->left, min, x->data) && is_bst_helper(x->right, x->data, max);
}

bool is_bst(tree_t *t)
{
    if (t == NULL || t->root == NULL)
    {
        return true;
    }
    return is_bst_helper(t->root, INT_MIN, INT_MAX);
}