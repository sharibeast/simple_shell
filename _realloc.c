#include <stdio.h>
#include "shell.h"

/**
 * _realloc - Realocating memory block
 * @p_old: Former pointer
 * @size_old: Former pointer size
 * @size: Pointer size
 * Return: Pointer
 */

void *_realloc(void *p_old, unsigned int size_old, unsigned int size)
{
	char *latest;
	char *former;

	unsigned int i;

	if (p_old == NULL)
		return (malloc(size));

	if (size == size_old)
		return (p_old);

	if (size == 0 && p_old != NULL)
	{
		free(p_old);
		return (NULL);
	}

	latest = malloc(size);
	former = p_old;
	if (latest == NULL)
		return (NULL);

	if (size > size_old)
	{
		for (i = 0; i < size_old; i++)
			latest[i] = former[i];
		free(p_old);
		for (i = size_old; i < size; i++)
			latest[i] = '\0';
	}
	if (size < size_old)
	{
		for (i = 0; i < size; i++)
			latest[i] = former[i];
		free(p_old);
	}
	return (latest);
}