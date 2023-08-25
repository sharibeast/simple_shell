#include "shell.h"

/**
  * directory_changes_fn - function to change current working directory in shell
  *
  * @dir: curr working dir (new)
  * Return: 0 when success, -1 if failed.
  */


int directory_changes_fn(const char *dir)
{
	size_t buf_size = 1024;
	char *buf = NULL;

	if (dir == NULL)
	{
		buf = (char *)malloc(sizeof(char) * buf_size);
		dir = getcwd(buf, buf_size);
	}
	if (chdir(dir) == -1)
	{
		perror(dir);
		free(buf);
		return (98);
	}

	free(buf);
	return (1);
}
