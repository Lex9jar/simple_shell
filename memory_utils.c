#include "shell.h"

/**
 * _realloc - reallocates memory area for a string
 * @str: String to reallocate memory for.
 * @size: size to allocate
 *
 * Return: Pointer to allocated memory, otherwise NULL
 */
char *_realloc(char *str, size_t size)
{
	size_t len = _strlen(str);
	char *new_str;

	if (len == size)
		return (str);

	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);

	new_str = _strcpy(new_str, str);
	free(str);

	return (new_str);
}

/**
 * free_array - Frees an array of strings
 * @array: A 2 dimensional array
 * @size: size of the array
 *
 * Return: void.
 */
void free_array(char **array, size_t size)
{
	ssize_t i;

	if (array[size] == NULL)
		i = --size;
	else
		i = size;

	for ( ; i >= 0; i--)
		free(array[i]);
	free(array);
}

/**
 * free_env - Frees environ
 *
 * Return: void.
 */
void free_env(void)
{
	size_t i = 0;

	for (i = 0; environ[i]; i++)
		free(environ[i]);
	free(environ);
	environ = NULL;
}
