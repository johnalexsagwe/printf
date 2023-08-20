#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints the output of characters
 * @formar: is a character string
 * by Alex and Nelson
 * Return: The printed characters
 */
int _printf(const char *format, ...)
{
	int charCount = 0;
	char c;
	const char *s;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			charCount++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 's':
					s = va_arg(args, const char *);
					while (*s)
					{
						putchar(*s);
						s++;
						charCount++;
					}
					break;
				case 'c':
					c = (char)va_arg(args, int);
					putchar(c);
					charCount++;
					break;
				case '%':
					putchar('%');
					charCount++;
					break;
				default:
					break;
			}
		}
		formart++;
	}
	va_end(args);
	return (charCount);
}
