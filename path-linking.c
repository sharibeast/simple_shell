#include "shell.h"

/**
 * append_node - adds a new node at the end of a list_t list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

path_list *append_node(path_list **head, char *str)
{

	path_list *mpya;
	path_list *tmp;

	mpya = malloc(sizeof(path_list));

	if (!str || !mpya)
	{
		return (NULL);
	}

	mpya->p = '\0';
	mpya->dir = str;

	if (!*head)
	{
		*head = mpya;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = mpya;
	}

	return (*head);
}



/**
 * _get_global_env_value - gets the value of the global variable
 * @name: global variable name
 * Return:string value
 */

char *_get_global_env_value(const char *name)
{
	int n, m;
	char *value;

	if (!name)
		return (NULL);
	for (n = 0; envronm[n]; n++)
	{
		m = 0;
		if (envronm[n][m] == name[m])
		{
			while (name[m])
			{
				if (name[m] != envronm[n][m])
				{
					break;
				}
				m++;
			}
			if (name[m] == '\0')
			{
				value = (envronm[n] + m + 1);
				return (value);
			}
		}
	}
	return (0);
}



/**
 * path_link - make linkedlist of path directories
 * @path: keep  path value
 * Return: pointer
 */
path_list *path_link(char *path)
{
	char *cpath = _strdup(path);
	path_list *head = '\0';
	char *tkn;

	tkn = strtok(cpath, ":");
	while (tkn)
	{
		head = append_node(&head, tkn);
		tkn = strtok(NULL, ":");
	}

	return (head);
}


