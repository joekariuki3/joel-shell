#include "shell.h"

/**
 * _realloc - resizes memory of a particular string accordingly
 * @ptr: pointer to old memory
 * @newSize: newsize of the new memory to be created
 * @oldSize: oldSize of ptr
 * Returns: pointer to new memory or NULL
 */
void *_realloc(void *ptr, size_t oldSize, size_t newSize)
{
    void *newPtr;
    size_t i;
    char *src, *dest;

    /*check if new size is 0 free the incoming ptr*/
    if (newSize == 0)
    {
        free(ptr);
        return (NULL);
    }

    /*create newPtr memory*/
    newPtr = malloc(newSize);
    if (newPtr == NULL)
    {
        return (NULL);
    }

    /*if ptr had data in it create placeholders to transfer data to new memory(newPtr)*/
    if (ptr != NULL)
    {
        src = (char *)ptr;
        dest = (char *)newPtr;

        /* copy data from ptr to newPtr */

        for (i = 0; i < newSize && i < oldSize; i++)
        {
            dest[i] = src[i];
        }
        /* free ptr after moving data to dest*/
        free(ptr);
    }
    return (newPtr);
}
