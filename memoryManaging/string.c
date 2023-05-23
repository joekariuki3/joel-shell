#include "shell.h"
/**
 * _strlen - returns length l of a string s
 * @s: string passed to check its length
 * Return: length on success otherwise 1
 */
unsigned long int _strlen(char *s)
{
	unsigned long int l;

	if (s == NULL)
		return (1);
	l = 0;
	while (s[l])
	{
		l++;
	}
	return (l);
}

/**
 * _strcat - joins two strings together
 * @dest: where the new string will be appended
 * @src: the string to be appended to dest
 * Return: dest string having src at its tail
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	/* check for null string */
	if (dest == NULL && src)
	{
		return (src);
	}
	if (src == NULL && dest)
	{
		return (dest);
	}
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}

	/*move pointer to end of dest string*/

	while (*ptr)
	{
		ptr++;
	}

	/*copy char from src to dest */
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	/*add null terminator end of dest*/
	*ptr = '\0';

	return (dest);
}

/**
 * _strcpy - copy src string to dest string
 * @dest: where the new string will be copied
 * @src: the string to be copied to dest
 * Return: dest string having src at its tail
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	/* check for null string */
	if (dest == NULL && src)
	{
		return (src);
	}
	if (src == NULL && dest)
	{
		return (dest);
	}
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}

	/*copy char from src to dest */
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	/*add null terminator end of dest*/
	*ptr = '\0';

	return (dest);
}

/**
 * _strcmp - compares string 1 and string 2
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if match else deference of char that differ ascii value
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((*(char *)s1) - (*(char *)s2));
}

/**
 * _strncmp - compares string 1 and string 2 up to n char
 * @s1: string 1
 * @s2: string 2
 * @n: size
 * Return: 0 if match else deference of char that differ ascii value
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	/* check if n has reached to 0 meaning string is equal up to n char*/
	if (n == 0)
	{
		return (0);
	}
	return ((*(char *)s1) - (*(char *)s2));
}
