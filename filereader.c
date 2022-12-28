
#include "filereader.h"

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
    {
        int temp_number;
        sscanf(temp_char, "%d", &temp_number);
        add_list_node(list, temp_number);
    }
    fclose(file);
    return list;
}