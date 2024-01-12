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
	int _return = 0;

	(void)ac;

	while (INFINITE)
	{
		prompt();
		get_n = (getline(&lineptr, &n, stdin));
		if (get_n == EOF)
			_EOF(lineptr, _return);
		else if (_strcmp("exit\n", lineptr) == 0)
		{
			free(lineptr);
			break;
		}
		else if (_strcmp("env", lineptr) == 0)
			_printenv();
		else
		{
			s_printf("At execute\n");
			execute_commands(lineptr, av[0], &_return);
		}

		free(lineptr), n = 0, lineptr = NULL;
	}

	return (_return);
}

/**
 * _EOF - Chaecks if the buffer is EOF
 * @lineptr: The pointer to the input string.
 * @_return: Exit value.
 *
 * Return: void
 */
void _EOF(char *lineptr, int _return)
{
	if (lineptr)
		free(lineptr);
	if (isatty(STDIN_FILENO))
		s_printf("\n");
	exit(_return);
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
	s_printf(new_prompt);
}
