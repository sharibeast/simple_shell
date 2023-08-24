#include "shell.h"





/**
 * main - Shell
 * Return: 0 on success
 */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, controlCheck);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arv = devideString_fn(buff, " \n");
		if (!arv || !arv[0])
			run(arv);
		else
		{
			value = fetchEnvironment("PATH");
			head = pathDirectory(value);
			pathname = _which(arv[0], head);
			f = verifyBuild_fn(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				run(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				run(arv);
			}
		}
	}
	freeList_fn(head);
	freearray_fn(arv);
	free(buff);
	return (0);
}
