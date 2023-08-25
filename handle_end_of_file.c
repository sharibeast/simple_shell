#include "shell.h"
/**
 * handle_eof - A handle_eof function that chaecks if buffer is EOF or not
 *
 * @buf: ptr input string
 * Return: void
 */
void handle_end_of_file(char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);

	exit(EXIT_SUCCESS);
}
