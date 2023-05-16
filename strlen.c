#include "shell.h"
/**
 * _strlen - returns length l of a string s
 * @s: string passed to check its length
 * Return: length on sucess otherwise 1
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
