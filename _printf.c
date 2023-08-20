#include "main.h"
#include <stdarg.h>
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - prints characters
 * @format: is the format.
 * Return: charCount.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int p, printed = 0, charCount = 0;
	int flags, width, precision, size, buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (p = 0; format && format[p] != '\0'; p++)
	{
		if (format[p] != '%')
		{
			buffer[buff_ind++] = format[p];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/** write(1, &format[p], 1);*/
			charCount++;
		}
	else
	{
		print_buffer(buffer, &buff_ind);
		flags = get_flags(format, &p);
		width = get_width(format, &p, args);
		precision = get_precision(format, &p, args);
		size = get_size(format, &p);
		++p;
		printed = handle_print(format, &p, args, buffer,
				flags, width, precision, size);
		if (printed == -1)
			return (-1);
		charCount += printed;
	}
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);
	return (charCount);
}
