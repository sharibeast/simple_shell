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
void child_execution(char **cmd, char *name, char **envp, int loops)
{
	int process_id, stats;

	process_id = fork();
	if (process_id < 0)
	{
		perror("error message: Error fork");
		freeMem_and_exit(cmd);
	}
	else if (process_id == 0)
	{
		execute_command(cmd, name, envp, loops);
		free_memory(cmd);
	}
	else
	{
		if (waitpid(process_id, &stats, 0) < 0)
		{
			perror("error message: process id wait failed");
			freeMem_and_exit(cmd);
		}
	}

	free_memory(cmd);
}
