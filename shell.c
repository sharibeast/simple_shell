#include "shell.h";

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
* @length: return val of getline function
* @bf: Temporary Variable
 */
void _endOfFile(int length, char *bf)
{
	(void)bf;
	if (length == -1)
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
	ssize_t length = 0;
	char *buffer = NULL, *val, *pathName, **arg;
	size_t size = 0;
	path_list *lead = '\0';
	void (*f)(char **);

	signal(SIGINT, key_handler);
	while (length != EOF)
	{
		_isatty();
		length = getline(&buffer, &size, stdin);
		_EOF(length, buffer);
		arg = splitstring(buffer, " \n");
		if (!arg[0] || !arg)
			execute(arg);
		else
		{
			val = _getenv("PATH");
			lead = linkpath(val);
			pathName = _which(arg[0], lead);
			f = checkbuild(arg);
			if (f)
			{
				free(buffer);
				f(arg);
			}
			else if (!pathName)
				execute(arg);
			else if (pathName)
			{
				free(arg[0]);
				arg[0] = pathName;
				execute(arg);
			}
		}
	}
	free_list(lead);
	freearv(arg);
	free(buffer);
	return (0);
}