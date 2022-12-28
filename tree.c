#include "tree.h"

tnode *new_tree_node(int value)
{
    tnode *nnode = (tnode *)malloc(sizeof(tnode));
    nnode->left = NULL;
    nnode->right = NULL;
    nnode->value = value;
    return nnode;
}

tree *new_tree()
{
    tree *ntree = (tree *)malloc(sizeof(tree));
    ntree->root = NULL;
    return ntree;
}

void add_tree_node(tree *tree, tnode *current_root, int value)
{
    if (tree->root == NULL)
    {
        tree->root = new_tree_node(value);
        return;
    }
    if (value < current_root->value)
    {
        if (current_root->left != NULL)
            return add_tree_node(tree, current_root->left, value);
        current_root->left = new_tree_node(value);
        return;
    }
    if (current_root->right != NULL)
        return add_tree_node(tree, current_root->right, value);
    current_root->right = new_tree_node(value);
}

void print_preorder(tnode *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->value);
    print_preorder(node->left);
    print_preorder(node->right);
}

void print_inorder(tnode *node)
{
    if (node == NULL)
        return;
    print_inorder(node->left);
    printf("%d ", node->value);
    print_inorder(node->right);
}

void print_postorder(tnode *node)
{
    if (node == NULL)
        return;
    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d ", node->value);
}
