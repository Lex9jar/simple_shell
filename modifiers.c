#include "shell.h"

/**
 * generate_arg_vector - Allocates an array of arguments in cmd_line
 * @argc: Size of array vector to generate
 * @cmd_line: Command line arguments
 * @delim: Delimiter for tokenization
 * @f_name: Program's name
 *
 * Return: Pointer to a 2 dimensional array of arguments.
 */
char **generate_arg_vector(size_t argc, char *cmd_line,
		const char *delim, char *f_name)
{
	char **argv;
	size_t i = 0;
	char *token;
	char *lineptr;

	lineptr = _strdup(cmd_line);
	if (lineptr == NULL)
		_enomem(f_name);

	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
	{
		free(lineptr);
		_enomem(f_name);
	}

	token = strtok(lineptr, delim);
	while (token)
	{
		argv[i] = _strdup(token);
		if (argv[i] == NULL)
		{
			free(lineptr);
			free_array(argv, i);
			_enomem(f_name);
		}
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(lineptr);

	return (argv);
}
