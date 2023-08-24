#include "shell.h"

/**
 * _strdup - return ptr of new allocated mem
 *
 * @str: string ptr
 * Return: pointer
 */
char *_strdup(char *str)
{
	char *nw;
	int j;
	int x;

	if (!str)
	{
		return (NULL);
	}
	for (x = 0; str[x] != '\0';)
	{
		x++;
	}
	nw = malloc(sizeof(char) * x + 1);
	if (!nw)
	{
		return (NULL);
	}
	for (j = 0; j < x; j++)
	{
		nw[j] = str[j];
	}
	nw[x] = str[x];
	return (nw);
}






