#include "shell.h"

/**
 * free_memory_fn - function to free all memory
 *
 * @cmd: Ptr to allocate mem
 * Return: Nothing.
 */
void free_memory_fn(char **cmd)
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
		free(cmd[num]);
	free(cmd);
}
