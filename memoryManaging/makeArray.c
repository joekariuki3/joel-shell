#include "shell.h"
void makeArray(char **enVars)
{
    char *string = NULL, *word = NULL, **wordArray = NULL, *validPath = NULL;
    int isExit = 0, wordCount = 0, i = 0 /* wordLength = 0, index */;
    size_t length = 0 /*, wordArraySize = 0*/;
    ssize_t read;

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
            perror("Memorry re allocation failed");
            exit(1);
        }
        /* Now lets append each word to the wordArray */
        wordArray[wordCount] = strdup(word);
        wordCount++;
        word = strtok(NULL, " ");
    }

    /* Look for executable */
    validPath = getPath(wordArray, enVars);
    if (validPath)
    {
        printf("%s\n", validPath);
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
