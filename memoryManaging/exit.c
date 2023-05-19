#include "shell.h"
int myexit(char *word)
{
	if (strcmp(word, "exit") == 0)
		return(1);
	return (0);
}
