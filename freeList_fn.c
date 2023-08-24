#include <stdio.h>
#include "shell.h"

/**
 * freeList_fn - Freeing list
 *@lead: Pointer to list
 */
void freeList_fn(list_path *lead)
{
	list_path *keep;

	while (lead)
	{
		keep = lead->p;
		free(lead->dir);
		free(lead);
		lead = keep;
	}

}
