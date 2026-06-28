// Busca em Profundidade pos ordem
#include <stdio.h>

void dfs_in_aux(tree_node_t *node)
{
    if (node == NULL)
    {
        return;
    }

    dfs_in_aux(node->left);
    dfs_in_aux(node->right);
    printf("%d\n", node->data);
}

void dfs_pos(tree_t *t)
{
    if (t == NULL)
    {
        return;
    }
    dfs_in_aux(t->root);
}