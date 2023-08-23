#include "shell.h"

/**
 * custom_exit - function to exist shell
 * @params: array of words
 */
void custom_exit(char **params)
{
	int p;
	int i;

	if (params[1])
	{
		p = _atoi(params[1]);
		if (p <= -1)
			p = 2;
		free_array_ptr(params);
		exit(p);
	}
	for (i = 0; params[i]; i++)
		free(params[i]);
	free(params);
	exit(0);
}
