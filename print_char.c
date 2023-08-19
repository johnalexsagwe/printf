#include "main.h"

/**
 * print_char - Prints a character
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: Width
 * @precision: Precision Specification
 * @size: Size specifier
 * Return: NUmber of chars printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, size)
{
	char c = va_arg(types, int);
	return handle_write_char(c, buffer, flags, width, precision, size);
}
