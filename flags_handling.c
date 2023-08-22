/**
 * get_flags_and_update - Takes active formatting flags, updates struct flags
 * @format: The formatted string containing the flags
 * @i: Pointer to the current position in the format string
 * @f: Pointer to the struct flags in which we turn the flags on
 * Return: Calculated flags
 */
int get_flags_and_update(const char *format, int *i, flags_t *f)
{
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				get_flag(format[curr_i], f);
				break;
			}
		}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
