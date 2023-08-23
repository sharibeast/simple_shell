#include <stdio.h>
/**
 * _puts - prints string
 * @string: pointer to the string
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
