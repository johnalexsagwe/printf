/**
 * print_string - Prints a string
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * Width: Width
 * @precision: Precision Specification
 * @size: Size Specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
		int flags, width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED (Size);

	char *str = va_arg(types, char *);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "	";
	}

	int length = 0;
	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < lenght)
		length = precision;

	if (width > length)
	{
		int i;
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return width;
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return width;
		}
	}
	return write(1, str, length);
}
