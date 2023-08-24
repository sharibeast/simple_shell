#include <stdio.h>
#include "shell.h"

/**
 * _which - Retrieves the path of the file
 * @name: File name or command
 * @lead: head of list
 * Return: pathname
 */
char *_which(char *name, list_path *lead)
{
	char *str;
	struct stat statt;

	list_path *tmp = lead;

	while (tmp)
	{

		str = concatenate_all(tmp->dir, "/", name);
		if (stat(str, &statt) == 0)
		{
			return (str);
		}
		free(str);
		tmp = tmp->p;
	}

	return (NULL);
}
