#ifndef STACK_HEADER
#define STACK_HEADER
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

// Cria uma nova pilha
stack *new_stack();

// Empilha um elemento em uma pilha
void *push(stack *stack, int value);

// Desempilha um elemento em uma pilha
snode *pop(stack *stack);

// Imprime os elementos de uma pilha
void print_stack(stack *stack);

#endif