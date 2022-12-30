#include "filereader.h"
#include "integer.h"

list *file_2_numbers(char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot open this file: %s", filename);
        return NULL;
    }
    list *list = new_list();
    char temp_char[50];

    while (fgets(temp_char, 50, file) != NULL)
        add_list_node(list, parse_int(temp_char));
    fclose(file);
    return list;
}