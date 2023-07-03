#include "shell.h"

/**
 * _eputs - Func to print a string inputted
 * @str: String for printng
 *
 * Return: Nada
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Func to write d char d to standarderr
 * @c: Char for printng
 *
 * Return: 1(success), else -1 and d errno is appropriatly set
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - Func to write d char d to d given file_descriptr
 * @c: Char for printng
 * @fd: File-descriptr to be written to
 *
 * Return: 1 (success), else -1 and the errno is appropriatly set
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Func to print a string inputted to a givn fd
 * @str: String for printng
 * @fd: File-descriptr to be written to
 *
 * Return: D Tnum of characterss printed to fd
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
