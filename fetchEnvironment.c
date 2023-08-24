#include <stdio.h>
#include "shell.h"

/**
 * fetchEnvironment - Fetching global variables
 * @title: The global variable
 * Return: pointer
 */
char *fetchEnvironment(const char *title)
{
	char *k;
	int a;
	int b;

	if (!title)
		return (NULL);
	for (a = 0; environ[a]; a++)
	{
		b = 0;
		if (title[b] == environ[a][b])
		{
			while (title[b])
			{
				if (title[b] != environ[a][b])
					break;

				b++;
			}
			if (title[b] == '\0')
			{
				k = (environ[a] + b + 1);
				return (k);
			}
		}
	}
	return (0);
}
