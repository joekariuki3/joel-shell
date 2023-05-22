#include "shell.h"
char *_strdup(char *str)
{
    size_t newLength = _strlen(str) + 1;
    char *newString = malloc(newLength);
    char *newPtr = NULL;

    if (newString != NULL)
    {
        newPtr = newString;
        while (*str != '\0')
        {
            /* copy each character*/
            *newPtr++ = *str++;
        }
        /* add null terminator*/
        *newPtr = '\0';
    }

    return (newString);
}