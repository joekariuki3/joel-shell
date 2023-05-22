#include "shell.h"
/**
 * myexit - checks for exit command and terminates program
 * @word: command to check
 * Return: 1 if successful 0 if not
 */
int myexit(char *word)
{
	if (_strcmp(word, "exit") == 0)
		return (1);
	return (0);
}
