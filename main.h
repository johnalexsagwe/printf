#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>


/**
 * struct format - a structure to match the conversion specifiers for printf
 * @f: the pointer to the function that handles the conversion specifier
 * @id: the character pointer to the conversion specifier eg 1 or h d,i,u,o,x or X
 *
 * /
 
 typedef struct fmt fmt_t;

 int _printf(const char *format, ...);
 va_list list, char buffer[], int flags, int width, int precision, int size);

/*  Number printing */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size;

int print_binary(va_list types, char buffer [],
	int flags, int width, int precision, int size);

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int size, int precision);

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size;

int print_hexa(va_list types, char map_to[],
	char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Character and Strings Printing */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_char(va_list types, char buffer[],
       	int flags, int width, int precision, int size);

/* Special Characters, symbols and address */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Specifier Handling */

int get_flags(const char *format, int *i);

int get_width(const char *format, int *i, va_list list);

int get_size(const char *format, int *i);

int get_precision(const char *format, int *i, va_list list);

/* Other Functions */

int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);

int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);

int handle_write_char(char c, char buffer[],
	int flags int width, int precision, int size);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/* Auxiliary Operations */

int is_printable(char);

int append_hexa_code(char, char[], int);

int is_digit(char);

long int convert_size_number(long int num, int size);

long int convert_size _unsgnd(unsigned long int num, int size);

#endif /* PRINTF_PROTOTYPES_H */

