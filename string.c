#include "shell.h"

/**
 * shell_printf - Simple print function
 * @str: String to print
 *
 * Return: void.
 */
void shell_printf(char *str)
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
	shell_printf("#cisfun$ ");
}
