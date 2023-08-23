#include "shell.h"

/**
 * key_handler - checks if Ctrl C is pressed
 * @num: int
 */
void key_handler(int num)
{
	if (num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
* _endOfFile - HandleFileEnds
* @length_var: return val of getline function
* @bf: Temporary Variable
 */
void _endOfFile(int length_var, char *bf)
{
	(void)bf;
	if (length_var == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(bf);
		}
		exit(0);
	}
}

/**
  * _isTerminal - verif if terminal
  */

void _isTerminal(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
 * main - Shell
 * Return: 0 on success
 */

int main(void)
{
	size_t size_var = 0;
	void (*f)(char **);
	path_list *lead_var = '\0';
	ssize_t length_var = 0;
	char *buffer_var = NULL, *val, *pathName, **arg;

	signal(SIGINT, key_handler);
	while (length_var != EOF)
	{
		_isTerminal();
		length_var = getline(&buffer_var, &size_var, stdin);
		_endOfFile(length_var, buffer_var);
		arg = string_spliting(buffer_var, " \n");
		if (!arg[0] || !arg)
			run(arg);
		else
		{
			val = _get_global_env_value("PATH");
			lead_var = linkpath(val);
			pathName = _custom_which(arg[0], lead_var);
			f = verify_build(arg);
			if (f)
			{
				free(buffer_var);
				f(arg);
			}
			else if (!pathName)
				run(arg);
			else if (pathName)
			{
				free(arg[0]);
				arg[0] = pathName;
				run(arg);
			}
		}
	}
	empty_list_memory(lead_var);
	free_array_ptr(arg);
	free(buffer_var);
	return (0);
}