#include "shell.h"

/**
 * _dirsPATH - Gets the directories for the
 * PATH environmental variable.
 *
 * @env: The environmental variables.
 * Return: An array of directories.
 */
char **_dirsPATH(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int num = 0;

	pathvalue = strtok(env[num], "=");
	while (env[num])
	{
		if (compare_strings_function(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = custom_tokenizer(pathvalue, ":");
			return (pathways);
		}
		num++;
		pathvalue = strtok(env[num], "=");
	}
	return (NULL);
}


/**
 * command_error - Prints command not found error message.
 *
 * @shell_name: The name of the shell.
 * @loops: The number of executed cycles.
 * @command: The tokenized command.
 * Return: Nothing
 */
void command_error(char *shell_name, int loops, char **command)
{
	char result;

	result = loops + '0';
	write(STDOUT_FILENO, shell_name, length_of_string_function(shell_name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &result, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], length_of_string_function(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
