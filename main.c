#include "shell.h"

/**
 * main - start of main function
 * @argc: number of arguments passed
 * @argv: array of passed arguments
 * @envp: array of envoroment variables
 *
 * Return: 0 for sucess
 */
int main()
{
	char *string = NULL, *word = NULL, **wordArray;
	int wordLength = 0, wordArraySize = 0, i = 0, index;
	size_t length = 0;
	ssize_t read;

	printf("$ ");

	/* Read the string using getlinein stdin(keyboard) stream */
	read = getline(&string, &length, stdin);

	if (read == -1)
		exit(98);

	/* remove the newline at the end ot the string */
	string[strlen(string) -1] = '\0';

	/* split the string to individual words using strtok */
	word = strtok(string, " ");

	/* allocate momory to wordArray */
	wordArray = (char **) malloc(sizeof(char *));
	if(wordArray == NULL)
		exit(98);

	/* loop through the string getting each word*/
	while(word != NULL)
	{
		/* increase wordArraySize */
		wordArraySize++;
		
		/* resize the array n add current word*/
		wordArray = (char **) realloc(wordArray,
				wordArraySize * sizeof(char *));
		if(wordArray == NULL)
			exit(98);
		/* append word to wordArray */
		/* assign memory word to be stored in wordArray[index] */
		wordLength = strlen(word) + 1;
		index = wordArraySize - 1;
		wordArray[index] = (char *) malloc(wordLength * sizeof(char));
		if (wordArray[index] == NULL)
			exit(98);
		/* now append the word by coping it to wordArray[index] */
		strcpy(wordArray[index], word);

		/* extraxt the next argument(word)*/
		word = strtok(NULL, " ");
	}

	/* display the arguments*/
for (i = 0; wordArray[i] != NULL; i++)
{
	printf("%s\n", wordArray[i]);
}	

	return(0);
}
