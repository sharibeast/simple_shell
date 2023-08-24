#include "shell.h"





/**
 * main - Shell
 * Return: 0 on success
 */

int main(void)
{
	size_t sz_var = 0;
	list_path *var_head = '\0';
	ssize_t var_len = 0;
	char *val, *path_name, **arv_var , *buff_var = NULL;
	void (*f)(char **);

	signal(SIGINT, controlCheck);
	while (var_len != EOF)
	{
		_custom_isatty();
		var_len = getline(&buff_var, &sz_var, stdin);
		end_of_file(var_len, buff_var);
		arv_var = devideString_fn(buff_var, " \n");
		if (!arv_var || !arv_var[0])
			run(arv_var);
		else
		{
			val = fetchEnvironment("PATH");
			var_head = pathDirectory(val);
			path_name = _which(arv_var[0], var_head);
			f = verifyBuild_fn(arv_var);
			if (f)
			{
				free(buff_var);
				f(arv_var);
			}
			else if (!path_name)
				run(arv_var);
			else if (path_name)
			{
				free(arv_var[0]);
				arv_var[0] = path_name;
				run(arv_var);
			}
		}
	}
	freeList_fn(var_head);
	freearray_fn(arv_var);
	free(buff_var);
	return (0);
}
