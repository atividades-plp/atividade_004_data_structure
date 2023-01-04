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

// Verifica se símbolo é uma operação suportada
bool is_operation(char symbol)
{
    return symbol == '-' || symbol == '+' || symbol == '*' || symbol == '/';
}

// Retorna o ID da operação representada pelo símbolo
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

// Verifica se símbolo é um inteiro
bool is_integer(char symbol)
{
    char numbers[] = "0123456789";
    int length = 10;
    for (int index = 0; index < length; index++)
        if (symbol == numbers[index])
            return true;
    return false;
}

// Encapsula as operações matemáticas suportadas
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

// Cria um buffer de char para ser utilizado como variável auxiliar
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

        if (is_integer(symbol)) // Se inteiro, concatena-o na string para que seja transformado em inteiro
        {
            char text[] = {symbol, '\0'};
            strcat(buffer, text);

            if (!is_integer(expression[index + 1]))
                push(numbers, parse_int(buffer)); // Adiciona o inteiro a pilha
        }
        else if (is_operation(symbol)) // Se operação, adiciona operação na pilha e renova o buffer
        {
            operation_id operation = get_operation(symbol);
            push(operations, operation);
            buffer = new_buffer();
        }
        else if (symbol == ')') // Se ), realiza o cálculo do resultado e adiciona novamente na pilha
        {
            int y = pop(numbers)->value;
            int x = pop(numbers)->value;
            operation_id operation = pop(operations)->value;
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
