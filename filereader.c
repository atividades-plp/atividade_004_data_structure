
#include "filereader.h"

string *new_string()
{
    string *nstring = (string *)malloc(sizeof(string));
    nstring->length = 0;
    nstring->data = NULL;
    return nstring;
}

schar *new_schar(char character)
{
    schar *nchar = (schar *)malloc(sizeof(schar));
    nchar->value = character;
    nchar->next = NULL;
    return nchar;
}

void add(string *text, char character)
{
    schar *nchar = new_schar(character);
    if (text->length == 0)
    {
        text->data = nchar;
        text->length++;
        return;
    }
    schar *temp_char = text->data;
    while (temp_char->next != NULL)
        temp_char = temp_char->next;
    temp_char->next = nchar;
    text->length++;
}

string *file_2_string(char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot open this file: %s", filename);
        return NULL;
    }
    string *text = new_string();
    char temp_char;

    while (!feof(file))
    {
        temp_char = fgetc(file);
        if (temp_char != ' ')
            add(text, temp_char);
    }
    fclose(file);
    return text;
}