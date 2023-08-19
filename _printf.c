#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: Format String
 * Return: Number of printed chars
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0, buff_ind = 0;
	int flags, width, precision, size;
	va_list list;
	char buffer[BUFF_SIZE];

	if (!format)
		return (-1);

	va_start(list, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = ,size);
			i++;
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list):

		return(printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add the next char, represents length
 */
void print_buffer(char bufffer[], int *buff_ind
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
