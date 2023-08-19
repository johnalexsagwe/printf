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
 
 typedef struct {
 	char *id;
	int (*f)();
	convert_match;
}

/****************** Number printing *****************/

int print_int(va_list args, char buffer[],
		int flags, int width, int precision, int size;

int print_binary(va_list args, char buffer [],
	int flags, int width, int precision, int size);

int print_unsigned(va_lists args, char buffer[]
	int flags, int width, int size, int precision);

int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_octal(va_list args, char buffer[]
	int flags, int width, int precision, int size;

int print_hexa(va_list args, char map_to[],
	char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_hexa_upper(va list args, char buffer[]
	int flags, int width, int precision, int size);

/****************** Character and Strings Printing  *****************/

int print_char(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_char(va_list args, char buffer[],
       	int flags, int width, int precision, int size);

/***************** Special Characters, symbols and adress ****************/

int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_pointer(va_list args,char buffer[],
	int flags, int width, int precision, int size);

/***************** Specifier Handling  ****************/

int get_flags(const char *format, int *index);

int get_width(const char *format, int *index, va_list args);

int get_size(const char *forrmat, int *index);

int get_precision(const char *format, int *index, va_list args);

/**************** Other Functions *****************/

int write_number(int is_positive, int index, char buffer[]
	int flags, int width, int precision, int size);

int write_num(int index, char bff[], int flags, int width, int precision,
	int length, char padding, char extra_char, int padd_start);

int handle_write_char(char c, char buffer[]
	int flags int width, int precision, int size);

int write_unsgnd(int is_negative, int index,
	char buffer[], int flags, int width, int precision, int size);

/**************** Auxiliary Operations ****************/

int is_printable(char);

int append_hexa_code(char, char[], int);

int is_digit(char);

long int convert_size_number(long int num, int size);

long int convert_size _unsgnd(unsigned long int num, int size);

#endif /* PRINTF_PROTOTYPES_H */

