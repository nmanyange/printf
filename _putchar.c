#include "main.h"

/**
 * _puts - prints a string
 * @str: string to printed
 * Return: (str - a)
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the character c to standard output
 * @c: character to be printed
 * Return: on success 1
 * on error, -1 is returned
 */
int _putchar(int c)
{
	static int r;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || r >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, r);
		r = 0;
	}
	if (c != BUF_FLUSH)
		buf[r++] = c;
	return (1);
}
