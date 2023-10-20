#include "main.h"

/**
 * get_precision - precision string
 * @s: string
 * @params: parameters
 * @xy: pointer
 * Return: new pointer
 */
char *get_precision(char *s, params_t *params, va_list xy)
{
	int i = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		i = va_arg(xy, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			i = 1 * 10 + (*s++ - '0');
	}
	params->precision = i;
	return (s);
}
