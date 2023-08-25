#include <stdio.h>

/**
 * concatenate_string_function - This function concatenates two strings.
 * @destination: Destination String
 * @source: Source String
 * Return: Output function
 */
char *concatenate_string_function(char *destination, char *source)
{
	char *dest = destination;

	while (*destination)
	{
		destination++;
	}

	*destination++ = '/';
	while (*source)
	{
		*destination++ = *source++;
	}
	return (dest);
}
