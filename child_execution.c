#include "shell.h"

/**
 * child_execution - create child process by executing function
 *
 * @cmd: pointer ags comands
 * @n:  the name of the shell pt.
 * @environment: variables for Environment.
 * @l: how many times loop executed
 * Return: Void.
 */
void child_execution(char **cmd, char *n, char **environment, int l)
{
	int process_id, stats;

	process_id = fork();
	if (process_id < 0)
	{
		perror("error message: Error fork");
		free_memory_and_exit_fn(cmd);
	}
	else if (process_id == 0)
	{
		execute_command(cmd, n, environment, l);
		free_memory_fn(cmd);
	}
	else
	{
		if (waitpid(process_id, &stats, 0) < 0)
		{
			perror("error message: process id wait failed");
			free_memory_and_exit_fn(cmd);
		}
	}

	free_memory_fn(cmd);
}
