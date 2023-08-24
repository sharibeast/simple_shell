#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>




void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **devideString_fn(char *string, const char *dl);
void *_realloc(void *p_old, unsigned int size_old, unsigned int size);


extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;


char *_which(char *filename, list_path *head);

/**
 * struct mybuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */


void(*checkbuild(char **arv))(char **arv);
void terminate(char **argument);
void setEnvironment_fn(char **arv);
void _unsetenv(char **arv);

void freearv(char **arv);
void freeList_fn(list_path *head);
int _strlen(char *s);









typedef struct custom_build
{
	char *n;
	void (*f)(char **);
} custom_build;
void terminate(char **argument);
int _atoi(char *pointer);
void environment_fn(char **arguments __attribute__ ((unused)));
void unsettingEnvironment_fn(char **argument);
void(*verifyBuild_fn(char **args))(char **args);
void run(char **arguments);
void freearray_fn(char **arp);
char *fetchEnvironment(const char *title);
list_path *nodeEnd(list_path **lead, char *string);
void _puts(char *str);
char *concatenate_all(char *name, char *sep, char *value);
list_path *pathDirectory(char *actualPath);
char *_which(char *name, list_path *lead);
int _putchar(char c);
char *_strdup(char *str);
void freeList_fn(list_path *lead);
void _EOF(int len, char *buff);
void _isatty(void);
void controlCheck(int num);


#endif
