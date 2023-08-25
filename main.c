#include "shell.h"

/**
 * main - Launches the shell
 *
 * @nofArg: Number of Arguments
 * @inputArg: Input Arguments
 * @argVar: Environment Variables
 * Return: Always Integer.
 */
int main(int nofArg, char **inputArg, char **argVar)
{
	char *temporary = NULL, **cmd = NULL;

	size_t bfSz = 0;
	ssize_t checked = 0;

	int tries = 0;
	(void)nofArg;

	while (1)
	{
		tries++;
		handle_prompt();
		signal(SIGINT, signal_handle);
		checked = getline(&temporary, &bfSz, stdin);

		if (checked == EOF)
		{
			handle_end_of_file(temporary);
		}
		else if (*temporary == '\n')
		{
			free(temporary);
		}
		else
		{
			temporary[length_of_string_function(temporary) - 1] = '\0';
			cmd = custom_tokenizer(temporary, " \0");
			free(temporary);
			if (compare_strings_function(cmd[0], "exit") != 0)
				exit_handler(cmd);
			else if (compare_strings_function(cmd[0], "cd") != 0)
				directory_changes_fn(cmd[1]);
			else
				child_execution(cmd, inputArg[0], argVar, tries);
		}
		fflush(stdin);
		temporary = NULL, bfSz = 0;
	}

	if (checked == -1)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
