#include <stdbool.h>
#include <stdlib.h>

bool bst_find_helper(bst_node_t *t, int x)
{
    if(t == NULL){
        return false;
    }
    if(t->data == x){
        return true;
    }
    if(t->data < x){
        return bst_find_helper(t->right, x);
    }
    return bst_find_helper(t->left, x);
}

bool bst_find(bst_t *t, int data)
{
    return bst_find_helper(t->root, data);
}