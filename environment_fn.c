#include <stdio.h>
#include "shell.h"



/**
 * environment_fn - prints the current environment
 * @arguments: array of arguments
 */
void environment_fn(char **arguments __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}

}