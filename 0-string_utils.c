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
 * word_count - Counts the number of words in the string
 * @str: String to compute
 * @delim: Delimiters for tokenization
 *
 * Return: Number of words in str.
 */
size_t word_count(char *str, const char *delim)
{
	size_t count = 0;
	char *tmp = _strdup(str);

	if (tmp == NULL)
		return (-1);

	if (strtok(tmp, delim) != NULL)
		count++;

	while (strtok(NULL, delim))
		count++;
	free(tmp);

	return (count);
}

/**
 * _strcat - concatenates two strings
 * @dest: Where to append string
 * @src: String to append
 *
 * Return: Pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	size_t i, len = _strlen(dest);

	for (i = 0; src[i]; i++, len++)
		dest[len] = src[i];
	dest[len] = '\0';

	return (dest);
}
