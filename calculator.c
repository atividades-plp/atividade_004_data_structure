#include "calculator.h"
#include "stack.h"
#include "calctree.h"
#include "integer.h"
#include "operations.h"
#define false 0
#define true 1
#define BUFFER_SIZE 100
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4
#define UNDEFINED -1

typedef int bool;
typedef int operation_id;

bool is_operation(char symbol)
{
    return symbol == '-' || symbol == '+' || symbol == '*' || symbol == '/';
}

operation_id get_operation(char symbol)
{
    if (symbol == '+')
        return ADDITION;
    if (symbol == '-')
        return SUBTRACTION;
    if (symbol == '*')
        return MULTIPLICATION;
    if (symbol == '/')
        return DIVISION;
    return UNDEFINED;
}

bool is_integer(char symbol)
{
    char numbers[] = "0123456789";
    int length = 10;
    for (int index = 0; index < length; index++)
        if (symbol == numbers[index])
            return true;
    return false;
}

int wrapper(operation_id operation, int x, int y)
{
    if (operation == MULTIPLICATION)
        return mul(x, y);
    if (operation == ADDITION)
        return sum(x, y);
    if (operation == SUBTRACTION)
        return sub(x, y);
    if (operation == DIVISION)
        return divs(x, y);
    return 0;
}

char *new_buffer()
{
    char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    strcpy(buffer, "0");
    return buffer;
}

int calculate_expression_stack(char *expression)
{
    int length = strlen(expression);

    if (length == 0)
        return 0;

    int index = 0;
    stack *numbers = new_stack();
    stack *operations = new_stack();
    char *buffer = new_buffer();

    while (index < length)
    {
        char symbol = expression[index];

        if (is_integer(symbol))
        {
            // printf("Inteiro: %c\n", symbol);
            char text[] = {symbol, '\0'};
            strcat(buffer, text);

            if (!is_integer(expression[index + 1]))
                push(numbers, parse_int(buffer));
        }
        else if (is_operation(symbol))
        {
            // printf("Operação: %c\n", symbol);
            operation_id operation = get_operation(symbol);
            push(operations, operation);
            buffer = new_buffer();
        }
        else if (symbol == ')')
        {
            int y = pop(numbers)->value;
            int x = pop(numbers)->value;
            operation_id operation = pop(operations)->value;
            // printf("Calculando: %d %d %d\n", x,operation,y);
            push(numbers, wrapper(operation, x, y));
        }
        index++;
    }
    int expression_result = pop(numbers)->value;
    free(numbers);
    free(operations);
    return expression_result;
}

int calculate_expression_tree()
{
    calctree *tree = new_calctree();
    tree->root = new_calctree_node(UNDEFINED, sum);
    tree->root->left = new_calctree_node(2, NULL);
    tree->root->right = new_calctree_node(UNDEFINED, mul);
    tree->root->right->left = new_calctree_node(3, NULL);
    tree->root->right->right = new_calctree_node(UNDEFINED, sub);
    tree->root->right->right->left = new_calctree_node(5, NULL);
    tree->root->right->right->right = new_calctree_node(1, NULL);
    return calculate_calctree(tree, tree->root);
}
