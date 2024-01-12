#include "shell.h"

/**
 * _strtok - Extract tokens from strings
 * @str: String to tokenize
 * @delim: Delimiters for tokenization
 *
 * Return: Pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *next_token = NULL;
	char *token;

	if (str != NULL)
		next_token = str;
	else if (next_token == NULL)
		return (NULL);

	next_token += _strspn(next_token, delim);
	if (*next_token == '\0')
	{
		next_token = NULL;
		return (NULL);
	}

	token = next_token;
	next_token += _strcspn(next_token, delim);
	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}
	else
		next_token = NULL;

	return (token);
}
