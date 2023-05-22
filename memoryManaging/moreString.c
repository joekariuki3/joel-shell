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

/**
 * _strchr - checks for first occurrence of the character char in the string
 * @s: string
 * @c: character to look for
 * Return: function returns a pointer.
 */
char *_strchr(char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
        {
            return ((char *)s);
        }
        s++;
    }

    if (c == '\0')
    {
        return ((char *)s);
    }
    return (NULL);
}