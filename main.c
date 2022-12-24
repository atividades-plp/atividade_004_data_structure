#include "filereader.h"

int main()
{
    char *file_content = file_2_string("data\\input.txt");
    if (file_content != NULL)
        printf(file_content);
    return 0;
}
