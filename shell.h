#ifndef _SIMPLE_SHELL_H_
#define _SIMPLE_SHELL_H_

#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int compare_strings_function(char *firstString, char *secondString);
void child_execution(char **cmd, char *name, char **envp, int loops);
int main(int argc, char **argv, char **envp);
void free_memory_and_exit_fn(char **cmd);
char **custom_tokenizer(char *buffer, const char *delim);
int directory_changes_fn(const char *dir);
void free_memory_fn(char **cmd);

int length_of_string_function(char *givenString);
char *copy_string_function(char *destination, char *source);
char *concatenate_string_function(char *destination, char *source);
int string_to_integer_function(char *string);
void run(char **runCommand, char *name, char **envir, int cycles);
void handle_prompt(void);
void signal_handle(int signal);
void exit_handler(char **cmd);
void handle_end_of_file(char *buf);
void show_environment(char **environment);
char **directory_path_function(char **environment);
void error_handler(char *name, int cycleCounts, char **com);

#endif
