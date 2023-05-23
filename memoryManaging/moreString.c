#include "shell.h"
/**
 * _strdup - makes a copy of a string
 * @str: string passed
 * Return: returns pointer to nely created string
 */
char *_strdup(char *str)
{
	size_t newLength = _strlen(str) + 1;
	char *newString = malloc(newLength), *newPtr = NULL;

	if (newString != NULL)
	{
		newPtr = newString;
		while (*str != '\0')
			*newPtr++ = *str++;/* copy each character*/
		*newPtr = '\0';/* add null terminator*/
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
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
