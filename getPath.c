#include "shell.h"
/**
 * getPath - gets PATH and looks for valid path to execute
 * @wordArray: Array of comands entered
 * @enVars: Array of enviros
 * Return: null or valid path to execute
 */
char *getPath(char **wordArray, char **enVars)
{
	char *allPath = NULL, *tempPath = NULL, *path = NULL, *pathName = NULL;
	int pathNameSize = 0;

	if (wordArray == NULL || enVars == NULL)
		return (NULL);
	allPath = extractPATH(enVars);/* call extractPATH*/
	if (allPath == NULL)
		exit(1);
	tempPath = _strdup(allPath); /* Make a copy of allPath n use the copy */
	path = strtok(tempPath, ":");
	while (path)
	{
		if ((_strchr(wordArray[0], '/')) == NULL)
		{
			pathNameSize = _strlen(path) + _strlen("/") + _strlen(wordArray[0]);
			pathName = (char *)malloc(pathNameSize * sizeof(char *));
			if (pathName == NULL)
				exit(1);
			_strcpy(pathName, path);/*copy path to the pathname*/
			_strcat(pathName, "/");	/* add / to pathname*/
			_strcat(pathName, wordArray[0]); /* add the 1st argument to the path */
		}
		else
			pathName = _strdup(wordArray[0]); /*copy WordArray to PathName */
		if (access(pathName, X_OK) != 0)	  /*check pathName is valid n executable */
		{
			free(pathName);
			path = strtok(NULL, ":"); /* move to next path*/
		}
		else /* if path is valid*/
		{
			free(tempPath); /*free tempPath allocated by _strdup()*/
			return (pathName);/*return the valid path n exit freed where returned*/
		}
	} /*looping no valid path free tempPath allocated by _strdup()*/
	free(tempPath);
	perror(wordArray[0]); /* print error*/
	return (NULL);
}
/**
 * extractPATH - get PATH variable from environment
 * @enVars: pointer to array of enviroment variables
 * Return: PATH or null on fail
 */
char *extractPATH(char **enVars)
{
	char *PATH = NULL;
	int i = 0;

	if (enVars != NULL)
	{
		for (i = 0; enVars[i] != NULL; i++) /* loop through enVars PATH*/
		{
			if (_strncmp(enVars[i], "PATH=", 5) == 0) /*look for PATH using _strncmp*/
			{
				PATH = enVars[i] + 5; /*remove PATH=*/
				break;
			}
		}
		if (PATH == NULL) /* check if allPath was found */
			return (NULL);
		return (PATH);
	}
	return (NULL);
}
