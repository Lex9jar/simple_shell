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
	char *f_name = av[0];

	while (INFINITE)
	{
		prompt();
		if (getline(&lineptr, &n, stdin) <= 0)
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
		execute_commands(argv, f_name);

		free(lineptr);
		free(argv[0]);
		n = 0;
		lineptr = NULL;
	}

	return (0);
}
