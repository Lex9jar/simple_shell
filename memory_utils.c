#include "shell.h"

/**
 * free_array - Frees a 2 dimensional array
 * @array: An array to free
 * @size: Size of array
 *
 * Return: void.
 */
void free_array(char **array, size_t size)
{
	ssize_t i = size;

	for (; i >= 0; i--)
		free(array[i]);
	free(array);
}
