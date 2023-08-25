#include <stdio.h>

/**
 * string_to_integer_function - This function converts a string to an integer.
 * @string: The input string.
 * Return: An integer from the conversion.
 */

int string_to_integer_function(char *string)
{
	char flag = 0;
	int signal = 1, sum = 0;

	if (string == NULL)
	{
		return (0);
	}
	while (*string)
	{
		if (*string == '-')
		{
			signal *= -1;
		}
		if (*string >= '0' && *string <= '9')
		{
			flag = 1;
			sum = sum * 10 + (*string - '0');
		}
		else if (*string < '0' || *string > '9')
		{
			if (flag == 1)
				break;
		}
		string++;
	}
	if (signal < 0)
	{
		sum = (-1 * (sum));
	}

	return (sum);
}
