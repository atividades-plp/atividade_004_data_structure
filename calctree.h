#ifndef CALCTREE_HEADER
#define CALCTREE_HEADER
#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED -1

typedef struct ctnode
{
    int value;
    int (*operation)(int, int);
    struct ctnode *left;
    struct ctnode *right;
} ctnode;

typedef struct calctree
{
    ctnode *root;
} calctree;

// Cria um novo nó para a árvore de cálculo
ctnode *new_calctree_node(int value, int (*operation)(int, int));

// Cria uma nova árvore de cálculo
calctree *new_calctree();

// Calcula recursivamente o resultado da árvore de cálculo
int calculate_calctree(calctree *tree, ctnode *current_root);

#endif