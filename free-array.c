#include "shell.h"
/**
 * free_array_ptr - frees the array of pointers arv
 *@arv:  pointer arrays
 */
void free_array_ptr(char **arv)
{
	int n;

	for (n = 0; arv[n]; n++)
	{
		free(arv[n]);
	}
	free(arv);
}
