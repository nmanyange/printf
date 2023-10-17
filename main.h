#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct format
{
	char *id;
	int (*f)();
} match;
int _printf(const char *format, ...);
int _puttchar(char c);
int print_char(va_list val);
int print_string(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int print_int(va_list args);
int print_dec(va_list args);
int print_37(void);

#endif
