#include "main.h"
#include <stdarg.h>

/**
 * get_width - finds the width for printing
 * @format: format for printing arguments
 * @i: list of arguments to print
 * @list: list
 *
 * Return: width
 */
int get_width(const char *format, int *i, va_list list)
{
	int p;
	int width = 0;

	for (p = *i + 1; format[p] != '\0'; p++)
	{
		if (is_digit(format[p]))
		{
			width *= 10;
			width += format[p] - '0';
		}
		else if (format[p] == '*')
		{
			p++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = p - 1;
	return (width);
}
