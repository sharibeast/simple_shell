#include <stdio.h>
#include "shell.h"

/**
 * controlCheck - checks if Ctrl C is pressed
 * @num: number
 */
void controlCheck(int num)
{
	if (num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}
