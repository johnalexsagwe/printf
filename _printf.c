#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * handle_char - Handles the %c conversion specifier
 * @args: The va_list containing the argument
 * @count: A pointer to the count of printed characters
 */
void handle_char(va_list args, int *count)
{
        char c = (char)va_arg(args, int);

        write(1, &c, 1);
        (*count)++;
}

/**
 * handle_reverse_string - Handles the %r conversion specifier
 * @args: The va_list containing the argument (a string)
 * @count: A pointer to the count of printed characters
 */
void handle_reverse_string(va_list args, int *count)
{
        const char *str = va_arg(args, const char *);
        int length = strlen(str);
        int i;

        for (i = length - 1; i >= 0; i--)
        {
                write(1, &str[i], 1);
                (*count)++;
        }
}

/**
 * _handle_unknown - Handles an unknown conversion specifier
 * @specifier: The unknown specifier
 * @count: A pointer to the count of printed characters
 */
void _handle_unknown(char specifier, int *count)
{
        write(1, "%", 1);
        write(1, &specifier, 1);
        (*count) += 2;
}

/**
 * _handle_percent - Handles the %% conversion specifier
 * @count: A pointer to the count of printed characters
 */
void _handle_percent(int *count)
{
        write(1, "%", 1);
        (*count)++;
}

/**
 * _handle_custom - Handles the custom conversion specifier %r
 * @format: The format string
 * @args: The va_list containing the argument
 * @count: A pointer to the count of printed characters
 */
void _handle_custom(const char *format, va_list args, int *count)
{
        format++;
        if (*format != '\0' && *format == 's')
                handle_reverse_string(args, count);
        else
                _handle_unknown('r', count);
}

/**
 * _printf - Custom printf function with additional conversion specifier
 * @format: The format string with optional conversion specifiers
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
        int count = 0;
        va_list args;

        if (format == NULL)
                return (-1);

        va_start(args, format);

        while (*format)
        {
                if (*format == '%')
                {
                        format++;

                        if (*format == '\0')
                                break;

                        if (*format == 'c')
                                handle_char(args, &count);
                        else if (*format == '%')
                                _handle_percent(&count);
                        else if (*format == 'r')
                                _handle_custom(format, args, &count);
                        else
                                _handle_unknown(*format, &count);
                }
                else
                {
                        write(1, format, 1);
                        count++;
                }
                format++;
        }

        va_end(args);
        return (count);
}
