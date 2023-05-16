#include "shell.h"
char **makeArray(char *string, char *deli)
{
    char *word = NULL, **wordArray;
    int wordLength = 0, wordArraySize = 0, index;

    /* split the string to individual words using strtok */
    word = strtok(string, deli);

    /* allocate memory to wordArray */
    wordArray = (char **)malloc(sizeof(char *));
    if (wordArray == NULL)
        exit(98);

    /* loop through the string getting each word*/
    while (word != NULL)
    {
        /* increase wordArraySize */
        wordArraySize++;

        /* resize the array n add current word*/
        wordArray = (char **)realloc(wordArray,
                                     wordArraySize * sizeof(char *));
        if (wordArray == NULL)
            exit(98);

        /* append word to wordArray */
        /* assign memory word to be stored in wordArray[index] */
        wordLength = strlen(word) + 1;
        index = wordArraySize - 1;
        wordArray[index] = (char *)malloc(wordLength * sizeof(char));
        if (wordArray[index] == NULL)
            exit(98);

        /* now append the word by coping it to wordArray[index] */
        strcpy(wordArray[index], word);

        /* extraxt the next argument(word)*/
        word = strtok(NULL, " ");
    }
    /* Free the input buffer allocated by getline */

    /*Return word Array*/
    return (wordArray);
}