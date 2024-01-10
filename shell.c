#include "shell.h"

/**
 * main - A simple shell program.
 * @ac: Number of arguments passed to program.
 * @av: Array of string passed to the program.
 *
 * Return: On success 0, or an error value on failure.
 */
int main(__attribute__((unused))int ac, char *av[])
{
	char *lineptr = NULL;
	size_t n = 0;
	char *argv[2];
	ssize_t get_n = 0;
	char *trimmed;

	while (INFINITE)
	{
		prompt();
		get_n = (getline(&lineptr, &n, stdin));
		if (get_n == EOF)
			_EOF(lineptr);
		else
		{
			trimmed = trim(lineptr);
			if (trimmed == NULL)
			{
				free(trimmed), free(lineptr),
					n = 0, lineptr = NULL;
				continue;
			}
			argv[0] = trimmed;
			argv[1] = NULL;
			execute_commands(argv, av[0]);
			free(lineptr), free(trimmed), n = 0, lineptr = NULL;
		}

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
