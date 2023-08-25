#include "shell.h"
/**
 * exit_handler - a handle exit fn
 *
 * @cmd: Tokenized pointer command.
 * Return: Nothing.
 */

void exit_handler(char **cmd)
{
	int status = 0;

	if (cmd[1] != NULL)
		status = string_to_integer_function(cmd[1]);

	free_memory_fn(cmd);
	exit(status);
}
