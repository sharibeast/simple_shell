#include "shell.h"
/**
 * _puts - prints a string
 * @str: pointer to string
 */
void _puts(char *str)
{
	int n = 0;

	while (str[n])
	{
		_putchar(str[n]);
		n++;
	}
}
