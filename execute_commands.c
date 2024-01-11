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
	char *argv[2];
	size_t argc;
	char *tmp = _strdup(lineptr);

	argc = word_count(tmp, " \t\r\n");
	free(tmp);

	if (argc > 1)
	{
		fprintf(stderr, "%s: No such file or directory\n", f_name);
		return (-1);
	}
	else if (argc == 0)
		return (0);

	tmp = _strdup(lineptr);
	argv[0] = strtok(tmp, " \t\r\n");
	argv[1] = NULL;

	if (_execve(argv, f_name) != 0)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
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
