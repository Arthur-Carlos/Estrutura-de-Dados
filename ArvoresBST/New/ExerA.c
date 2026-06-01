#include <stdbool.h>
#include <stdlib.h>

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

bool bst_find_helper(bst_node_t *t, int data){
    if (t == NULL){
        return false;
    }
    if(data == t->data){
        return true;
    }
    if(data < t->data){
        return bst_find_helper(t->left, data);
    }
    return bst_find_helper(t->right, data);
}

bool bst_find(bst_t *t, int data){
    return bst_find_helper(t->root, data);
}