#include "shell.h"

/**
 * _strlen - Calculates the number of characters in a string
 * @str: String to compute
 *
 * Return: Number of characters in str.
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * _strcpy - copies a string from 'src' to 'dest'
 * @dest: destination
 * @src: string to copy to destination
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = _strlen(src);

	for (i = 0; i < len; i++)
	dest[i] = src[i];

	dest[i++] = '\0';
	return (dest);
}

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: String to duplicate
 *
 * Return: Pointer to duplicated string, or NULL if failed.
 */
char *_strdup(char *str)
{
	int len;
	char *new_str;

	if (str == NULL)
	{
		errno = EINVAL;
		perror("Error");
	return (NULL);
	}

	len = _strlen(str);

	new_str = malloc(len + 1);
	if (new_str == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	_strcpy(new_str, str);

	return (new_str);
}

/**
 * _strcmp - compares two string
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0 if s1 and s2 are equal or positive number if s1 > s2,
 * or negative number if s1 < s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strncpy - copies a string
 * @dest: string to overwrite
 * @src: string to copy
 * @n: number of characters to copy
 *
 * Return: pointer to the destination string dest
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
