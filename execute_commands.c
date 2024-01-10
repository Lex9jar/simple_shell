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
	int status, exit_status = 1;
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Fork error");
		return (-1);
	}

	if (child == 0)
	{
		execve(argv[0], argv, NULL);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (_WIFEXITED(status))
			exit_status = _WEXITSTATUS(status);
		if (exit_status != 0)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
					f_name, exit_status, argv[0]);
			return (-1);
		}
	}

	return (0);
}
