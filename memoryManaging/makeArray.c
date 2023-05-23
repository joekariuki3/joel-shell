#include "shell.h"
/**
 * makeArray - read input makes calls getWordArray checks validPath
 * @enVars: environment variables
 */
void makeArray(char **enVars)
{
	char *string = NULL, **wordArray = NULL, *validPath = NULL;
	int status;
	pid_t pid;
	size_t length = 0, i = 0;
	ssize_t read;

	read = getline(&string, &length, stdin);
	if (read == -1)
	{
		free(string);
		exit(1);
	}
	string[_strlen(string) - 1] = '\0'; /* remove the newline*/
	wordArray = getWordArray(string, enVars);   /* make array from string*/
	if (wordArray != NULL)
	{
		validPath = getPath(wordArray, enVars); /* Look for executable */
		if (validPath)
		{ /* if path is valid create a child process n execute it*/
			pid = fork();
			if (pid == -1)/*fork process failed*/
				perror("Fork() failed");
			if (pid == 0)/*child process*/
				execve(validPath, wordArray, enVars);
			if (pid != 0)/* back to parent process */
				wait(&status); /* wait for child to finish*/
			free(validPath); /* free validPath that ws returned from getPath()*/
		}
		if (string)
			free(string); /* free string  allocated memory with getline()*/
		if (wordArray)
		{
			for (i = 0; wordArray[i] != NULL; i++)
				free(wordArray[i]); /* free wordArray[i] allocated memory with _strdup() */
			free(wordArray);/* free Word Array */
		}
	}
}
/**
 * getWordArray - makes array out of string passed
 * @string: string passed
 * @enVars: pointer to environment array
 * Return: a pointer to the wordArray or null
 */
char **getWordArray(char *string, char **enVars)
{
	char *word = NULL, **wordArray = NULL;
	int isExit = 0, isEnv = 0;
	size_t wordCount = 0;

	word = strtok(string, " ");
	if (word == NULL)
	{
		if (string)
			free(string);
		return (NULL);
	}
	isExit = myexit(word); /* check word if it exit*/
	if (isExit == 1)
	{
		free(string);
		exit(0);
	}
	isEnv = myenv(word, enVars); /* check  env cmd n print enviros */
	if (isEnv == 1)
	{
		free(string);
		return (NULL);
	}
	while (word != NULL)
	{
		wordArray = _realloc(wordArray, (wordCount * sizeof(char *)),
				(wordCount + 1) * sizeof(char *));
		if (wordArray == NULL)
			return (NULL);
		wordArray[wordCount] = _strdup(word); /*append each word to the wordArray */
		wordCount++;
		word = strtok(NULL, " ");
	}
	wordArray = _realloc(wordArray, (wordCount * sizeof(char *)),
			(wordCount + 1) * sizeof(char *));
	if (wordArray == NULL)
		return (NULL);
	wordArray[wordCount] = NULL;/* add null terminator*/
	return (wordArray);
}
