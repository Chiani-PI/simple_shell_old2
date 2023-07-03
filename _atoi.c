#include "shell.h"

/**
 * interactive - The func shld return true if shell is in intrctv mod
 * @info: The address of the struct
 *
 * Return: 1 if synergic, else 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - function evaluates whether a char is a separator
 * @c: the inputted character to be evaluated
 * @delim: separator string
 * Return: 1 if true, else 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - function evaluates whether a char is an alphabet
 * @c: the inputted character to be evaluated
 * Return: 1 if c is an alphabet, else 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Function changes a string to an integer
 * @s: String to be changed
 * Return: 0 if there are nums within string, else changed number
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
