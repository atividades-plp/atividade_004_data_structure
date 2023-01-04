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

calctree *new_calctree();
void add_calctree_node(calctree *tree, int value, int (*operation)(int, int));
int calculate_calctree(calctree *tree, ctnode *current_root);

#endif