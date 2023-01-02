#include "filereader.h"
#include "calculator.h"

int main()
{
    // list *file_content = file_2_numbers("./data/input.txt");
    printf("Resultado: %d", calculate_expression_stack("(2+(3+(5-1)))"));
    return 0;
}