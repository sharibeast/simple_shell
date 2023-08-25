#include <stdio.h>
#include "shell.h"

/**
 * show_environment - Shows env vars
 * @environment: Env Vars.
 * Return: Void
 */
void show_environment(char **environment)
{
	size_t count = 0;

	size_t len = 0;

	while (environment[count])
	{
		len = length_of_string_function(environment[count]);
		write(STDOUT_FILENO, environment[count], len);
		write(STDOUT_FILENO, "\n", 1);
		(count++);
	}
}
