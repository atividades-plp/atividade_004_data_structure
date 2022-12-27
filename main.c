#include "filereader.h"

void print_string(list text)
{
    if (text.length == 0)
        return;
    printf("Quantidade: %d\n", text.length);
    while (text.data != NULL)
    {
        printf("%d\n", text.data->value);
        text.data = text.data->next;
    }
}

int main()
{
    list *file_content = file_2_numbers("C:\\Users\\Gabriel\\OneDrive\\Documentos\\projetos\\github\\atividade_004_data_structure\\data\\input.txt");
    print_string(*file_content);
    return 0;
}
