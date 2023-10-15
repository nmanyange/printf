#include "main.h"

/**
 * _puttchar - prints a character
 * @c: char input
 * Return: 1
 */
int _puttchar(char c)
{
	return (write(1, &c, 1));
}
