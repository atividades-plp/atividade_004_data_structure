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

// Cria uma nova lista encadeada
list *new_list();

// Adiciona um novo nó na lista encadeada
void add_list_node(list *list, int value);

// Imprime os valores de uma lista encadeada
void print_list(list *list);

#endif