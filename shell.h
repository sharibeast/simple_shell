#ifndef HEADER_M
#define HEADER_M


#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **envronm;

/**
 * struct custom_build - ptr fn with command building
 * @n: command building
 * @f: execute the command build
 */
typedef struct custom_build
{
	char *n;
	void (*f)(char **);
} custom_build;


/**
 * struct path_list - Linked list with paths dir
 * @dir: directory
 * @p: pointer to  node
 */
typedef struct path_list
{
	char *dir;
	struct path_list *p;
} path_list;

path_list *append_node(path_list **head, char *str);
path_list *linkpath(char *path);

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concatenate(char *nm, char *sp, char *val);
int _atoi(char *p);
void print_env(char **arv __attribute__ ((unused)));

char *concatenate_all(char *nm, char *sp, char *val);
int _strlen(char *s);
int _putchar(char c);
void _puts(char *str);
void custom_exit(char **params);
void free_array_ptr(char **arv);
void empty_list_memory(path_list *head);
char *_get_global_env_value(const char *name);
char *_custom_which(char *filename, path_list *head);
void run(char **arg)

#endif