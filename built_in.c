#include "shell.h"

/**
 * _printenv - Prints the environment variables
 *
 * Return: void.
 */
void _printenv(void)
{
	int i;

	while (environ[i] != NULL)
	{
		s_printf(environ[i]);
		s_printf("\n");
		i++;
	}
}
