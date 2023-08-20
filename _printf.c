#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints characters
 * @format: is the format.
 * Return: charCount.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int charCount = 0;

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
			if (*format == ' ')
				return (-1);
			if (*format == 'c')
				handle_char(args, &charCount);
			else if (*format == 's')
				handle_string(args, &charCount);
			else if (*format == '%')
				handle_percent(&charCount);
			else
				handle_unknown(*format, &charCount);
		}
		else
		{
				write(1, format, 1);
				charCount++;
		}
		format++;
	}
	va_end(args);
	return (charCount);
}
