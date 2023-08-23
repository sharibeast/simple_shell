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


/**
 * _environmentSeting - Dealing with environment variables
 * @arg: array of words
 */
void _environmentSeting(char **arg)
{
	int i, j, k;

	if (!arg[1] || !arg[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (i = 0; envronm[i]; i++)
	{
		j = 0;
		if (arg[1][j] == envronm[i][j])
		{
			while (arg[1][j])
			{
				if (arg[1][j] != envronm[i][j])
					break;

				j++;
			}
			if (arg[1][j] == '\0')
			{
				k = 0;
				while (arg[2][k])
				{
					envronm[i][j + 1 + k] = arg[2][k];
					k++;
				}
				envronm[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!envronm[i])
	{

		envronm[i] = concatenate(arg[1], "=", arg[2]);
		envronm[i + 1] = '\0';

	}
}


/**
 * _environmentUnsetting - Remove an environment variable
 * @arg: array of entered words
 */
void _environmentUnsetting(char **arg)
{
	int i, j;

	if (!arg[1])
	{
		perror(_getenv("_"));
		return;
	}
	for (i = 0; envronm[i]; i++)
	{
		j = 0;
		if (arg[1][j] == envronm[i][j])
		{
			while (arg[1][j])
			{
				if (arg[1][j] != envronm[i][j])
					break;

				j++;
			}
			if (arg[1][j] == '\0')
			{
				free(envronm[i]);
				envronm[i] = envronm[i + 1];
				while (envronm[i])
				{
					envronm[i] = envronm[i + 1];
					i++;
				}
				return;
			}
		}
	}
}




/**
* verify_build - verify command building
* @arv: arguments
* Return: ptr fn
*/
void(*verify_build(char **arv))(char **arv)
{
	int i, j;
	custom_build T[] = {
		{"exit", custom_exit},
		{"env", print_env},
		{"setenv", _environmentSeting},
		{"unsetenv", _environmentUnsetting},
		{NULL, NULL}
	};

	for (i = 0; T[i].n; i++)
	{
		j = 0;
		if (T[i].n[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; j++)
			{
				if (T[i].n[j] != arv[0][j])
				{
					break;
				}
			}
			if (!arv[0][j])
			{
				return (T[i].f);
			}
		}
	}
	return (0);
}