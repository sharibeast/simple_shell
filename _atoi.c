#include <stdio.h>
#include "shell.h"

/**
 * _atoi - Creates an integer from a string
 *@pointer: Points to string
 *Return: the integer
 */
int _atoi(char *pointer)
{
        int signal = 1;
	int i;
        int number;

	i = 0;
	number = 0;
	while (!((pointer[i] >= '0') && (pointer[i] <= '9')) && (pointer[i] != '\0'))
	{
		if (pointer[i] == '-')
		{
			signal = signal * (-1);
		}
		i++;
	}
	while ((pointer[i] >= '0') && (pointer[i] <= '9'))
	{
		number = (number * 10) + (signal * (pointer[i] - '0'));
		i++;
	}
	return (number);
}