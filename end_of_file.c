#include "shell.h"
/**
* end_of_file - handles the End of File
* @len: return value of getline function
* @buff: buffer
 */
void end_of_file(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
