#include "main.h"
#include <stdarg.h>

/**
 * get_precision - Determines the printing precision
 * @format: format
 * @i: List of arguments to print
 * @List: list of arguments
 *
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int r = *i + 1;
	int precision = -1;

	if (format[r] != '.')
		return (precision);
	precision = 0;
	for (r += 1; format[r] != '\0'; r++)
	{
		if (is_digit(format[r]))
		{
			precision *= 10;
			precision += format[r] - '0';
		}
		else if (format[r] == '*')
		{
			r++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = r - 1;
	return (precision);
}
