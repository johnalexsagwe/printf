#include "main.h"

/**
 * parse_format - Parse and process format string.
 * @format: Format string.
 * @args: Variable arguments.
 *
 * Return: Number of characters printed.
 */
int parse_format(const char *format, va_list args)
{
    int i = 0, printed_chars = 0;

    while (format && format[i])
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            printed_chars++;
        }
        else
        {
            i++;
            if (format[i] == '\0')
                return (-1);
            printed_chars += process_format(format[i], args);
        }
        i++;
    }

    return printed_chars;
}

/**
 * process_format - Process format specifier.
 * @specifier: The format specifier.
 * @args: Variable arguments.
 *
 * Return: Number of characters printed.
 */
int process_format(char specifier, va_list args)
{
    int printed_chars = 0;

    switch (specifier)
    {
        case 'c':
            printed_chars += print_char(va_arg(args, int));
            break;
        case 's':
            printed_chars += print_string(va_arg(args, char *));
            break;
        case '%':
            _putchar('%');
            printed_chars++;
            break;
        case 'd':
        case 'i':
            printed_chars += print_int(va_arg(args, int));
            break;
        // Add more cases for other conversion specifiers
        default:
            _putchar('%');
            _putchar(specifier);
            printed_chars += 2;
            break;
    }

    return printed_chars;
}
