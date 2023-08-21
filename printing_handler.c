#include "main.h"

/**
 *handle_print - Processes and prints arguments based on the format specifier.
 * @fmt: The formatted string containing the format specifiers.
 * @ind: Pointer to the current index in the format string.
 * @list: The argument list.
 * @buffer: Buffer array used for printing.
 * @flags: Flags indicating formatting options.
 * @width: Width specification for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 *
 * Return: Number of characters printed on success, -1 on error.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;

	// Format specifiers and corresponding functions
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	// Check for matching format specifier and call the respective print function
	for (i = 0; fmt_types[i].fmt != '\0'; i++) {
		if (fmt[*ind] == fmt_types[i].fmt) {
			return fmt_types[i].fn(list, buffer, flags, width, precision, size);
		}
	}

	// Handle unknown format specifier
	if (fmt_types[i].fmt == '\0') {
		if (fmt[*ind] == '\0') {
			return -1; // Error: Reached the end of format string unexpectedly
		}
		
		// Print '%' if not part of a valid format specifier
		unknown_len += write(1, "%", 1);
		
		// Handle space flag and width specifier
		if (fmt[*ind - 1] == ' ') {
			unknown_len += write(1, " ", 1);
		} else if (width) {
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%') {
				--(*ind);
			}
			if (fmt[*ind] == ' ') {
				--(*ind);
			}
			return 1; // Return 1 to indicate successful handling of width specifier
		}

		// Print the unknown character
		unknown_len += write(1, &fmt[*ind], 1);
		return unknown_len;
	}

	return printed_chars;
}
