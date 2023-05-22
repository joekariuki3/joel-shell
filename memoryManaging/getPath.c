#include "shell.h"
char *getPath(char **wordArray, char **enVars)
{
    char *allPath = NULL, *tempPath = NULL, *path = NULL, *pathName = NULL;
    int i = 0, pathNameSize = 0;
    if (wordArray == NULL)
    {
        perror("WordArray NULL");
        return (NULL);
    }

    else if (enVars == NULL)
    {
        perror("enVars NULL");
        return (NULL);
    }

    /* loop through enVars vector to find the path variable */
    for (i = 0; enVars[i] != NULL; i++)
    {
        /*look for PATH using strncmp*/
        if (_strncmp(enVars[i], "PATH=", 5) == 0)
        {
            allPath = enVars[i] + 5; /*remove PATH=*/
            break;
        }
    }
    /* check if allPath was found */
    if (allPath == NULL)
    {
        perror("allPath not found");
        exit(1);
    }

    /* Make a copy of allPath n use the copy */
    tempPath = _strdup(allPath);

    path = strtok(tempPath, ":");

    while (path)
    {

        if ((_strchr(wordArray[0], '/')) == NULL)
        {
            /* get the size of the complete pathName */
            pathNameSize = _strlen(path) + _strlen("/") + _strlen(wordArray[0]);
            /* allocate memory for the pathName */
            pathName = (char *)malloc(pathNameSize * sizeof(char *));
            if (pathName == NULL)
            {
                perror("Memory to PathName failed");
                exit(1);
            }
            /* copy path to the pathname */
            _strcpy(pathName, path);

            /* add / to pathname */
            _strcat(pathName, "/");

            /* add the 1st argument to the path */
            _strcat(pathName, wordArray[0]);
        }
        else
        {
            /* copy WordArray to PathName */
            pathName = _strdup(wordArray[0]);
        }

        /* check if the full pathName is valid n executable */
        if (access(pathName, X_OK) != 0)
        {
            /*free pathname*/
            free(pathName);

            /* move to next path*/
            path = strtok(NULL, ":");
        }
        else
        {
            /* if path is valid*/
            /*free tempPath allocated by _strdup()*/
            free(tempPath);
            /* return the valid path n exit.. it will be freed where it is being returned*/
            return (pathName);
        }
    }
    /* finish looping without getting valid path free tempPath allocated by _strdup()*/
    free(tempPath);
    /* print error*/
    perror(wordArray[0]);
    return (NULL);
}
