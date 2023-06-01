/**
 * calculate_pad_size - calculates pad sizes
 * @format: the substring
 * @i: the index
 * @size: the size of the substring format
 * @pad_size: the size of pad before decimal
 * @decimal_pad_size: the size of the pad after decimal
 */
void calculate_pad_size(const char *format, int *i, int size, int *pad_size,
		int *decimal_pad_size)
{
	int d = 0;
	int *has_decimal = &d;
	char c;

	while (*i < size)
	{
		c = *(format + *i);
		if (c == '.' && *has_decimal == 0)
		{
			*has_decimal = 1;
		}
		else if (c >= 48 && c < 48 + 10 && *has_decimal == 0)
		{
			*pad_size += (*pad_size * 10) + (c  - '0');
		}
		else if (c >= 48 && c < 48 + 10 && *has_decimal == 1)
		{
			*decimal_pad_size += (*decimal_pad_size * 10) + (c - '0');
		}
		else
		{
			exit(EXIT_FAILURE);
		}
		*i += 1;
	}
}
