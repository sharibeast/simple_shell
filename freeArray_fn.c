#include <stdio.h>
#include "shell.h"

/**
 * freearray_fn - free array
 *@arp: pointers
 */

void freearray_fn(char **arp)
{
	int i;

	for (i = 0; arp[i]; i++)
		free(arp[i]);
	free(arp);
}