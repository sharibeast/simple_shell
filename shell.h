#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*### Main program Shell file ###*/
int main(int argc, char **argv, char **envp);

/*### functions to Initialize shell ###*/
void prompt_handler(void);
void handle_signal(int signals);
void handle_eof(char *buffer);
void handle_exit(char **input_command);


/*### functions to child process Creation ###*/
void execute_child(char **command, char *shell_name, char **envp, int loops);


/*### functions to execute command ###*/
void execute_command(char **command, char *name, char **env, int cicles);
void print_env(char **env);
char **_dirsPATH(char **env);
void command_error(char *name, int loops, char **command);


/*### functions to tokenize input ###*/
char **tokenize(char *buffer, const char *delim);


/*### functions to free memory ###*/
void free_memory(char **command);



/*### Almas & Sharif*/
int compare_strings_function(char *firstString, char *secondString);
void child_execution(char **cmd, char *name, char **envp, int loops);
void free_memory_and_exit_fn(char **cmd);
int directory_changes_fn(const char *dir);
void free_memory_fn(char **cmd);

int length_of_string_function(char *givenString);
char *copy_string_function(char *destination, char *source);
char *concatenate_string_function(char *destination, char *source);
int string_to_integer_function(char *string);


#endif /*### _SHELL_H_ ###*/
