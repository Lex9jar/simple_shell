#include "shell.h"

/**
 * s_printf - Simple print function
 * @str: String to print
 *
 * Return: void.
 */
void s_printf(char *str)
{
	write(STDIN_FILENO, str, _strlen(str));
}

/**
 * prompt - Prints a prompt on the terminal
 *
 * Return: void.
 */
void prompt(void)
{
	s_printf("#cisfun$ ");
}
