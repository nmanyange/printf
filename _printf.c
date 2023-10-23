#include "main.h"

/**
 * _printf - mimics printf function
 * @format: The format string
 * @...: variable arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            count++;
        }
        else
        {
            format++;

            if (*format == '\0')
                return (-1);

            if (*format == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                int n = va_arg(args, int);
                char buffer[12];
                int len = sprintf(buffer, "%d", n);
                write(1, buffer, len);
                count += len;
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                count++;
            }
        }
        format++;
    }

    va_end(args);
    return (count);
}
