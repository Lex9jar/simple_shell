#include "shell.h"

/**
 * execute_commands - Executes array of commands
 * @lineptr: command to be executed
 * @f_name: Program name
 *
 * Return: On success 0, otherwise -1 upon failure.
 */
int execute_commands(char *lineptr, char *f_name)
{
	const char *delim = " \t\r\n";
	size_t argc = word_count(lineptr, delim);
	char **argv;

	if (argc == 0)
		return (0);

	argv = mod_lineptr(lineptr, argc, delim, f_name);
	if (argv == NULL)
		return (0);

	/*
	if (isatty(STDIN_FILENO) == 0)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", f_name, argv[0]);
		exit(127);
	}
	*/
	_execve(argv, f_name);

	free_array(argv, argc);

	return (0);
}

/**
 * _execve - Executes an array of commands
 * @argv: Array of commands to execute
 * @f_name: Program's name
 *
 * Return: 0 upon Success, otherwise -1 upon failure.
 */
int _execve(char **argv, char *f_name)
{
	int status;
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Fork error");
		return (-1);
	}

	if (child == 0)
	{
		execve(argv[0], argv, environ);
		perror(f_name);
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);

	return (0);
}
