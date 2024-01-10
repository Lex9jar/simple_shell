#include "shell.h"

/**
 * execute_commands - Executes array of commands
 * @argv: Array of commands
 * @f_name: Program name
 *
 * Return: On success 0, otherwise -1 upon failure.
 */
int execute_commands(char **argv, char *f_name)
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
