#include "shell.h"

/**
 * _strcat - This function concatenates two strings.
 *
 * @dest: The output string
 * @src: The input string
 * Return: A pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *mix = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (mix);
}


/**
 * _strint - This function converts a string to an integer.
 *
 * @str: The input string.
 * Return: An integer from the conversion.
 */
int _strint(char *str)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		if (*str >= '0' && *str <= '9')
		{
			null_flag = 1;
			total = total * 10 + (*str - '0');
		}
		else if (*str < '0' || *str > '9')
		{
			if (null_flag == 1)
				break;
		}
		str++;
	}
	if (sign < 0)
		total = (-1 * (total));
	return (total);
}
