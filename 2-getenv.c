#include "shell.h"

/**
 * _getenv - Get an environment variable
 * @name: Environment variable name to get.
 *
 * Return: Pointer to the variable if found, otherwise NULL.
 */
char *_getenv(char *name)
{
	int i = 0;
	char *env;

	if (name == NULL)
		return (NULL);

	while (environ[i])
	{
		if (strncmp(name, environ[i], _strlen(name)) == 0)
		{
			env = environ[i];
			env += _strlen(name);
			return (env);
		}
		i++;
	}

	return (NULL);
}
