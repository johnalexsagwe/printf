#include "main.h"

/**
 * get_size - finds the size to cast the argument.
 * @format: formatted string to cast the argument.
 * @i: arguments to be casted.
 *
 * Return: precision.
 */
int get_size(const char *format, int *i)
{
	int currentIndex = *i + 1;
	int size = 0;

	if (format[currentIndex] == '1')
		size = S_LONG;
	else if (format[currentIndex] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = currentIndex - 1;
	else
		*i = currentIndex;
	return (size);
}
