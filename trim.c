#include "shell.h"
#include <string.h>

/**
 * trim - Return a string that starts and end from a non space character
 * @str: string to compute
 *
 * Return: Pointer to trimed string.
 */
char *trim(char *str)
{
	size_t length, trim_len, start, end;
	char *trimmed;

	if (str == NULL)
		return (NULL);

	length = _strlen(str);
	while (start < length && (str[start] == ' ' ||
				str[start] == '\t' || str[start] == '\n'
				|| str[start] == '\r'))
		start++;

	end = length;
	while (end > start && (str[end - 1] == ' ' ||
				str[end - 1] == '\t' || str[end - 1] == '\n'
				|| str[end - 1] == '\r'))
		end--;

	trim_len = end - start;
	if (trim_len == 0)
		return (NULL);

	trimmed = malloc(trim_len + 1);
	if (trimmed == NULL)
		return (NULL);

	strncpy(trimmed, str + start, trim_len);

	return (trimmed);
}
