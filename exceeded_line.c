#include "shell.h"

/**
 * string_spliting - A function to split string
 * @line: the sentence
 * @dlm: the dlm
 * Return: array of pointers to words
 */
char **string_spliting(char *line, const char *dlm)
{
	int i, j;
	char **arr;
	char *assurer;
	char *cpy;

	cpy = malloc(_strlen(line) + 1);
	if (cpy == NULL)
	{
		perror(_get_global_env_value("_"));
		return (NULL);
	}
	i = 0;
	while (line[i])
	{
		cpy[i] = line[i];
		i++;
	}
	cpy[i] = '\0';

	assurer = strtok(cpy, dlm);
	arr = malloc((sizeof(char *) * 2));
	arr[0] = _strdup(assurer);

	i = 1;
	j = 3;
	while (assurer)
	{
		assurer = strtok(NULL, dlm);
		arr = _reallocate(arr, (sizeof(char *) * (j - 1)), (sizeof(char *) * j));
		arr[i] = _strdup(assurer);
		i++;
		j++;
	}
	free(cpy);
	return (arr);
}

/**
 * run - Run the command
 * @arg: array of arguments
 */

void run(char **arg)
{

	int i, st;

	if (!arg || !arg[0])
		return;
	i = fork();
	if (i == -1)
	{
		perror(_get_global_env_value("_"));
	}
	if (i == 0)
	{
		execve(arg[0], arg, envronm);
			perror(arg[0]);
		exit(EXIT_FAILURE);
	}
	wait(&st);
}

/**
 * _reallocate - Reallocation of memory block
 * @pointer: Old pointer
 * @prev_size: previous pointer's size
 * @latest_size: Latest pointer's size
 * Return: New Pointer
 */

void *_reallocate(void *pointer, unsigned int prev_size, unsigned int latest_size)
{
	char *nw;
	char *old;

	unsigned int i;

	if (pointer == NULL)
		return (malloc(latest_size));

	if (latest_size == prev_size)
		return (pointer);

	if (latest_size == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}

	nw = malloc(latest_size);
	old = pointer;
	if (nw == NULL)
		return (NULL);

	if (latest_size > prev_size)
	{
		for (i = 0; i < prev_size; i++)
			nw[i] = old[i];
		free(pointer);
		for (i = prev_size; i < latest_size; i++)
			nw[i] = '\0';
	}
	if (latest_size < prev_size)
	{
		for (i = 0; i < latest_size; i++)
			nw[i] = old[i];
		free(pointer);
	}
	return (nw);
}