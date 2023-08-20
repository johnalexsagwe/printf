#include "main.h"
#include <stdarg.h>

/**
 * _printf - printf function
 * @format: is the format.
 * Return: charCount.
 */
int _printf(const char *format, ...)
{
	int charCount = 0;
	char c;
	char *str;
	va_list args;

	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				c = (char)va_arg(args, int);
				putchar(c);
				charCount++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				while (*str)
				{
					putchar(*str);
					str++;
					charCount++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				charCount++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				charCount += 2;
			}
		}
		else
		{
			putchar(*format);
			charCount++;
		}
		format++;
	}
	va_end(args);
	return (charCount);
}
