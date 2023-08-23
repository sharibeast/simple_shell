#ifndef HEADER_M
#define HEADER_M


#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concatenate(char *nm, char *sp, char *val);
int _atoi(char *p);
void print_env(char **arv __attribute__ ((unused)));
char *concatenate_all(char *nm, char *sp, char *val);
void custom_exit(char **params);


#endif