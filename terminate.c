#include <stdio.h>
#include "shell.h"


/**
 * terminate - Terminates Shell
 * @arv: array of words of the entered line
 */
void terminate(char **argument)
{
	int i, number;

	if (argument[1])
	{
		number = _atoi(argument[1]);
		if (number <= -1)
			number = 2;
		freearray_fn(argument);
		exit(number);
	}
	for (i = 0; argument[i]; i++)
		free(argument[i]);
	free(argument);
	exit(0);
}