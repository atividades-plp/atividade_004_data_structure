#ifndef CALCULATOR_HEADER
#define CALCULATOR_HEADER
#include <string.h>

// Calcula uma expressão numérica (em notação infixa) utilizando uma pilha
int calculate_expression_stack(char *expression);

// Calcula uma expressão numérica de exemplo (2+(3*(5-1))) utilizando uma árvore de cálculo
int calculate_expression_tree();

#endif