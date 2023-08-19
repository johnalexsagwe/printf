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
	int flags, int width, int 
