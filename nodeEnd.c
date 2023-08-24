#include <stdio.h>
#include "shell.h"

/**
 * nodeEnd - appends node to the list
 * @lead: Points to the list
 * @string: String of former node
 * Return: address
 */

list_path *nodeEnd(list_path **lead, char *string)
{

	list_path *latest;
	list_path *buffer;

	latest = malloc(sizeof(list_path));

	if (!latest || !string)
	{
		return (NULL);
	}

	latest->dir = string;

	latest->p = '\0';
	if (!*lead)
	{
		*lead = latest;
	}
	else
	{
		buffer = *lead;

		while (buffer->p)
		{

			buffer = buffer->p;
		}

		buffer->p = latest;
	}

	return (*lead);
}
