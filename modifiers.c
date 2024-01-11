#include "shell.h"
#include <stdlib.h>

/**
 * concate - Concatenates a file to a path
 * @path: Path to add
 * @cmd: Name of the file
 * @full_path: Where to store the concatenated path
 * @f_name: Program's name
 *
 * Return: void.
 */
void concate(char *path, char *cmd, char **full_path, char *f_name)
{
	size_t len = _strlen(path) + 1 + _strlen(cmd) + 1;
	char *tmp;

	tmp = malloc(len);
	if (tmp == NULL)
		_enomem(f_name);

	_strcpy(tmp, path);
	_strcat(tmp, "/");
	_strcat(tmp, cmd);

	*full_path = tmp;
}

/**
 * add_path - searches and add appropriate path to a file
 * @cmd: File to search path for
 * @f_name: Program's name
 *
 * Return: On success 0, otherwise -1 upon failure.
 */
int add_path(char **cmd, char *f_name)
{
	char *path, *token, *env, *full_path = NULL, *tmp = *cmd;
	struct stat stat_ptr;

	env = _getenv("PATH=");
	path = _strdup(env);
	if (path == NULL)
		_enomem(f_name);

	token = strtok(path, ":");
	while (token)
	{
		concate(token, *cmd, &full_path, f_name);
		if (stat(full_path, &stat_ptr) == 0)
		{
			*cmd = malloc(_strlen(full_path) + 1);
			if (*cmd == NULL)
				_enomem(f_name);
			_strcpy(*cmd, full_path);
			free(full_path);
			free(path);
			free(tmp);
			return (0);
		}
		free(full_path);
		full_path = NULL;
		token = strtok(NULL, ":");
	}
	fprintf(stderr, "%s: 1: %s: not found\n", f_name, *cmd);
	free(path);
	exit(127);
}

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
			_enomem(f_name);
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(lineptr);

	return (argv);
}

/**
 * mod_lineptr - Generates an array of valid commands
 * @lineptr: String containing commands
 * @size: Size of array
 * @delim: Delimeter to tokenization
 * @f_name: Program name.
 *
 * Return: Pointer to an array of commands, or NULL is failed.
 */
char **mod_lineptr(char *lineptr, size_t size,
		const char *delim, char *f_name)
{
	struct stat stat_ptr;
	char **argv = generate_arg_vector(size, lineptr, delim, f_name);

	if (isatty(STDIN_FILENO) == 0)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", f_name, argv[0]);
		exit(127);
	}

	if (stat(argv[0], &stat_ptr) == 0)
		return (argv);

	if (add_path(&argv[0], f_name) == 0)
		return (argv);

	free_array(argv, size);

	return (NULL);
}
