#include <stdio.h>
#include "shell.h"

/**
 * run - Running the commands
 * @runCommand: Tokenized runCommand.
 * @name: Shell name.
 * @envir: Environmental Vars.
 * @cycles: Cycle count
 * Return: Void
 */
void run(char **runCommand, char *name, char **envir, int cycles)
{
        int i = 0;
        char **road = NULL;
        struct stat a;
        char *path = NULL;

        if (compare_strings_function(runCommand[0], "envir") != 0)
        {
                show_environment(envir);
        }
        if (stat(runCommand[0], &a) == 0)
        {
                if (execve(runCommand[0], runCommand, envir) < 0)
                {
                        perror(name);
                        free_memory_and_exit_fn(runCommand);
                }
        }
        else
        {
                road = directory_path_function(envir);
                while (road[i])
                {
                        path = concatenate_string_function(road[i], runCommand[0]);
                        i++;
                        if (stat(path, &a) == 0)
                        {
                                if (execve(path, runCommand, envir) < 0)
                                {
                                        perror(name);
                                        free_memory_fn(road);
                                        free_memory_and_exit_fn(runCommand);
                                }
                                return;
                        }
                }
                error_handler(name, cycles, runCommand);
                free_memory_fn(road);
        }
}