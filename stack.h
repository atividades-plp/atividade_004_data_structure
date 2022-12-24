#ifndef STACK_FILE
#define STACK_FILE
#include <stdio.h>
#include <stdlib.h>

typedef struct snode
{
    int value;
    struct snode *next_node;
} snode;

typedef struct stack
{
    int length;
    snode *data;
} stack;

stack *new_stack();
void *push(stack *stack, int value);
snode *pop(stack *stack);

#endif