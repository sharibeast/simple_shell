#include <stdio.h>
#include "shell.h"

/**
 * setEnvironment_fn - Initializing environment
 * @argument: Words that are entered
 */
void setEnvironment_fn(char **argument)
{
	int b, a, c;

	if (!argument[1] || !argument[2])
	{
		perror(fetchEnvironment("_"));
		return;
	}

	for (a = 0; environ[a]; a++)
	{
		b = 0;
		if (argument[1][b] == environ[a][b])
		{
			while (argument[1][b])
			{
				if (argument[1][b] != environ[a][b])
					break;
				b++;
			}
			if (argument[1][b] == '\0')
			{
				c = 0;
				while (argument[2][c])
				{
					environ[a][b + 1 + c] = argument[2][c];
					c++;
				}
				environ[a][b + 1 + c] = '\0';
				return;
			}
		}
	}
	if (!environ[a])
	{

		environ[a] = concatenate_all(argument[1], "=", argument[2]);
		environ[a + 1] = '\0';
	}
}
