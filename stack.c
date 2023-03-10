#include "stack.h"

snode *new_stack_node(int value)
{
    snode *nnode = (snode *)malloc(sizeof(snode));
    nnode->next_node = NULL;
    nnode->value = value;
    return nnode;
}

stack *new_stack()
{
    stack *nstack = (stack *)malloc(sizeof(stack));
    nstack->data = NULL;
    nstack->length = 0;
    return nstack;
}

void *push(stack *stack, int value)
{
    snode *nnode = new_stack_node(value);
    nnode->next_node = stack->data;
    stack->data = nnode;
    stack->length++;
}

snode *pop(stack *stack)
{
    if (stack->length == 0)
        return NULL;
    snode *node = stack->data;
    stack->data = stack->data->next_node;
    stack->length--;
    return node;
}

void print_stack(stack *stack)
{
    if (stack->length == 0)
    {
        printf("Pilha vazia.");
        return;
    }
    snode *node = stack->data;
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next_node;
    }
}