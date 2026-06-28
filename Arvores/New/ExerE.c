// Busca em Profundidade pre ordem
#include <stdio.h>

void dfs_in_aux(tree_node_t *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d\n", node->data);
    dfs_in_aux(node->left);
    dfs_in_aux(node->right);
}

void dfs_pre(tree_t *t)
{
    if (t == NULL)
    {
        return;
    }
    dfs_in_aux(t->root);
}