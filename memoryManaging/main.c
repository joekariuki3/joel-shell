#include "shell.h"

/**
 * main - start of main function
 * @argc: number of arguments passed
 * @argv: array of passed arguments
 * @envp: array of enviroment variables
 *
 * Return: 0 for success
 */
int main(int argc, char *argv[], char *envp[])
{
	while (1)
	{
		short prompt, space;

		if (argc || argv || envp)
		{
			;
		}

		prompt = 36;
		space = 32;
		/* write $ on the screen */
		write(1, &prompt, 1);
		write(1, &space, 1);

		/* read a line and create array */
		makeArray(envp);
	}
	return (0);
}
