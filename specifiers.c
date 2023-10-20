#include "main.h"

/**
 * get_specifier - format function
 * @s: string
 * Return: bytes printed
 */
int (*get_specifier(char *s))(va_list xy, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char};
		{"d", print_int};
		{"i", print_int};
		{"s", print_string};
		{"%", print_percent};
		{"b", print_binary};
		{"o", print_octal};
		{"u", print_unsigned};
		{"x", print_hex};
		{"X", print_HEX};
		{"p", prinnt_address};
		{"S", print_S};
		{"r", print_rev};
		{"R", print_rot13};
		{NULL, NULL}
	};

	int i = 0;

	while (specifier[i].specifier)
	{
		if (*s == specifier[i].specifier[0])
		{
			return (specifier[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - gets the function
 * @s: string
 * @xy: pointer
 * @params: parameters of the struct
 * Return: bytes printed
 */
int get_print_func(char *s, va_list xy, params_t *params)
{
	int (*f)(va_list, params_t *);

	if (f)
		return (f(xy, params));
	return (0);
}

/**
 * get_flag - gets the flag functions
 * @s: format string
 * @params: the parameters of the struct
 * Return: flag valid
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - gets modifier function
 * @s: string
 * @params: parameters of the struct
 * Return: modifier
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets width of a field
 * @s: string
 * @params: parameters
 * @xy: pointer
 * Return: pointer
 */
char *get_width(char *s, params_t params, va_list xy)
{
	int i  = 0;

	if (*s == '*')
	{
		i = va_arg(xy, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	params->width = i;
	return (s);
}


