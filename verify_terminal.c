#include "shell.h"

/**
  * _custom_isatty - verif  terminal
  */

void _custom_isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}
