#include "shell.h"
char *getpath(char **envp, char **wordArray)
{
    char *ALLPATH = NULL, *path = NULL, *pathName = NULL, *tempAllPath = NULL;
    int i, status;
    size_t pathNameSize = 0;
    pid_t pid;

    /* loop through envp vector to find the path variable */
    for (i = 0; envp[i] != NULL; i++)
    {
        /*look for PATH using strncmp*/
        if (strncmp(envp[i], "PATH=", 5) == 0)
        {
            ALLPATH = envp[i] + 5; /*remove PATH=*/
            break;
        }
    }

    /* check if ALLPATH was found */
    if (ALLPATH == NULL)
    {
        perror("ALLPATH not found");
        exit(98);
    }
    tempAllPath = strdup(ALLPATH);
    /*path found, loop throuh the ALLPATH extracting path*/
    path = strtok(tempAllPath, ":");

    i = 0;
    while (path)
    {

        /* get the size of the complete pathname */
        pathNameSize = _strlen(path) + _strlen("/") + _strlen(wordArray[0]);
        /* allocate memory for the pathname */
        pathName = (char *)malloc(pathNameSize);
        if (pathName == NULL)
        {
            perror("Memory to PathName failed");
            exit(1);
        }

        /* copy path to the pathname */
        strcpy(pathName, path);

        /* add / to pathname */
        strcat(pathName, "/");

        /* add the 1st argument to the path */
        strcat(pathName, wordArray[0]);

        /* check if the full pathName is valid n executable */
        if (access(pathName, X_OK) == 0)
        {
            pid = fork();
            /*  Check if fork was a success */
            if (pid == -1)
            {
                perror("Fork failed");
                exit(1);
            }

            if (pid == 0)
            {

                if (execve(pathName, wordArray, envp) == -1)
                {
                    perror("Execution failed");
                    exit(1);
                }
                return (pathName);
                free(pathName);
                break;
            }
            if (waitpid(pid, &status, 0) == -1)
            {
                perror("Error on Wait");
                exit(1);
            }

            break;
        }
        else
        {

            /* free pathName memory*/
            pathName = NULL;
            free(pathName);

            /* get the next path */
            path = strtok(NULL, ":");
        }
    }
    if (!path)
    {
        perror(wordArray[0]);
    }
    free(tempAllPath);
    /* argument not found */
    return (NULL);
}
