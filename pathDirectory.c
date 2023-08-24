#include <stdio.h>
#include "shell.h"

/**
 * pathDirectory - generates path to the directory
 * @actualPath: string of path value
 * Return: pointer
 */
list_path *pathDirectory(char *actualPath)
{
        char *tk;
        list_path *lead = '\0';
        char *path = _strdup(actualPath);

        tk = strtok(path, ":");
        while (tk)
        {
                lead = nodeEnd(&lead, tk);
                tk = strtok(NULL, ":");
        }

        return (lead);
}