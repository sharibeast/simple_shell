#include <stdio.h>
#include "shell.h"

/**
 * _strlen - Calculate the length of string
 * @s: Pointer to that string
 * Return: Always Integer
 */

int _strlen(char *s)
{
        int i = 0;

        while (*(s + i) != '\0')
        {
                i++;
        }
        return (i);
}
