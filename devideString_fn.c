#include <stdio.h>
#include "shell.h"

/**
 * devideString_fn - Devides a string
 * @string: the string to be split
 * @dl: the dl
 * Return: character
 */

char **devideString_fn(char *string, const char *dl)
{
	char **theArray;
        int numberOfWords;
	char *cp;
	int i;
	char *tk;

	cp = malloc(_strlen(string) + 1);
	if (cp == NULL)
	{
		perror(fetchEnvironment("_"));
		return (NULL);
	}
	i = 0;
	while (string[i])
	{
		cp[i] = string[i];
		i++;
	}
	cp[i] = '\0';

	tk = strtok(cp, dl);
	theArray = malloc((sizeof(char *) * 2));
	theArray[0] = _strdup(tk);

	i = 1;
	numberOfWords = 3;
	while (tk)
	{
		tk = strtok(NULL, dl);
		theArray = _realloc(theArray, (sizeof(char *) * (numberOfWords - 1)), (sizeof(char *) * numberOfWords));
		theArray[i] = _strdup(tk);
		i++;
		numberOfWords++;
	}
	free(cp);
	return (theArray);
}