#include "calctree.h"
#include "operations.h"

ctnode *new_calctree_node(int value, int (*operation)(int, int))
{
    ctnode *nnode = (ctnode *)malloc(sizeof(ctnode));
    nnode->left = NULL;
    nnode->right = NULL;
    nnode->operation = operation;
    nnode->value = value;
    return nnode;
}

calctree *new_calctree()
{
    calctree *ntree = (calctree *)malloc(sizeof(calctree));
    ntree->root = NULL;
    return ntree;
}

int calculate_calctree(calctree *tree, ctnode *current_root)
{
    if (tree == NULL || tree->root == NULL)
        return 0;
    if (current_root->left == NULL && current_root->right == NULL)
        return current_root->value;

    int left = calculate_calctree(tree, current_root->left);
    int right = calculate_calctree(tree, current_root->right);

    int operation_result = current_root->operation(left, right);
    current_root->value = operation_result;
    return operation_result;
}
