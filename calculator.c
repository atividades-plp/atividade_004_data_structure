#include "calculator.h"
#define BUFFER_SIZE 100
#define false 0
#define true 1

typedef int bool;

/* == Algoritmo para cálculo de uma expressão númerica ==
(2+(2+(5+1)))
*/
int calculate_expression_stack(char *expression)
{
    int length = strlen(expression);

    if (length == 0)
        return 0;

    int index = 0;
    stack *calculator = new_stack();
    char buffer[BUFFER_SIZE];
    while (index < length)
    {
        index++;
    }

    snode *node = pop(calculator);
    if (node == NULL)
        return 0;
    int expression_result = node->value;
    free(node);
    free(calculator);

    return expression_result;
}

int calculate_expression_tree(char *expression)
{
    return 0;
}
