#include "shell.h"

/**
 * error_handler - Handles Errors
 *
 * @name: Shell Name
 * @cycleCounts: Number of Cycle counts
 * @com: commands.
 * Return: Void
 */
void error_handler(char *name, int cycleCounts, char **com)
{
	char res;

	res = cycleCounts + '0';

	write(STDOUT_FILENO, name, length_of_string_function(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &res, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, com[0], length_of_string_function(com[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
