#ifndef JOEL_SHELL
#define JOEL_SHELL

/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_strdup(char *s);
char *_strchr(char *s, int c);
char **getWordArray(char *string);

#endif
