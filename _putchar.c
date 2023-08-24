#include "shell.h"
/**
 * _putchar - a function that print character c to standard output
 * @c: character to be printed
 *
 * Return: success 1
 * On error, -1 is returned,
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
