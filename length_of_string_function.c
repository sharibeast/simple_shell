#include <stdio.h>

/**
 * length_of_string_function - A function that finds the length of the string
 *
 * @givenString: The given string
 * Return: Always integer
 */
int length_of_string_function(char *givenString)
{
	int i = 0;

	while (givenString[i])
	{
		i++;
	}

	return (i);
}
