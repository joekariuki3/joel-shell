#include "shell.h"
void makeArray(char **enVars)
{
    char *string = NULL, *word = NULL, **wordArray = NULL, *validPath = NULL;
    int isExit = 0, wordCount = 0, i = 0, status;
    size_t length = 0;
    ssize_t read;
    pid_t pid;

    /* read line entered */
    read = getline(&string, &length, stdin);
    /*confirm line was read */
    if (read == -1)
    {
        perror("Getline reached end of line");
        exit(1);
    }

    /* remove the newline at the end ot the string */
    string[_strlen(string) - 1] = '\0';

    /* split the string to individual words using strtok */
    word = strtok(string, " ");
    if (word == NULL)
    {
        free(string);
        perror("end of string");
        exit(1);
    }

    /* check 1st word if it exit by calling the exit function  */
    isExit = myexit(word);
    if (isExit == 1)
    {
        free(string);
        exit(0);
    }

    /* count number of words to know amount of memory to allocate */
    while (word != NULL)
    {
        wordArray = realloc(wordArray, (wordCount + 1) * sizeof(char *));
        if (wordArray == NULL)
        {
            perror("Memory re allocation failed");
            exit(1);
        }
        /* Now lets append each word to the wordArray */
        wordArray[wordCount] = strdup(word);
        wordCount++;
        word = strtok(NULL, " ");
    }

    /*add null terminator to word array*/
    wordArray = realloc(wordArray, (wordCount + 1) * sizeof(char *));
    wordArray[wordCount] = NULL;

    /* Look for executable */
    validPath = getPath(wordArray, enVars);
    if (validPath)
    {
        /* if path is valid create a child process n execute it*/
        pid = fork();
        if (pid == -1)
        {
            /*fork process failed*/
            perror("Fork() failed");
            exit(1);
        }
        if (pid == 0)
        {
            /*child process*/
            execve(validPath, wordArray, enVars);
        }
        if (pid != 0)
        {
            wait(&status);
        }
        /* free validPath that ws returned from getPath()*/
        free(validPath);
    }

    /* free string  allocated memory with getline()*/
    free(string);

    /* free wordArray[i] allocated memory with strdup() */
    for (i = 0; i < wordCount; i++)
    {
        free(wordArray[i]);
    }
    /* free Word Array */
    free(wordArray);
}
