#include "shell.h"

/**
 * main - start of main function
 * @argc: number of arguments passed
 * @argv: array of passed arguments
 * @envp: array of envoroment variables
 *
 * Return: 0 for sucess
 */
int main(int argc, char *argv[], char *envp[])
{
	while (1)
	{
		char **wordArray, /* *allPath = NULL, *tempAllPath = NULL,*/ *validPathName = NULL;
		int i;
		char *string = NULL, *delimiterArgument = " " /*, **pathArray, */ /* *delimiterPath = ":", *path = NULL */;
		size_t length = 0;
		ssize_t read;

		if (argc || argv || envp)
		{
			;
		}

		printf("$ ");
		/* Read the string using getlinein stdin(keyboard) stream */
		read = getline(&string, &length, stdin);
		if (read == -1)
		{
			free(string);
			perror("Getline error");
			exit(98);
		}
		/* remove the newline at the end ot the string */
		string[strlen(string) - 1] = '\0';

		wordArray = makeArray(string, delimiterArgument);
		validPathName = getpath(envp, wordArray);

		/* pathArray = makeArray(allPath, delimiterPath);*/

		/* free each index memory */
		i = 0;
		while (wordArray[i])
		{
			free(wordArray[i]);
			i++;
		}
		/* free the Arraymemory */
		free(wordArray);
		free(validPathName);
	}
	return (0);
}
