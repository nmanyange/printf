#include "main.h"

/**
 * _printf - prints to stdout
 * @format: format specifier
 * Return: number of bytes
 */
int _printf(const char *format, ...)
{
	unsigned int i, s_count, count = 0;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_puttchar(format[i]);
		}
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			_puttchar(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			s_count = putss(va_arg(args, char *));
			i++;
			count += (s_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			_puttchar('%');
		}
		count += 1;
	}
	va_end(args);

	return (count);
}
