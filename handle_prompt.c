#include "shell.h"

/**
 * handle_prompt - handle function that console the prompt
 *
 * Return: void.
 */
void handle_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		const char *text_prompt = "#cisfun$ ";

		write(STDOUT_FILENO, text_prompt, 10);
	}
}