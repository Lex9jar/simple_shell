#include "shell.h"

/**
 * main - A simple shell program.
 * @ac: Number of arguments passed to program.
 * @av: Array of string passed to the program.
 *
 * Return: On success 0, or an error value on failure.
 */
int main(int ac, char *av[])
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t get_n = 0;

	(void)ac;

	while (INFINITE)
	{
		prompt();
		get_n = (getline(&lineptr, &n, stdin));
		if (get_n == EOF)
		{
			free(lineptr);
			return(_return);
		}
		else
			execute_commands(lineptr, av[0]);

		free(lineptr), n = 0, lineptr = NULL;
	}

	return (_return);
}

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

/**
 * _EOF - Chaecks if the buffer is EOF
 * @lineptr: The pointer to the input string.
 *
 * Return: void
 */
void _EOF(char *lineptr)
{
	if (lineptr)
		free(lineptr);
	if (isatty(STDIN_FILENO))
		shell_printf("\n");
	exit(EXIT_SUCCESS);
}

/**
 * ctrl_c - Handles Ctrl+C signal
 * @sig: The signal to handle
 *
 * Return: void.
 */
void ctrl_c(int sig)
{
	char *new_prompt = "\n#xcsh-$ ";

	(void)sig;
	shell_printf(new_prompt);
}
