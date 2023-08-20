#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints characters
 * @format: is the format.
 * Return: printed characters
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
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				charCount++;
			}
			else if (*format == 's')
				s = va_arg(args, char *);
				while (*s)
				{
					wite(1, s, 1);
					s++;
					charCount++;
				}
				else if (*format == '%')
					write(1, format, 1);
				charCount++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				charCount += 2;
			}
			else
			{
				write(1, format, 1);
				charCount++;
			}
			va_end(args);
			return (charCount);
}
