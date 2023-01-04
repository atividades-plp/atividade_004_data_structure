#include "calculator.h"
#include "stack.h"
#include "tree.h"
#include "hashtable.h"
#include "filereader.h"

void print_title(char *title)
{
    printf("=== ");
    printf(title);
    printf(" === \n");
}

void break_line()
{
    printf("\n");
}

void break_lines(int lines)
{
    for (int index = 0; index < lines; index++)
        break_line();
}

stack *list_2_stack(list *numbers)
{
    stack *nstack = new_stack();
    lnode *node = numbers->data;
    while (node != NULL)
    {
        push(nstack, node->value);
        node = node->next;
    }
    return nstack;
}

tree *list_2_tree(list *numbers)
{
    tree *ntree = new_tree();
    lnode *node = numbers->data;
    while (node != NULL)
    {
        add_tree_node(ntree, ntree->root, node->value);
        node = node->next;
    }
    return ntree;
}

hashtable *list_2_hashtable(list *numbers)
{
    hashtable *nhashtable = new_hashtable(numbers->length);
    lnode *node = numbers->data;
    while (node != NULL)
    {
        add_hash_node(nhashtable, node->value, node->value);
        node = node->next;
    }
    return nhashtable;
}

int main()
{
    list *numbers = file_2_numbers("./data/input.txt");
    print_title("NUMEROS LIDOS DO ARQUIVO");
    print_list(numbers);
    break_lines(2);

    if (numbers == NULL || numbers->length == 0)
        return 0;

    print_title("Lendo dados de um arquivo e alocando em uma PILHA");
    print_stack(list_2_stack(numbers));
    break_line();

    print_title("Lendo dados de um arquivo e alocando em uma ARVORE BINARIA");
    print_inorder(list_2_tree(numbers)->root);
    break_line();

    print_title("Lendo dados de um arquivo e alocando em uma TABELA HASH");
    print_hashtable(list_2_hashtable(numbers));
    break_lines(2);

    print_title("Calculadora utilizando PILHA");
    char *expression = "(2+(3*(5-1)))";
    printf("%s = %d", expression, calculate_expression_stack(expression));
    break_line();

    print_title("Calculadora utilizando ARVORE BINARIA");
    printf("%s = %d", expression, calculate_expression_tree(expression));

    return 0;
}