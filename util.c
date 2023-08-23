#include "shell.h"
/**
 * env - prints  environment in system
 * @arv: arguments
 */
void print_env(char **arv __attribute__ ((unused)))
{
	int y;

	for (y = 0; envronm[y]; y++)
	{
		_puts(envronm[y]);
		_puts("\n");
	}

}
