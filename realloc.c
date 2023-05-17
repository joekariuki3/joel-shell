#include"shell.h"

/**
 * _realloc - resizes memory of a particular string arcodingly
 * @ptr: pointer to old memory
 * @newsize: size of the new memory to be created
 * Returns: poiter to new memory or NULL
 */
void *_realloc(void *ptr, size_t size)
{
	void *newptr;
	size_t i;
	char *src, *dest;
	
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	newptr = malloc(size);
	if (newptr == NULL)
	{
		return (NULL);
	}

	if (ptr != NULL)
	{
		src = (char *)ptr;
		dest = (char *)newptr;

		/* copy data from ptr to newptr */

		for (i = 0; i < size; i++)
		{
			dest[i] = src[i];
		}
		free(ptr);
	}
	return (newptr);
}
