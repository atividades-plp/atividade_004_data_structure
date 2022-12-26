#ifndef FILE_HEADER
#define FILE_HEADER
#include <stdio.h>
#include <stdlib.h>

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

string *file_2_string(char *filename);

#endif