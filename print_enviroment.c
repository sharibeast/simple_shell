#include <stdio.h>
#include "shell.h"

/**
 * print_env - Prints all environmental variables.
 *
 * @env: The environmental variables.
 * Return: Nothing
 */
void print_env(char **env)
{
	size_t num = 0, length = 0;

	while (env[num])
	{
		length = length_of_string_function(env[num]);
		write(STDOUT_FILENO, env[num], length);
		write(STDOUT_FILENO, "\n", 1);
		num++;
	}
}
