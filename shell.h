#ifndef JOEL_SHELL
#define JOEL_SHELL

/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* remove later after adding string funtions */
#include <unistd.h>
#include <sys/wait.h>
#include <unistd.h>

/* Prototypes*/
char **makeArray(char *string, char *deli);
char *getpath(char **envp, char **wordArray);
void excec();


unsigned long int _strlen(char *s);
void *_realloc(void *ptr, size_t newsize);

#endif
