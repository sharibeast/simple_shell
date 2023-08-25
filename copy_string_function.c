#include <stdio.h>

/**
 * copy_string_function - copies string
 *
 * @destination: Destination String
 * @source: Source string
 * Return: Copied String
 */
char *copy_string_function(char *destination, char *source)
{
        char *dest = destination;

        while (*source)
        {
                *destination++ = *source++;
        }
        *destination = '\0';
        return (dest);
}
