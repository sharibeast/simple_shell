#include "shell.h"
/**
 * free_memory_and_exit_fn - A function frees all the memory
 *
 * @cmd: . ptr to free memory cmd
 * Return: void.
 */


void free_memory_and_exit_fn(char **cmd)
{
	size_t num = 0;

	if (cmd == NULL)
	{
		return;
	}

	while (cmd[num])
	{
		free(cmd[num]);
		num++;
	}

	if (cmd[num] == NULL)
	{
		free(cmd[num]);
	}
	free(cmd);
	exit(EXIT_FAILURE);
}
