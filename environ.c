#include "shell.h"

/**
 * dup_env - Makes the duplicate of environ
 * @f_name: Program's name
 *
 * Return: Pointer to an array of environment variable
 */
char **dup_env(char *f_name)
{
	char **new_env;
	size_t i;

	for (i = 0; environ[i]; i++)
		;

	new_env = malloc(sizeof(char *) * (i + 1));
	if (new_env == NULL)
		_enomem(f_name);

	for (i = 0; environ[i]; i++)
	{
		new_env[i] = _strdup(environ[i]);
		if (new_env[i] == NULL)
		{
			free_array(new_env, i);
			_enomem(f_name);
		}
	}
	new_env[i] = NULL;

	return (new_env);
}

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
