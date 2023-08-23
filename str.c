#include "shell.h"

/**
 * _strptr - returns a pointer to a new space in array
 * @string: pointer to a string
 * Return: pointer to a string
 */
char *_strptr(char *string)
{
	char *newVar;
	int i, length;

	if (!string)
	{
		return (NULL);
	}
	for (length = 0; string[length] != '\0';)
	{
		length++;
	}
	newVar = malloc(sizeof(char) * length + 1);
	if (!newVar)
	{
		return (NULL);
	}
	for (i = 0; i < length; i++)
	{
		newVar[i] = string[i];
	}
	newVar[length] = string[length];
	return (newVar);
}

/**
 * concat - Concatenates Three Strings
 * @first: first string
 * @second: second string
 * @third: Third string
 * Return: pointer to the new string
 */
char *concat(char *first, char *second, char *third)
{
	char *res;
	int len1, len2, len3, i, j;

	len1 = _strlen(first);
	len2 = _strlen(second);
	len3 = _strlen(third);

	res = malloc(len1 + len2 + len3 + 1);
	if (!res)
		return (NULL);

	for (i = 0; first[i]; i++)
		res[i] = first[i];
	j = i;

	for (i = 0; second[i]; i++)
		res[j + i] = second[i];
	j = j + i;

	for (i = 0; third[i]; i++)
		res[j + i] = third[i];
	j = j + i;

	res[j] = '\0';

	return (res);
}
