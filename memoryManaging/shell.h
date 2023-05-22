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
void makeArray();
int myexit(char *word);
char *getPath(char **wordArray, char **enVars);
void excec();

unsigned long int _strlen(char *s);
void *_realloc(void *ptr, size_t oldSize, size_t size);

#endif
