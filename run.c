#include <stdio.h>
#include "shell.h"

/**
 * run - Runs command
 * @arguments: arguments
 */

void run(char **arguments)
{

	int a;
	int check;

	if (!arguments || !arguments[0])
		return;
	a = fork();
	if (a == -1)
	{
		perror(fetchEnvironment("_"));
	}
	if (a == 0)
	{
		execve(arguments[0], arguments, environ);
		perror(arguments[0]);
		exit(EXIT_FAILURE);
	}
	wait(&check);
}
