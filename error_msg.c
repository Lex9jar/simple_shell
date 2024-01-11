#include "shell.h"

/**
 * _enomem - Set errno to ENOMEM and prints and exits the a program
 * with exit value.
 * @f_name: Program's name.
 *
 * Return: void.
 */
void _enomem(char *f_name)
{
	errno = ENOMEM;
	perror(f_name);
	exit(EXIT_FAILURE);
}
