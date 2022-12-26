#include "filereader.h"

void print_string(string text)
{
    if (text.length == 0)
        return;
    while (text.data != NULL)
    {
        printf("%c", text.data->value);
        text.data = text.data->next;
    }
}

int main()
{
    string *file_content = file_2_string("C:\\Users\\Gabriel\\OneDrive\\Documentos\\projetos\\github\\atividade_004_data_structure\\data\\input.txt");
    print_string(*file_content);
    return 0;
}
