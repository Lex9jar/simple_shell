#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @str: String to compute
 *
 * Return: Number derived
 */
int _atoi(char *str)
{
	int i, len, num, digit, flg, opr;

	i = 0, len = 0, opr = 0, num = 0, digit = 0, flg = 0;

	while (str[len])
		len++;

	while (i < len && flg == 0)
	{
		if (str[i] == '-')
			++opr;

		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			if (opr % 2)
				digit = -digit;
			num = num * 10 + digit;
			flg = 1;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break;
			flg = 0;
		}
		i++;
	}
	if (flg == 0)
		return (0);

	return (num);
}
