#include <stdio.h>

/**
 * compare_strings_function - This function compares two strings.
 *
 * @firstString: Pointer to the first string
 * @secondString: Pointer to the second string
 * Return: Always Integer
 */
int compare_strings_function(char *firstString, char *secondString)
{
	unsigned int i = 0;

	while (firstString[i])
	{
		if (firstString[i] != secondString[i])
		{
			return (0);
		}
		i++;
	}

	return (1);
}
