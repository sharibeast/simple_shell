#include <stdio.h>
#include "shell.h"

/**
 * directory_path_function - Gets directory path
 * @environment: Environment vars.
 * Return: Directory.
 */
char **directory_path_function(char **environment)
{
	char *path = NULL;

	int i = 0;
        
        char **road = NULL;

	path = strtok(environment[i], "=");
	while (environment[i])
	{
		if (compare_strings_function(path, "PATH"))
		{
			path = strtok(NULL, "\n");
			road = custom_tokenizer(path, ":");
                        
			return (road);
		}
		i++;
		path = strtok(environment[i], "=");
	}
	return (NULL);
}
