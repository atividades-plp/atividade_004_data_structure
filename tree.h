#ifndef TREE_HEADER
#define TREE_HEADER
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int value;
    struct tnode *left;
    struct tnode *right;
} tnode;

typedef struct tree
{
    tnode *root;
} tree;

tree *new_tree();
void add_tree_node(tree *tree, tnode *root, int value);
void print_preorder(tnode *node);
void print_inorder(tnode *node);
void print_postorder(tnode *node);

#endif