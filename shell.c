#include "shell.h"

/**
 * main - A simple shell program.
 * @ac: Number of arguments passed to program
 * @av: Array of string passed to the program
 *
 * Return: On success 0, or an error value on failure.
 */
int main(__attribute__((unused))int ac, char *av[])
{
	char *lineptr = NULL;
	size_t n = 0;
	char *argv[2];
	ssize_t get_n = 0;

	while (INFINITE)
	{
		prompt();
		get_n = (getline(&lineptr, &n, stdin));
		if (get_n == EOF)
			_EOF(lineptr);
		else if (get_n == -1)
		{
			free(lineptr);
			return (0);
		}

		argv[0] = _strdup(lineptr);
		if (argv[0] == NULL)
			return (-1);
		argv[1] = NULL;
		argv[0][(_strlen(argv[0])) - 1] = '\0';

		if (_strcmp(argv[0], "\0") == 0)
			continue;
		execute_commands(argv, av[0]);

		free(lineptr);
		free(argv[0]);
		n = 0;
		lineptr = NULL;
		fflush(stdin);
	}

	return (0);
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
	shell_printf("#xcsh-$ ");
}

/**
 * _EOF - Chaecks if the buffer is EOF
 * @buffer: The pointer to the input string.
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
