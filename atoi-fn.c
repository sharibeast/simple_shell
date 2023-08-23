#include <stdio.h>
/**
 * _atoi - return integer fro string
 *@p: pointer to a string
 *Return: the integer
 */
int _atoi(char *p)
{
	int index, integer, sign = 1;

	index = 0;
	integer = 0;
	while (!((p[index] >= '0') && (p[index] <= '9')) && (p[index] != '\0'))
	{
		if (p[index] == '-')
		{
			sign = sign * (-1);
		}
		index++;
	}
	while ((p[index] >= '0') && (p[index] <= '9'))
	{
		integer = (integer * 10) + (sign * (p[index] - '0'));
		index++;
	}
	return (integer);
}
