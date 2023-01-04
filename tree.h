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

// Cria uma árvore
tree *new_tree();

// Adiciona elementos em uma árvore
void add_tree_node(tree *tree, tnode *root, int value);

// Imprime elementos de uma árvore (Pre-ordem)
void print_preorder(tnode *node);

// Imprime elementos de uma árvore (Em-ordem)
void print_inorder(tnode *node);

// Imprime elementos de uma árvore (Pós-ordem)
void print_postorder(tnode *node);

#endif