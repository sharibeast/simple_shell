#include "shell.h"

/**
  * _isatty - verif if terminal
  */

void _custom_isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}
