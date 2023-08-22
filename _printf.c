#include "main.h"
#include <stdio.h>
#include <stdarg.h>

void handle_char(va_list args, int *count)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	(*count)++;
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				handle_char(args, &count);
			else if (*format == '%')
				handle_percent(&count);
			else
				handle_unknown(*format, &count);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
