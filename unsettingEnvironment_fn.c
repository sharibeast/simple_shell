#include <stdio.h>
#include "shell.h"


/**
 * unsettingEnvironment_fn - Remove an environment variable
 * @argument: array of entered words
 */
void unsettingEnvironment_fn(char **argument)
{
	int i, j;

	if (!argument[1])
	{
		perror(fetchEnvironment("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (argument[1][j] == environ[i][j])
		{
			while (argument[1][j])
			{
				if (argument[1][j] != environ[i][j])
					break;

				j++;
			}
			if (argument[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
