#include "integer.h"

int parse_int(char *string)
{
    int number;
    sscanf(string, "%d", &number);
    return number;
}