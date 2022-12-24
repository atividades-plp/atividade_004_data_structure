
#include "filereader.h"

typedef struct schar
{
    char value;
    struct schar *next;
} schar;

typedef struct string
{
    int length;
    schar *data;
} string;

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

char *string_2_char_array(string *text)
{
    char *char_array = (char *)malloc(sizeof(char) * text->length);
    int index = 0;
    while (text->data != NULL)
    {
        char_array[index] = text->data->value;
        index++;
        text->data = text->data->next;
    }
    return char_array;
}

char *file_2_string(char *filename)
{
    FILE *file = NULL;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot open this file: %s", filename);
        return NULL;
    }
    string *text = new_string();
    char temp_char;

    while (temp_char != EOF)
    {
        temp_char = fgetc(file);
        add(text, temp_char);
    }
    fclose(file);
    char *file_content = string_2_char_array(text);
    free(text);
    return file_content;
}