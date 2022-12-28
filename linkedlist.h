#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER
#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    int value;
    struct lnode *next;
} lnode;

typedef struct list
{
    int length;
    lnode *data;
} list;

list *new_list();
void add_list_node(list *list, int value);

#endif