#include "shell.h"

/**
 * _strspn - Get length of a prefix substring
 * @s: String to evaluate
 * @accept: Set of characters for comparism
 *
 * Return: The numbers of bytes in the initial segment of s
 * which consists of bytes from accept.
 */
size_t _strspn(char *s, const char *accept)
{
	size_t i, j, flg, found;

	found = 0;
	for (i = 0; s[i]; i++)
	{
		flg = 0;
		for (j = 0; accept[j]; j++)
			if (s[i] == accept[j])
			{
				found++;
				flg++;
			}
		if (flg == 0)
			return (found);
	}
	return (0);
}

/**
 * _strcspn - Get length of a prefix substring
 * @s: String to evaluate
 * @reject: Set of characters for comparism
 *
 * Return: The numbers of bytes in the initial segment of s
 * which are not in the string reject.
 */
size_t _strcspn(char *s, const char *reject)
{
	size_t i = 0;

	while (s[i])
	{
		if (_strchr(reject, s[i]) != NULL)
			break;
		i++;
	}

	return (i);
}

/**
 * _strchr - locates character c in string s
 * @s: string to search
 * @c: The character to search for
 *
 * Return: pointer to the first occurrence of character c in str,
 * or NULL if character not found.
 */
char *_strchr(const char *s, char c)
{
	int i;

	while (true)
	{
		i = *s++;
		if (i == c)
			return ((char *)s - 1);
		if (i == 0)
			return (NULL);
	}
}

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
