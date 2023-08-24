#include "shell.h"

/**
* verifyBuild_fn - Verify the building process
* @args: arguments
* Return: Always null
*/
void(*verifyBuild_fn(char **args))(char **args)
{
	int a;
	int b;
	mybuild T[] = {
		{"exit", terminate},
		{"env", environment_fn},
		{"setenv", setEnvironment_fn},
		{"unsetenv", unsettingEnvironment_fn},
		{NULL, NULL}
	};

	for (a = 0; T[a].name; a++)
	{
		b = 0;
		if (T[a].name[b] == args[0][b])
		{
			for (b = 0; args[0][b]; b++)
			{
				if (T[a].name[b] != args[0][b])
					break;
			}
			if (!args[0][b])
				return (T[a].func);
		}
	}
	return (0);
}
