#ifndef HEADER_M
#define HEADER_M


#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concatenate(char *nm, char *sp, char *val);
int _atoi(char *p);


#endif