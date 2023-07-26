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

/* makeArray.c */
void makeArray(char **env);
char **getWordArray(char *string, char **enVars);

/* getPath.c */
char *getPath(char **wordArray, char **enVars);
char *extractPATH(char **enVars);

/* realloc.c */
void *_realloc(void *ptr, size_t oldSize, size_t size);

/* string.c */
unsigned long int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);

/* moreString.c */
char *_strdup(char *s);
char *_strchr(char *s, int c);

/* exit.c */
int myexit(char *word);

/* env.c */
int myenv(char *word, char **envVars);

#endif
