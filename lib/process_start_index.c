/**
 * process_start_index - function to compute numbers in pad
 * @format: the substring
 * @i: the index
 * @reverse_padding: reference to reverse_padding
 * @include_sign: reference to include_sign
 * @zero_padding: reference to zero_padding
 * @space_padding: reference to space_padding
 *
 */
void process_start_index(const char *format, int *i, int *reverse_padding,
	int *include_sign, int *zero_padding, int *space_padding)
{
	if (*(format + *i) == '+' && *(format + *i + 1) != '-')
	{
		*include_sign = 1;
		*i += 1;
	}

	if (*(format + *i) == '-' && *(format + *i + 1) != '+')
	{
		*reverse_padding = 1;
		*i += 1;
	}

	if (
		(*(format + *i) == '+' && *(format + *i + 1) != '-') ||
		(*(format + *i) == '-' && *(format + *i + 1) != '+'))
	{
		*reverse_padding = 1;
		i += 1;
	}

	if (
		(*(format + *i) == '+' && *(format + *i + 1) == '-') ||
		(*(format + *i) == '-' && *(format + *i + 1) == '+'))
	{
		*reverse_padding = 1;
		*include_sign = 1;
		*i += 2;
	}

	if (*(format + *i) == '0')
	{
		*zero_padding = 1;
		*i += 1;
	}

	if (*(format + *i) == ' ')
	{
		*space_padding = 1;
		*i += 1;
	}
}
