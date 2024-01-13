#include "shell.h"

/**
 * _printenv - Prints the environment variables
 *
 * Return: void.
 */
void _printenv(void)
{
	int i;

	while (environ[i] != NULL)
	{
		s_printf(environ[i]);
		s_printf("\n");
		i++;
	}
}

/**
 * exit_shell - Exits the shell program
 * @argv: Array of commands
 * @argc: Size of array
 * @f_name: Program's name.
 * @_return: Terminating value
 *
 * Return: void.
 */
int exit_shell(char **argv, size_t argc, char *f_name, int *_return)
{
	int i = -1, flg = 0, val;

	if (argc > 1)
	{
		while (argv[1][++i])
			if (argv[1][i] < '0' || argv[1][i] > '9')
			{
				flg = 1;
				break;
			}

		if (flg == 0)
		{
			val = atoi(argv[1]);
			if (val < 0)
			{
				fprintf(stderr, "%s: 1: exit: Illegal number: %d\n", f_name, val);
				return (2);
			}
			else
				exit(atoi(argv[1]));
		}
		else
			fprintf(stderr, "%s: 1: exit: Illegal number: %s\n", f_name, argv[1]);
		return (2);
	}
	else
		exit(*_return);
}
