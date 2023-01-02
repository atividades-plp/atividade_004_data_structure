#include "calculator.h"
#include "integer.h"
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

int sum(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int divs(int x, int y)
{
    return x / y;
}

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
            char text[] = {symbol, '\0'};
            strcat(buffer, text);

            if (!is_integer(expression[index + 1]))
            {
                printf("Adicionando...%d\n", parse_int(buffer));
                push(numbers, parse_int(buffer));
            }
        }
        else if (is_operation(symbol))
        {
            operation_id operation = get_operation(symbol);
            push(operations, operation);
            buffer = new_buffer();
        }
        else if (symbol == ')')
        {
            int y = pop(numbers)->value;
            int x = pop(numbers)->value;
            operation_id operation = pop(operations)->value;
            push(numbers, wrapper(operation, x, y));
        }
        index++;
    }

    free(numbers);
    free(operations);
    return pop(numbers)->value;
}

int calculate_expression_tree(char *expression)
{
    return 0;
}
