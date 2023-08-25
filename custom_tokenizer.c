#include "shell.h"

/**
 * custom_tokenizer - function that tokenize string to various commands
 * @buf: The string to tokenize.
 * @delimeter: The delimiter to use.
 * Return: An array of tokens.
 */

char **custom_tokenizer(char *buf, const char *delimeter)
{
	char *tkn = NULL, **cmd = NULL;
	size_t buf_size = 0;
	int num = 0;

	if (buf == NULL)
	{
		return (NULL);
	}
	buf_size = length_of_string_function(buf);
	cmd = malloc((buf_size + 1) * sizeof(char *));
	if (cmd == NULL)
	{
		perror("cant allocate buffer");
		free(buf);
		free_memory_fn(cmd);
		exit(EXIT_FAILURE);
	}

	tkn = strtok(buf, delimeter);
	while (tkn != NULL)
	{
		cmd[num] = malloc(length_of_string_function(tkn) + 1);
		if (cmd[num] == NULL)
		{
			perror("cant allocate buffer");
			free_memory_fn(cmd);
			return (NULL);
		}
		copy_string_function(cmd[num], tkn);
		tkn = strtok(NULL, delimeter);
		num++;
	}
	cmd[num] = NULL;
	return (cmd);
}
