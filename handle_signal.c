#include "shell.h"
/**
 * handle_signal - A signal handler function to handle cancel signal.
 *
 * @param_signal: handled signal
 * Return: void.
 */
void signal_handle(int param_signal)
{
	if (param_signal == SIGINT)
	{
		const char *text_signal = "\nalx_shell[$] ";

		write(STDOUT_FILENO, text_signal, 14);
	}
}