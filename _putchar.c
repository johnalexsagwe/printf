#include "main.h"

/**
 * _putchar - writes the character to stdout
 * @c: Output character
 *
 * Return: on sucess 1.
 * on error, -1 is returned, and error is set appropriately.
 * /
int _putchar(char c)
{
	return (write(1, &c, 1));
}
 
