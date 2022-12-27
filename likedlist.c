#include "linkedlist.h"

list *new_list()
{
    list *nlist = (list *)malloc(sizeof(list));
    nlist->length = 0;
    nlist->data = NULL;
    return nlist;
}

lnode *new_list_node(int value)
{
    lnode *nnode = (lnode *)malloc(sizeof(lnode));
    nnode->value = value;
    nnode->next = NULL;
    return nnode;
}

void add(list *list, int value)
{
    lnode *nnode = new_list_node(value);
    if (list->length == 0)
    {
        list->data = nnode;
        list->length++;
        return;
    }
    lnode *temp_node = list->data;
    while (temp_node->next != NULL)
        temp_node = temp_node->next;
    temp_node->next = nnode;
    list->length++;
}